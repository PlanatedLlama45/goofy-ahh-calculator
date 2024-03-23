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

#include <stb_image.h>

#include <vector>
#include <unordered_map>
#include <stack>

#include <fstream>
#include <sstream>
#include <string>

#include "math_parser/math_parser.hpp"

#define ref(type) std::reference_wrapper<type>

#define __makePath(root, filename, extension) root filename extension
#define fontPath(name) __makePath("../fonts/", name, ".ttf")
#define texPath(name) __makePath("../img/", name, "")
#define shaderPath(name) __makePath("../src/shaders/", name, "")

typedef unsigned int uint;
typedef const char* cstr;
typedef unsigned char byte;

extern uint loadTexture(cstr filename, int *width = nullptr, int *height = nullptr);

template <class T>
extern inline void deleteStackTop(std::stack<T *> &st) {
    if (!st.empty()) {
        delete st.top();
        st.pop();
    }
}

template <class T>
extern inline void deleteStack(std::stack<T *> &st) {
    while (!st.empty()) {
        delete st.top();
        st.pop();
    }
}

template <class T>
extern inline T tryGetTop(std::stack<T> &st, T err) {
    if (st.empty())
        return err;
    return st.top();
}

extern inline std::string tryGetTop(std::stack<std::string> &st, std::string err) {
    if (st.empty())
        return err;
    return st.top();
}

inline double deg2rad(double deg) { return deg * M_PI / 180.0; }
inline double rad2deg(double rad) { return rad * 180.0 / M_PI; }

inline double fact(double x) { return std::tgamma(x + 1); }

inline double nPr(double n, double r) { return fact(n) / fact(n - r); }
inline double nCr(double n, double r) { return nPr(n, r) / fact(r); }
