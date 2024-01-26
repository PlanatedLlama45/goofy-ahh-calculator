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

#include <functional>

typedef unsigned int uint;
typedef const char* cstr;
typedef unsigned char byte;

extern uint loadTexture(cstr filename, int *width = nullptr, int *height = nullptr);
