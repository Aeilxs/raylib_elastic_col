cmake_minimum_required(VERSION 3.10)
project(app CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path to assets
set(ASSETS_PATH "\"${CMAKE_CURRENT_SOURCE_DIR}/assets/\"")

# Configure config.h from config.h.in
set(CONFIG_HEADER_IN "${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.in")
set(CONFIG_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/config.h")
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
configure_file(${CONFIG_HEADER_IN} ${CONFIG_HEADER})

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Adding sources files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}") # Include directory where config.h is generated
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Executable inside root folder.
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/$<0:>)
