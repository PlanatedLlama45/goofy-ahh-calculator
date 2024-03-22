#include "sprite.hpp"

// Sprite

Sprite::Sprite(uint normalTex, bool hoverReact, uint hoverTex, bool holdReact, uint holdTex, glm::vec2 hitboxSize, glm::vec2 pos, float rot, Window &window, uint shader, 
        int reactButton, bool disableOnHide) : normalTex(normalTex), hoverReact(hoverReact), hoverTex(hoverTex), holdReact(holdReact), holdTex(holdTex),
        hitboxSize(hitboxSize), window(window), shader(shader), reactButton(reactButton), disableOnHide(disableOnHide) {
    initGeometry(hitboxSize);
    transformLocation = glGetUniformLocation(shader, "model");

    transform = { pos, rot };
}

Sprite::~Sprite() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Sprite::draw() const {
    if (hidden)
        return;
    
    glUseProgram(shader);

    glm::mat4 model = glm::mat4(1.0f);
    glm::vec2 pos = 2.0f * transform.position / glm::vec2{ window.width, window.height };
    model = glm::translate(model, { pos, 0.0f });
    model = glm::rotate(model, transform.rotation, { 0.0f, 0.0f, 1.0f });
    glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(model));

    if (holdReact && isHeld())
        glBindTexture(GL_TEXTURE_2D, holdTex);
    else if (hoverReact && isHover())
        glBindTexture(GL_TEXTURE_2D, hoverTex);
    else
        glBindTexture(GL_TEXTURE_2D, normalTex);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

bool Sprite::isHover() const {
    if (disableOnHide && hidden)
        return false;
    double x, y;
    glfwGetCursorPos(window.glWin, &x, &y);
    x = x - 0.5f * window.width;
    y = 0.5f * window.height - y;
    return x >= transform.position.x - 0.5f * hitboxSize.x &&
            y >= transform.position.y - 0.5f * hitboxSize.y &&
            x <= transform.position.x + 0.5f * hitboxSize.x &&
            y <= transform.position.y + 0.5f * hitboxSize.y;
}

bool Sprite::isClicked() {
    if (isHeld()) {
        if (!pressed) {
            pressed = true;
            return true;
        }
    } else
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

Button::Button(uint normalTex, bool hoverReact, uint hoverTex, bool holdReact, uint holdTex, std::string label, Font& font, glm::vec3 textCol, glm::vec2 textOffset,
        glm::vec2 hitboxSize, glm::vec2 pos, Window &window, uint shader, uint textShader, int reactButton, bool disableOnHide) {
    sprite = new Sprite(normalTex, hoverReact, hoverTex, holdReact, holdTex, hitboxSize, pos, 0.0f, window, shader, reactButton, disableOnHide);
    text = new Text(font, pos + textOffset, 1.0f, textCol, textShader, window);
    text->setText(label);
}

Button::~Button() {
    delete sprite;
    delete text;
}

void Button::draw() {
    if (hidden)
        return;
    
    sprite->draw();
    text->draw();
}

