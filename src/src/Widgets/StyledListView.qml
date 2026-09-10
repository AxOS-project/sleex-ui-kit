import SleexUiKit.Appearance
import QtQuick
import QtQuick.Controls

/**
 * A ListView with animations.
 */
ListView {
    id: root
    spacing: 5
    property real removeOvershoot: 20 // Account for gaps and bouncy animations
    property int dragIndex: -1
    property real dragDistance: 0
    property bool popin: true
    property bool animateAppearance: true
    property bool animateMovement: false


    function resetDrag() {
        root.dragIndex = -1
        root.dragDistance = 0
    }

    maximumFlickVelocity: 3500
    boundsBehavior: Flickable.DragOverBounds
    ScrollBar.vertical: StyledScrollBar {}

    
    add: Transition {
        enabled: animateAppearance
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    properties: popin ? "opacity,scale" : "opacity"
                from: 0
                to: 1
}
    }

    addDisplaced: Transition {
        enabled: animateAppearance
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "y"
}
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    properties: popin ? "opacity,scale" : "opacity"
                to: 1
}
    }
    
    displaced: Transition {
        enabled: root.animateMovement
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "y"
}
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    properties: "opacity,scale"
                to: 1
}
    } 

    move: Transition {
        enabled: root.animateMovement
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "y"
}
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    properties: "opacity,scale"
                to: 1
}
    }
    moveDisplaced: Transition {
        enabled: root.animateMovement
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "y"
}
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    properties: "opacity,scale"
                to: 1
}
    }

    remove: Transition {
        enabled: animateAppearance
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "x"
                to: root.width + root.removeOvershoot
}
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "opacity"
                to: 0
}
    }

    // This is movement when something is removed, not removing animation!
    removeDisplaced: Transition { 
        enabled: animateAppearance
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    property: "y"
}
            NumberAnimation {
    duration: Appearance.animation.elementMove.duration
    easing.type: Appearance.animation.elementMove.type
    easing.bezierCurve: Appearance.animation.elementMove.bezierCurve
    properties: "opacity,scale"
                to: 1
}
    }
}
