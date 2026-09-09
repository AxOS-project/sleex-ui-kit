import QtQuick
import SleexUiKit.Appearance

Image {
    asynchronous: true
    retainWhileLoading: true
    visible: opacity > 0
    opacity: (status === Image.Ready) ? 1 : 0
    Behavior on opacity {
        animation: NumberAnimation {
    duration: Appearance.animation.elementMoveEnter.duration
    easing.type: Appearance.animation.elementMoveEnter.type
    easing.bezierCurve: Appearance.animation.elementMoveEnter.bezierCurve
}
    }
}