import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import SleexUiKit.Appearance

ColumnLayout {
    id: root
    property string title
    property string icon
    property color backgroundColor: Appearance.colors.colLayer1
    default property alias data: sectionContent.data

    Layout.fillWidth: true
    spacing: 8
    
    RowLayout {
        Layout.leftMargin: 12
        Layout.rightMargin: 12
        spacing: 5
        visible: root.title !== "" || root.icon !== ""

        MaterialSymbol {
            text: root.icon
            iconSize: 20
            color: Appearance.colors.colOnLayer1
            visible: text !== ""
        }
        StyledText {
            text: root.title
            font.pixelSize: Appearance.font.pixelSize.larger
            font.weight: Font.Medium
            visible: text !== ""
        }
    }

    Item {
        Layout.fillWidth: true
        implicitHeight: sectionContent.implicitHeight + 24

        Repeater {
            model: sectionContent.visibleChildren.length
            Rectangle {
                property Item targetItem: sectionContent.visibleChildren[index]
                property int padY: 12
                
                x: 0
                width: parent.width
                y: targetItem ? (targetItem.y + sectionContent.y - padY) : 0
                height: targetItem ? (targetItem.height + padY * 2) : 0
                
                color: root.backgroundColor
                
                property bool isFirst: index === 0
                property bool isLast: index === sectionContent.visibleChildren.length - 1
                
                topLeftRadius: isFirst ? Appearance.rounding.large : Appearance.rounding.unsharpenmore
                topRightRadius: isFirst ? Appearance.rounding.large : Appearance.rounding.unsharpenmore
                bottomLeftRadius: isLast ? Appearance.rounding.large : Appearance.rounding.unsharpenmore
                bottomRightRadius: isLast ? Appearance.rounding.large : Appearance.rounding.unsharpenmore
            }
        }

        ColumnLayout {
            id: sectionContent
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.leftMargin: 12
            anchors.rightMargin: 12
            anchors.topMargin: 12
            spacing: 26 // (12 + 12 + 2) padding y + 2px gap
        }
    }
}