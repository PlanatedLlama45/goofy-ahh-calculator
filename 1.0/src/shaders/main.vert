#version 330 core

layout (location=0) in vec2 v_pos;
layout (location=1) in vec2 v_texCoord;

out vec2 f_texCoord;

uniform mat4 model;

void main() {
    gl_Position = model * vec4(v_pos, 0.0f, 1.0f);
    
    f_texCoord = v_texCoord;
}
