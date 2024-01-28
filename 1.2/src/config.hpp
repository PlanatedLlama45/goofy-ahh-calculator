#pragma once

#include <iostream>
// Opengl v4.6
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <vector>
#include <unordered_map>

#include <fstream>
#include <sstream>
#include <string>

#define ref(type) std::reference_wrapper<type>

#define __makePath(root, filename, extension) root filename extension
#define fontPath(name) __makePath("../fonts/", name, ".ttf")
#define texPath(name) __makePath("../img/", name, "")
#define shaderPath(name) __makePath("../src/shaders/", name, "")

typedef unsigned int uint;
typedef const char* cstr;
typedef unsigned char byte;

extern uint loadTexture(cstr filename, int *width = nullptr, int *height = nullptr);
