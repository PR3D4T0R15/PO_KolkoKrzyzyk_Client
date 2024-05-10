cmake_minimum_required(VERSION 3.16)

project("KolkoKrzyzyk" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Qt ##
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


## Qt PACKAGES ##
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Qml)

## Qt project setup ##
qt_standard_project_setup()

## Qt ADD EXE ##
qt_add_executable("${PROJECT_NAME}"
    "src/main.cpp"
    "src/WindowControl.cpp"
    "src/GameControl.cpp"
    "include/main.h"
    "include/WindowControl.h"
    "include/GameControl.h"
    "ui/PO_KolkoKrzyzyk_GUI.qrc"
)

target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Gui)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Qml)

set_target_properties("${PROJECT_NAME}" PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)