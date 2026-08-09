qt6_add_qml_module(SleexUiKitWidgets
    URI SleexUiKit.Widgets
    VERSION 1.0
    QML_FILES
        AudioDeviceSelectorButton.qml
        ButtonGroup.qml
        CircularProgress.qml
        CliphistImage.qml
        ClippedFilledCircularProgress.qml
        ConfigRow.qml
        ConfigSelectionArray.qml
        ConfigSpinBox.qml
        ConfigSwitch.qml
        ContentPage.qml
        ContentSection.qml
        ContentSubsection.qml
        ContentSubsectionLabel.qml
        CustomIcon.qml
        DialogButton.qml
        DragManager.qml
        Favicon.qml
        FloatingActionButton.qml
        GroupButton.qml
        IconComboBox.qml
        KeyboardKey.qml
        MaterialSymbol.qml
        MaterialTextField.qml
        MenuButton.qml
        PointingHandInteraction.qml
        PointingHandLinkHover.qml
        PopupToolTip.qml
        PrimaryTabBar.qml
        PrimaryTabButton.qml
        Revealer.qml
        RippleButton.qml
        RippleButtonWithIcon.qml
        RoundCorner.qml
        ScrollEdgeFade.qml
        ScrollingText.qml
        SecondaryTabButton.qml
        SelectionDialog.qml
        SelectionGroupButton.qml
        StyledBusyIndicator.qml
        StyledComboBox.qml
        StyledFlickable.qml
        StyledImage.qml
        StyledLabel.qml
        StyledListView.qml
        StyledProgressBar.qml
        StyledRadioButton.qml
        StyledRectangularShadow.qml
        StyledScrollBar.qml
        StyledSlider.qml
        StyledSpinBox.qml
        StyledSwitch.qml
        StyledText.qml
        StyledTextArea.qml
        StyledTextInput.qml
        StyledToolTip.qml
        StyledToolTipContent.qml
        TimePicker.qml
        VerticalButtonGroup.qml
        VolumeMixer.qml
        WallpaperDisplay.qml
        WaveVisualizer.qml
        WindowDialog.qml
        WindowDialogButtonRow.qml
        WindowDialogParagraph.qml
        WindowDialogSectionHeader.qml
        WindowDialogSeparator.qml
        WindowDialogSlider.qml
        WindowDialogTitle.qml
    DEPENDENCIES
        SleexUiKit.Appearance
        SleexUiKit.Functions
    OUTPUT_DIRECTORY ${SLEEX_UI_KIT_QML_ROOT}/SleexUiKit/Widgets
    # NO_PLUGIN
)

install(DIRECTORY ${SLEEX_UI_KIT_QML_ROOT}/SleexUiKit/Widgets/ DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Widgets)
install(TARGETS SleexUiKitWidgetsplugin LIBRARY DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Widgets RUNTIME DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Widgets)
install(TARGETS SleexUiKitWidgets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})