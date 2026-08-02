find_package(Qt6 6.7 REQUIRED COMPONENTS Gui)

qt6_add_qml_module(SleexUiKitFunctions
    URI SleexUiKit.Functions
    VERSION 1.0
    SOURCES
        ColorUtils.cpp ColorUtils.hpp
        DesktopUtils.cpp DesktopUtils.hpp
        FileUtils.cpp FileUtils.hpp
        Fuzzy.cpp Fuzzy.hpp
        Lavendist.cpp Lavendist.hpp
        ObjectUtils.cpp ObjectUtils.hpp
        StringUtils.cpp StringUtils.hpp
        plugin.cpp
    OUTPUT_DIRECTORY ${SLEEX_UI_KIT_QML_ROOT}/SleexUiKit/Functions
)

target_link_libraries(SleexUiKitFunctions PRIVATE Qt6::Gui)

install(DIRECTORY ${SLEEX_UI_KIT_QML_ROOT}/SleexUiKit/Functions/ DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Functions)
install(TARGETS SleexUiKitFunctionsplugin LIBRARY DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Functions RUNTIME DESTINATION ${SLEEX_UI_KIT_INSTALL_QMLDIR}/Functions)
install(TARGETS SleexUiKitFunctions LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})