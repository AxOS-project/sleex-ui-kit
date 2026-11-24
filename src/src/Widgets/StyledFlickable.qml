import QtQuick
import SleexUiKit.Appearance

Flickable {
    id: root
    maximumFlickVelocity: 3500
    boundsBehavior: Flickable.DragOverBounds

    property real touchpadScrollFactor: typeof Config !== "undefined" ? (Config?.options?.interactions?.scrolling?.touchpadScrollFactor ?? 1.8) : 1.8
    property real mouseScrollFactor: typeof Config !== "undefined" ? (Config?.options?.interactions?.scrolling?.mouseScrollFactor ?? 90) : 90
    property real mouseScrollDeltaThreshold: typeof Config !== "undefined" ? (Config?.options?.interactions?.scrolling?.mouseScrollDeltaThreshold ?? 120) : 120
    property bool fasterTouchpadScroll: typeof Config !== "undefined" ? (Config?.options?.interactions?.scrolling?.fasterTouchpadScroll ?? true) : true

    // Accumulated scroll destination so wheel deltas stack while animating
    property real scrollTargetY: 0

    // N'active l'animation lissée que pendant le wheel/touchpad, pas pendant un drag/flick manuel
    property bool smoothWheelActive: false

    NumberAnimation {
        id: scrollAnim
        target: root
        property: "contentY"
        to: root.scrollTargetY
        duration: Appearance.animation.scroll.duration
        easing.type: Appearance.animation.scroll.type
        easing.bezierCurve: Appearance.animation.scroll.bezierCurve
        onStopped: root.smoothWheelActive = false
    }

    WheelHandler {
        id: wheelHandler
        acceptedDevices: PointerDevice.Mouse | PointerDevice.TouchPad
        onWheel: function(event) {
            const maxY = Math.max(0, root.contentHeight - root.height);
            if (maxY <= 0)
                return;

            const base = scrollAnim.running ? root.scrollTargetY : root.contentY;
            let stepPx = 0;

            // 1. Touchpad avec pixelDelta disponible (le cas le plus courant sur Wayland)
            if (event.pixelDelta.y !== 0) {
                const factor = root.fasterTouchpadScroll ? root.touchpadScrollFactor : 1.0;
                stepPx = event.pixelDelta.y * factor;
            } else {
                // 2. Fallback sur angleDelta (molette souris ou touchpad sans pixelDelta)
                const isMouseWheel = Math.abs(event.angleDelta.y) >= root.mouseScrollDeltaThreshold;
                if (isMouseWheel) {
                    const notches = event.angleDelta.y / root.mouseScrollDeltaThreshold;
                    stepPx = notches * root.mouseScrollFactor;
                } else {
                    const factor = root.fasterTouchpadScroll ? (root.touchpadScrollFactor / 60.0) : (1.0 / 60.0);
                    stepPx = event.angleDelta.y * factor;
                }
            }

            const nextTargetY = Math.max(0, Math.min(base - stepPx, maxY));
            root.scrollTargetY = nextTargetY;
            root.smoothWheelActive = true;
            scrollAnim.restart();
            event.accepted = true;
        }
    }

    // Keep target synced when not animating via wheel (e.g., drag/flick or programmatic changes)
    onContentYChanged: {
        if (!root.smoothWheelActive && !scrollAnim.running) {
            root.scrollTargetY = root.contentY;
        }
    }
}