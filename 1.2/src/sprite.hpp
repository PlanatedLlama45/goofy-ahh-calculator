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

    Sprite(uint normalTex, bool hoverReact, uint hoverTex, bool holdReact, uint holdTex, glm::vec2 hitboxSize, glm::vec2 pos, float rot,
        Window &window, uint shader, int reactButton = GLFW_MOUSE_BUTTON_LEFT, bool disableOnHide = true);
    ~Sprite();

    void draw() const;
    bool isHover() const;
    inline bool isHeld() const { return glfwGetMouseButton(window.glWin, reactButton) * isHover(); }
    bool isClicked();
    inline void setHidden(bool val) { hidden = val; }
    inline void switchHidden() { hidden = !hidden; }

private:
    uint VAO, VBO, transformLocation, shader, normalTex, hoverTex, holdTex;
    bool pressed = false, hidden = false, hoverReact, holdReact, disableOnHide;
    int reactButton;

    void initGeometry(glm::vec2 size);
};


class Button {
public:
    Button(uint normalTex, bool hoverReact, uint hoverTex, bool holdReact, uint holdTex, std::string label, Font &font, glm::vec3 textCol,
        glm::vec2 textOffset, glm::vec2 hitboxSize, glm::vec2 pos, Window &window, uint shader, uint textShader, int reactButton = GLFW_MOUSE_BUTTON_LEFT, bool disableOnHide = true);
    ~Button();

    void draw();
    inline void setLabel(std::string str) { text->setText(str); }
    inline bool isHover() const { return sprite->isHover(); }
    inline bool isHeld() const { return sprite->isHeld(); }
    inline bool isClicked() { return sprite->isClicked(); }
    inline void setHidden(bool val) { hidden = val; sprite->setHidden(val); }
    inline void switchHidden() { hidden = !hidden; sprite->switchHidden(); }

private:
    Sprite *sprite;
    Text *text;
    bool hidden = false;
};
