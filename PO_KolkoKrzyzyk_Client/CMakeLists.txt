cmake_minimum_required(VERSION 3.16)

project("KolkoKrzyzyk" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## QT ##
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


######## QT PACKAGES ########
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Qml)

qt_standard_project_setup()


## DIR SETUP ##
set(include_DIR "${CMAKE_SOURCE_DIR}/include")
set(source_DIR "${CMAKE_SOURCE_DIR}/src")
set(ui_DIR "${CMAKE_SOURCE_DIR}/ui")

include_directories(${include_DIR})
include_directories(${source_DIR})
include_directories(${ui_DIR})



qt_add_executable("${PROJECT_NAME}"
    "src/main.cpp"
    "include/main.h"
)

target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Gui)
target_link_libraries("${PROJECT_NAME}" PRIVATE Qt6::Qml)

set_target_properties("${PROJECT_NAME}" PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)