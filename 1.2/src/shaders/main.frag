#version 330 core

in vec2 f_texCoord;

out vec4 color;

uniform sampler2D material;

void main() {
    color = texture2D(material, f_texCoord);
}
