// WidgetShowcase.qml
//
// Exercises every component in SleexUiKit.Widgets (sleex-ui-kit).
// Run with: qml6 WidgetShowcase.qml   (make sure SleexUiKit.* modules are on QML2_IMPORT_PATH)
//
// Notes:
//  - AudioDeviceSelectorButton / VolumeMixer need Quickshell.Services.Pipewire running with real nodes.
//  - CliphistImage needs a real cliphist entry string + a live `cliphist decode` pipe.
//  - TimePicker imports `qs` (the shell's own DateTime singleton) — it won't resolve outside
//    an actual Sleex/Quickshell shell tree unless you provide a stub `qs` module.
//  - Everything else works standalone.

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Quickshell.Services.Pipewire
import SleexUiKit.Appearance
import SleexUiKit.Functions
import SleexUiKit.Widgets as Widgets

ApplicationWindow {
    id: window
    visible: true
    width: 1200
    height: 900
    title: "Sleex UI Kit — Widget Showcase"
    color: Appearance.colors.colLayer0 ?? "#141318"

    Widgets.StyledScrollBar {
        id: vbar
    }

    ScrollView {
        anchors.fill: parent
        anchors.margins: 12
        ScrollBar.vertical: vbar

        Widgets.ContentPage {
            id: page
            width: window.width - 24

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Buttons"
                icon: "smart_button"

                Widgets.ContentSubsection {
                    title: "RippleButton / RippleButtonWithIcon / DialogButton"
                    RowLayout {
                        spacing: 10
                        Widgets.RippleButton {
                            buttonText: "Ripple"
                            implicitHeight: 36
                            horizontalPadding: 16
                            contentItem: Widgets.StyledText { text: "Ripple"; anchors.centerIn: parent }
                        }
                        Widgets.RippleButton {
                            toggled: true
                            implicitHeight: 36
                            horizontalPadding: 16
                            contentItem: Widgets.StyledText { text: "Toggled"; anchors.centerIn: parent }
                        }
                        Widgets.RippleButtonWithIcon {
                            materialIcon: "star"
                            mainText: "With icon"
                        }
                        Widgets.DialogButton {
                            buttonText: "OK"
                        }
                        Widgets.MenuButton {
                            buttonText: "Menu item"
                        }
                        Widgets.FloatingActionButton {
                            iconText: "add"
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "GroupButton family"
                    Widgets.ButtonGroup {
                        Widgets.GroupButton { buttonText: "One" }
                        Widgets.GroupButton { buttonText: "Two"; toggled: true }
                        Widgets.SelectionGroupButton { buttonText: "Left"; leftmost: true }
                        Widgets.SelectionGroupButton { buttonText: "Right"; rightmost: true }
                    }
                    Widgets.VerticalButtonGroup {
                        Widgets.GroupButton { buttonText: "Stacked A" }
                        Widgets.GroupButton { buttonText: "Stacked B" }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Text & Labels"
                icon: "text_fields"

                Widgets.ContentSubsection {
                    title: "StyledText / StyledLabel / ScrollingText / KeyboardKey"
                    ColumnLayout {
                        spacing: 8
                        Widgets.StyledText { text: "StyledText sample"; animateChange: true }
                        Widgets.StyledLabel { text: "StyledLabel sample" }
                        Widgets.ScrollingText {
                            width: 160
                            text: "A long scrolling text label that overflows its container"
                        }
                        RowLayout {
                            spacing: 6
                            Widgets.KeyboardKey { key: "Ctrl" }
                            Widgets.KeyboardKey { key: "Shift" }
                            Widgets.KeyboardKey { key: "A" }
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "ContentSubsectionLabel / WindowDialog text pieces"
                    ColumnLayout {
                        spacing: 4
                        Widgets.ContentSubsectionLabel { text: "A subsection label" }
                        Widgets.WindowDialogTitle { text: "Dialog title sample" }
                        Widgets.WindowDialogSectionHeader { text: "Section header sample" }
                        Widgets.WindowDialogParagraph { text: "Body paragraph sample text." }
                        Widgets.WindowDialogSeparator { Layout.fillWidth: true; Layout.preferredWidth: 200 }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Inputs"
                icon: "input"

                Widgets.ContentSubsection {
                    title: "Text fields"
                    ColumnLayout {
                        spacing: 8
                        Widgets.MaterialTextField {
                            placeholderText: "MaterialTextField"
                        }
                        Rectangle {
                            color: Appearance.colors.colLayer2 ?? "#2a2a30"
                            radius: 6
                            implicitWidth: 220
                            implicitHeight: textInput.implicitHeight + 12
                            Widgets.StyledTextInput {
                                id: textInput
                                anchors.fill: parent
                                anchors.margins: 6
                                text: "StyledTextInput"
                            }
                        }
                        Rectangle {
                            color: Appearance.colors.colLayer2 ?? "#2a2a30"
                            radius: 6
                            implicitWidth: 220
                            implicitHeight: 60
                            Widgets.StyledTextArea {
                                anchors.fill: parent
                                anchors.margins: 6
                                text: "StyledTextArea\nmultiline"
                            }
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "ComboBox / IconComboBox"
                    RowLayout {
                        spacing: 10
                        Widgets.StyledComboBox {
                            model: ["Option A", "Option B", "Option C"]
                        }
                        Widgets.IconComboBox {
                            icon: "palette"
                            model: ["Red", "Green", "Blue"]
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "Switches / Radio / SpinBox / ConfigRow"
                    ColumnLayout {
                        spacing: 8
                        RowLayout {
                            spacing: 10
                            Widgets.StyledSwitch { checked: true }
                            Widgets.StyledRadioButton { description: "Choice A"; checked: true }
                            Widgets.StyledRadioButton { description: "Choice B" }
                        }
                        Widgets.StyledSpinBox {
                            from: 0
                            to: 100
                            value: 42
                        }
                        Widgets.ConfigRow {
                            Widgets.StyledText { text: "A config row:" }
                            Widgets.ConfigSwitch { text: "Enable feature" }
                        }
                        Widgets.ConfigSpinBox {
                            text: "Count"
                            from: 0
                            to: 10
                            value: 3
                        }
                        Widgets.ConfigSelectionArray {
                            configOptionName: "demo"
                            currentValue: "b"
                            options: [
                                { "displayName": "Alpha", "value": "a" },
                                { "displayName": "Beta", "value": "b" },
                                { "displayName": "Gamma", "value": "c" }
                            ]
                        }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Sliders & Progress"
                icon: "linear_scale"

                Widgets.ContentSubsection {
                    title: "StyledSlider / WindowDialogSlider"
                    ColumnLayout {
                        spacing: 10
                        Widgets.StyledSlider {
                            Layout.preferredWidth: 240
                            from: 0
                            to: 1
                            value: 0.35
                        }
                        // Widgets.WindowDialogSlider {
                        //     Layout.preferredWidth: 240
                        //     text: "Volume"
                        //     from: 0
                        //     to: 100
                        //     value: 60
                        // }
                    }
                }

                Widgets.ContentSubsection {
                    title: "Progress indicators"
                    RowLayout {
                        spacing: 24
                        Widgets.CircularProgress {
                            value: 0.7
                        }
                        Widgets.ClippedFilledCircularProgress {
                            value: 0.4
                            icon: "download"
                        }
                        Widgets.StyledProgressBar {
                            value: 0.55
                        }
                        Widgets.StyledBusyIndicator {
                            running: true
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "WaveVisualizer"
                    Widgets.WaveVisualizer {
                        implicitWidth: 240
                        implicitHeight: 60
                        live: false
                        points: [0.1, 0.4, 0.8, 0.3, 0.6, 0.2, 0.9, 0.5]
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Tabs"
                icon: "tab"

                Widgets.ContentSubsection {
                    title: "PrimaryTabBar / SecondaryTabButton"
                    ColumnLayout {
                        spacing: 10
                        Widgets.PrimaryTabBar {
                            Layout.fillWidth: true
                            tabButtonList: [
                                { "icon": "notifications", "name": "Notifications" },
                                { "icon": "volume_up", "name": "Volume" },
                                { "icon": "settings", "name": "Settings" }
                            ]
                            externalTrackedTab: 0
                        }
                        RowLayout {
                            spacing: 6
                            Widgets.SecondaryTabButton { buttonText: "Tab A"; selected: true }
                            Widgets.SecondaryTabButton { buttonText: "Tab B" }
                        }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Layout & Containers"
                icon: "dashboard"

                Widgets.ContentSubsection {
                    title: "Revealer / StyledFlickable / StyledListView"
                    ColumnLayout {
                        spacing: 10
                        Widgets.Revealer {
                            reveal: true
                            Layout.preferredWidth: 200
                            Rectangle {
                                width: 200
                                height: 40
                                color: Appearance.colors.colPrimary ?? "#65558F"
                                Widgets.StyledText {
                                    anchors.centerIn: parent
                                    text: "Revealed content"
                                    color: "white"
                                }
                            }
                        }
                        Rectangle {
                            implicitWidth: 220
                            implicitHeight: 100
                            color: Appearance.colors.colLayer1 ?? "#1c1b20"
                            radius: 8
                            clip: true
                            Widgets.StyledListView {
                                id: demoList
                                anchors.fill: parent
                                model: ["Item 1", "Item 2", "Item 3", "Item 4", "Item 5"]
                                delegate: Widgets.StyledText {
                                    required property string modelData
                                    text: modelData
                                    padding: 4
                                }
                            }
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "RoundCorner / ScrollEdgeFade / StyledRectangularShadow"
                    RowLayout {
                        spacing: 20
                        Widgets.RoundCorner {
                            size: 24
                            color: Appearance.colors.colLayer0 ?? "#141318"
                        }
                        Rectangle {
                            id: shadowTarget
                            width: 80
                            height: 40
                            radius: 6
                            color: Appearance.colors.colLayer2 ?? "#2a2a30"
                            Widgets.StyledRectangularShadow {
                                target: shadowTarget
                            }
                        }
                        Rectangle {
                            id: fadeTarget
                            width: 120
                            height: 60
                            clip: true
                            color: "transparent"
                            Widgets.ScrollEdgeFade {
                                target: fadeTarget
                            }
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "PointingHandInteraction / DragManager"
                    Rectangle {
                        width: 160
                        height: 50
                        radius: 6
                        color: Appearance.colors.colLayer2 ?? "#2a2a30"
                        Widgets.StyledText { anchors.centerIn: parent; text: "Hover / drag me" }
                        Widgets.PointingHandInteraction {}
                        Widgets.DragManager {
                            onDragPressed: (dx, dy) => console.log("drag start", dx, dy)
                        }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Media & Icons"
                icon: "image"

                Widgets.ContentSubsection {
                    title: "MaterialSymbol / CustomIcon / StyledImage / WallpaperDisplay"
                    RowLayout {
                        spacing: 16
                        Widgets.MaterialSymbol {
                            text: "favorite"
                            iconSize: 28
                            fill: 1
                        }
                        Widgets.CustomIcon {
                            source: "settings"
                        }
                        Widgets.StyledImage {
                            width: 60
                            height: 60
                            fillMode: Image.PreserveAspectCrop
                            source: "https://picsum.photos/200"
                        }
                        Widgets.WallpaperDisplay {
                            width: 100
                            height: 60
                            source: "https://picsum.photos/300/200"
                        }
                    }
                }

                Widgets.ContentSubsection {
                    title: "Favicon (needs network)"
                    Widgets.Favicon {
                        url: "https://anthropic.com"
                        displayText: "Anthropic"
                        size: 32
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Tooltips & Popups"
                icon: "chat_bubble"

                Widgets.ContentSubsection {
                    title: "PopupToolTip / StyledToolTip"
                    Rectangle {
                        id: hoverTarget
                        property bool hovered: hoverArea.containsMouse
                        width: 140
                        height: 40
                        radius: 6
                        color: Appearance.colors.colLayer2 ?? "#2a2a30"
                        Widgets.StyledText { anchors.centerIn: parent; text: "Hover for tooltip" }
                        MouseArea {
                            id: hoverArea
                            anchors.fill: parent
                            hoverEnabled: true
                        }
                        Widgets.PopupToolTip {
                            text: "I'm a popup tooltip"
                        }
                        Widgets.StyledToolTip {
                            text: "I'm a styled tooltip"
                        }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Dialogs"
                icon: "chrome_reader_mode"

                Widgets.ContentSubsection {
                    title: "SelectionDialog / WindowDialog"
                    RowLayout {
                        spacing: 16
                        Widgets.RippleButton {
                            buttonText: "Open SelectionDialog"
                            contentItem: Widgets.StyledText { text: "Open SelectionDialog"; anchors.centerIn: parent }
                            onClicked: selectionDialog.visible = !selectionDialog.visible
                        }
                        Widgets.RippleButton {
                            buttonText: "Toggle WindowDialog"
                            contentItem: Widgets.StyledText { text: "Toggle WindowDialog"; anchors.centerIn: parent }
                            onClicked: winDialog.show = !winDialog.show
                        }
                    }

                    Widgets.SelectionDialog {
                        id: selectionDialog
                        visible: false
                        width: 300
                        height: 240
                        titleText: "Pick one"
                        items: ["Choice A", "Choice B", "Choice C"]
                        onCanceled: visible = false
                        onSelected: (result) => { console.log("selected", result); visible = false }
                    }

                    Widgets.WindowDialog {
                        id: winDialog
                        width: 400
                        height: 260
                        Widgets.WindowDialogTitle { text: "Example dialog" }
                        Widgets.WindowDialogParagraph { text: "This is body content inside a WindowDialog." }
                        Widgets.WindowDialogButtonRow {
                            Widgets.DialogButton { buttonText: "Cancel"; onClicked: winDialog.show = false }
                            Widgets.DialogButton { buttonText: "OK"; onClicked: winDialog.show = false }
                        }
                    }
                }
            }

            // ---------------------------------------------------------------
            Widgets.ContentSection {
                title: "Audio (requires Quickshell.Services.Pipewire)"
                icon: "graphic_eq"

                Widgets.ContentSubsection {
                    title: "AudioDeviceSelectorButton / VolumeMixer"
                    ColumnLayout {
                        spacing: 10
                        Widgets.AudioDeviceSelectorButton {
                            input: false
                        }
                        Widgets.AudioDeviceSelectorButton {
                            input: true
                        }
                        Rectangle {
                            implicitWidth: 300
                            implicitHeight: 160
                            color: Appearance.colors.colLayer1 ?? "#1c1b20"
                            radius: 8
                            Widgets.VolumeMixer {
                                anchors.fill: parent
                            }
                        }
                    }
                }
            }
        }
    }
}
