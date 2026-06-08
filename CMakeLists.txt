cmake_minimum_required(VERSION 3.5)
project(kronknet LANGUAGES C)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    message(FATAL_ERROR "Les builds dans le dossier source sont interdits. Créez un dossier build/.")
endif()

file(GLOB_RECURSE KRONKNET_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_library(kronknet-obj ${KRONKNET_SOURCES})

target_include_directories(kronknet-obj
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(kronknet-obj PRIVATE
    -Wall
    -Wextra
    -O3
)

add_library(kronknet-static STATIC
    $<TARGET_OBJECTS:kronknet-obj>
)

target_link_libraries(kronknet-static
    PUBLIC
        kronknet-obj
)

add_library(kronknet-shared SHARED
    $<TARGET_OBJECTS:kronknet-obj>
)

target_link_libraries(kronknet-shared
    PUBLIC
        kronknet-obj
)

add_library(kronknet ALIAS kronknet-static)

set_target_properties(kronknet-static PROPERTIES
    OUTPUT_NAME kronknet
)

set_target_properties(kronknet-shared PROPERTIES
    OUTPUT_NAME kronknet
)

set_target_properties(kronknet-obj PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
