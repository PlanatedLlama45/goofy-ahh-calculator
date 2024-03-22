#version 330 core

in vec2 f_texCoord;

out vec4 color;

uniform sampler2D text;
uniform vec3 textColor;

void main() {
    vec4 sampled = vec4(1.0f, 1.0f, 1.0f, texture(text, f_texCoord).r);
    color = vec4(textColor, 1.0f) * sampled;
}
