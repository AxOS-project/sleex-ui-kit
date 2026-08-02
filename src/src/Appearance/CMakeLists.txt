find_package(Qt6 6.7 REQUIRED COMPONENTS Gui)

qt6_add_qml_module(SleexUiKitAppearance
    URI SleexUiKit.Appearance
    VERSION 1.0
    OUTPUT_DIRECTORY ${SLEEX_UI_KIT_QML_ROOT}/SleexUiKit/Appearance
)

target_link_libraries(SleexUiKitAppearance PRIVATE Qt6::Gui SleexUiKitFunctions)

target_sources(SleexUiKitAppearance PRIVATE
    Appearance.hpp
    Appearance.cpp
)

install(DIRECTORY ${SLEEX_UI_KIT_QML_ROOT}/SleexUiKit/Appearance/
    DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Appearance
)

install(TARGETS SleexUiKitAppearanceplugin
    LIBRARY DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Appearance
    RUNTIME DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Appearance
)

install(TARGETS SleexUiKitAppearance
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
)