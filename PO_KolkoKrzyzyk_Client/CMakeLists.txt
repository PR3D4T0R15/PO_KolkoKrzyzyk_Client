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
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

## Qt project setup ##
qt_standard_project_setup()

## Qt ADD EXE ##
qt_add_executable("${PROJECT_NAME}"  
    "src/main.cpp"

    "include/WindowControl.h" #class exposed to QML
    "src/WindowControl.cpp"

    "include/MainWindowControl.h" #class exposed to QML
    "src/MainWindowControl.cpp"

    "include/StartViewControl.h" #class exposed to QML
    "src/StartViewControl.cpp"

    "include/HomeViewControl.h" #class exposed to QML
    "src/HomeViewControl.cpp"

    "include/MatchmakingViewControl.h" #class exposed to QML
    "src/MatchmakingViewControl.cpp"

    "include/TcpClient.h" #class for tcp socket client
    "src/TcpClient.cpp"

    "include/ConnectionManager.h" #class for sending and receiving data
    "src/ConnectionManager.cpp"

    "include/GameViewControl.h" #class exposed to QML
    "src/GameViewControl.cpp"

    "include/JsonDoc.h" #class for building data
    "src/JsonDoc.cpp"

    "include/SettingsFile.h" #class for config file
    "src/SettingsFile.cpp"

    "include/EndGameViewControl.h" #class for config file
    "src/EndGameViewControl.cpp"
)

## Qt resources ##
qt_add_binary_resources("PO_KolkoKrzyzyk_GUI" "ui/PO_KolkoKrzyzyk_GUI.qrc" DESTINATION "ui/PO_KolkoKrzyzyk_GUI.rcc" OPTIONS -no-compress)
add_dependencies("${PROJECT_NAME}" "PO_KolkoKrzyzyk_GUI")

target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Gui)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Qml)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Quick)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Multimedia)

set_target_properties("${PROJECT_NAME}" PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_custom_target(copy_config ALL COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/cfg/config.ini" "${PROJECT_BINARY_DIR}/config.ini" COMMENT "Copying config file")
add_dependencies("${PROJECT_NAME}" copy_config)