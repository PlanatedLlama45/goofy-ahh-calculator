#include "config.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

uint loadTexture(cstr filename, int *width, int *height) {
    int m_width, m_height, channels;
    unsigned char* data = stbi_load(filename, &m_width, &m_height, &channels, STBI_rgb_alpha);

    uint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexImage2D(
        GL_TEXTURE_2D,
        0, GL_RGBA, m_width, m_height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, data
    );

    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glGenerateMipmap(GL_TEXTURE_2D);

    if (width != nullptr)
        *width = m_width;
    
    if (height != nullptr)
        *height = m_height;

    return texture;
}
