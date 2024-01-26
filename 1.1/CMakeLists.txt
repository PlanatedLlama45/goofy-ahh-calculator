cmake_minimum_required(VERSION 3.5.0)
project(goofy-ahh-calculator VERSION 1.1.0)

find_package(OpenGL REQUIRED)

add_executable(
    goofy-ahh-calculator
    
    src/glad.c

    src/main.cpp
    src/main.hpp

    src/config.hpp
    src/config.cpp

    src/sprite.hpp
    src/sprite.cpp

    src/window.hpp

    src/maintenance.hpp
    src/maintenance.cpp

    src/text.hpp
    src/text.cpp

    src/transform.hpp
)

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
)
