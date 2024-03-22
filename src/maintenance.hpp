#pragma once

#include "config.hpp"
#include "window.hpp"

extern uint makeModule(cstr filepath, uint moduleType);
extern uint makeShader(cstr vertexFilepath, cstr fragmentFilepath);
extern bool init(int width, int height, cstr title, bool windowResizeable, Window &window);
extern void closeOpenGL(std::vector<uint> shader, Window &window);
