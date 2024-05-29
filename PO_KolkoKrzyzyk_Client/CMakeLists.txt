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
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS StateMachine)

## Qt project setup ##
qt_standard_project_setup()

## Qt ADD EXE ##
qt_add_executable("${PROJECT_NAME}"
    "include/main.h"    
    "src/main.cpp"

    "include/WindowControl.h"
    "src/WindowControl.cpp"

    "include/TcpClient.h"
    "src/TcpClient.cpp"

    "include/GameControl.h"
    "src/GameControl.cpp"
)

## Qt resources ##
qt_add_binary_resources("PO_KolkoKrzyzyk_GUI" "ui/PO_KolkoKrzyzyk_GUI.qrc" DESTINATION "ui/PO_KolkoKrzyzyk_GUI.rcc" OPTIONS -no-compress)
add_dependencies("${PROJECT_NAME}" "PO_KolkoKrzyzyk_GUI")

target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Gui)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Qml)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Quick)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::StateMachine)

set_target_properties("${PROJECT_NAME}" PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)