#pragma once

#include "config.hpp"
#include "window.hpp"
#include "transform.hpp"
#include "text.hpp"

class Sprite {
public:
    glm::vec2 hitboxSize;
    Transform transform;
    Window &window;

    Sprite(cstr texture, glm::vec2 hitboxSize, glm::vec2 pos, float rot, Window &window, uint shader);
    ~Sprite();

    void draw() const;
    bool isHover() const;
    bool isHeld(int button) const;
    bool isClicked(int button);

private:
    uint texture, VAO, VBO, transformLocation, shader;
    bool pressed = false;

    void initGeometry(glm::vec2 size);
};


class Button {
public:
    Button(cstr background, std::string label, Font &font, glm::vec3 textCol, glm::vec2 textOffset, glm::vec2 hitboxSize, glm::vec2 pos, Window &window, uint shader, uint textShader);
    ~Button();

    void draw();
    void setLabel(std::string str);
    inline bool isHover() const { return sprite->isHover(); }
    inline bool isHeld(int button) const { return sprite->isHeld(button); }
    inline bool isClicked(int button) { return sprite->isClicked(button); }

private:
    Sprite *sprite;
    Text *text;
};
