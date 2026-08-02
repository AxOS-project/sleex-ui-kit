import QtQuick
import SleexUiKit.Appearance

StyledText {
    text: "Dialog Title"
    color: Appearance.colors.colOnSurface
    wrapMode: Text.Wrap
    font {
        pixelSize: Appearance.font.pixelSize.title
        family: Appearance.font.family.title
    }
}