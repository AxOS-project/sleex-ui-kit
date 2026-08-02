cmake_minimum_required(VERSION 3.21)
project(SleexUiKit VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.7 REQUIRED COMPONENTS Core Qml Quick Gui)
qt_standard_project_setup(REQUIRES 6.7)
include(GNUInstallDirs)

set(SLEEX_UI_KIT_QML_ROOT "${CMAKE_BINARY_DIR}/qml" CACHE PATH "Root directory the SleexUiKit.* modules are generated into")
set(SLEEX_UI_KIT_INSTALL_QMLDIR "${QT6_INSTALL_PREFIX}/${QT6_INSTALL_QML}/SleexUiKit" CACHE PATH "Install destination for the SleexUiKit.* modules")

add_subdirectory(src/Functions)
add_subdirectory(src/Appearance)
add_subdirectory(src/Widgets)