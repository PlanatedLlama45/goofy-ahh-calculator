#include "sprite.hpp"

// Sprite

Sprite::Sprite(cstr texture, glm::vec2 hitboxSize, glm::vec2 pos, float rot, Window &window, uint shader) : hitboxSize(hitboxSize), window(window), shader(shader) {
    this->texture = loadTexture(texture);
    initGeometry(hitboxSize);
    transformLocation = glGetUniformLocation(shader, "model");

    transform = { pos, rot };
}

Sprite::~Sprite() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteTextures(1, &texture);
}

void Sprite::draw() const {
    glUseProgram(shader);

    glm::mat4 model = glm::mat4(1.0f);
    glm::vec2 pos = 2.0f * transform.position / glm::vec2{ window.width, window.height };
    model = glm::translate(model, { pos, 0.0f });
    model = glm::rotate(model, transform.rotation, { 0.0f, 0.0f, 1.0f });
    glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(model));

    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

bool Sprite::isHover() const {
    double x, y;
    glfwGetCursorPos(window.glWin, &x, &y);
    x = x - 0.5f * window.width;
    y = 0.5f * window.height - y;
    return x >= transform.position.x - 0.5f * hitboxSize.x &&
            y >= transform.position.y - 0.5f * hitboxSize.y &&
            x <= transform.position.x + 0.5f * hitboxSize.x &&
            y <= transform.position.y + 0.5f * hitboxSize.y;
}

bool Sprite::isHeld(int button) const {
    return glfwGetMouseButton(window.glWin, button) * isHover();
}

bool Sprite::isClicked(int button) {
    if (isHeld(button)) {
        if (!pressed) {
            pressed = true;
            return true;
        }
    }
    else
        pressed = false;
    return false;
}

void Sprite::initGeometry(glm::vec2 size) {
    size.x /= window.width;
    size.y /= window.height;
    
    float verts[30] = {
         size.x,  size.y,  1.0f, 0.0f,
         size.x, -size.y,  1.0f, 1.0f,
        -size.x,  size.y,  0.0f, 0.0f,

        -size.x,  size.y,  0.0f, 0.0f,
         size.x, -size.y,  1.0f, 1.0f,
        -size.x, -size.y,  0.0f, 1.0f
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 30 * 4, verts, GL_STATIC_DRAW);
    // Position
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 16, (void*)0);
    glEnableVertexAttribArray(0);
    // Texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 16, (void*)8);
    glEnableVertexAttribArray(1);
}


// Button

Button::Button(cstr background, std::string label, Font& font, glm::vec3 textCol, glm::vec2 textOffset, glm::vec2 hitboxSize, glm::vec2 pos, Window &window, uint shader, uint textShader) {
    sprite = new Sprite(background, hitboxSize, pos, 0.0f, window, shader);
    text = new Text(font, pos + textOffset, 1.0f, textCol, textShader, window);
    text->setText(label);
}

Button::~Button() {
    delete sprite;
    delete text;
}

void Button::draw() {
    sprite->draw();
    text->draw();
}

void Button::setLabel(std::string str) {
    text->setText(str);
}

