cmake_minimum_required(VERSION 3.5.0)
project(goofy-ahh-calculator VERSION 2.1.1)

# Comment to enable console
set(CMAKE_CXX_FLAGS "-mwindows")

find_package(OpenGL REQUIRED)

file(
    GLOB SOURCES

    src/*.c
    src/*.h
    src/*.cpp
    src/*.hpp

    src/*/*.c
    src/*/*.h
    src/*/*.cpp
    src/*/*.hpp
)

add_executable(goofy-ahh-calculator WIN32 ${SOURCES})

target_include_directories(
    goofy-ahh-calculator

    PRIVATE dependencies
    ${CMAKE_SOURCE_DIR}/../.public-include
)

target_link_libraries(
    goofy-ahh-calculator

    ${CMAKE_SOURCE_DIR}/dependencies/libglfw3.a
    ${CMAKE_SOURCE_DIR}/dependencies/freetype.lib
    OpenGL::GL

    -static
)

set_target_properties(goofy-ahh-calculator PROPERTIES OUTPUT_NAME "Goofy Ahh Calculator")
