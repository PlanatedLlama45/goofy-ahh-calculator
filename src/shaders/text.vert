#version 330 core

layout (location=0) in vec4 vert;

out vec2 f_texCoord;

uniform mat4 model;

void main() {
    gl_Position = model * vec4(vert.xy, 0.0f, 1.0f);
    
    f_texCoord = vert.zw;
}
