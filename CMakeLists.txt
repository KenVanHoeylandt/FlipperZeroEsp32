cmake_minimum_required(VERSION 3.15)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

if (IDF_TARGET)
    add_definitions(-DIDF_TARGET)
endif()

project(FlipperZeroEsp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXTRA_COMPONENT_DIRS
    $CMAKE_CURRENT_SOURCE_DIR/components/applications
    $CMAKE_CURRENT_SOURCE_DIR/components/furi
)
