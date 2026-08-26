import QtQuick
import Quickshell
import Quickshell.Widgets
import Qt5Compat.GraphicalEffects

Item {
    id: root
    
    property bool colorize: false
    property color color
    property string source: ""
    property string iconFolder: "file://" + Quickshell.shellPath("assets/icons")  // The folder to check first
    width: 30
    height: 30
    
    IconImage {
        id: iconImage
        anchors.fill: parent
        source: {
            if (!root.source) return "";
            const hasExtension = root.source.indexOf(".") !== -1;
            const fileName = hasExtension ? root.source : root.source + ".svg";
            const fullPathWhenSourceIsIconName = iconFolder + "/" + fileName;
            if (iconFolder && fullPathWhenSourceIsIconName) {
                return fullPathWhenSourceIsIconName
            }
            return root.source
        }
        implicitSize: root.height
    }

    Loader {
        active: root.colorize
        anchors.fill: iconImage
        sourceComponent: ColorOverlay {
            source: iconImage
            color: root.color
        }
    }
}
