#pragma once

#include "config.hpp"
#include "window.hpp"
#include "transform.hpp"

class Font {
public:
    struct Character {
        uint texture;
        glm::ivec2 size;
        glm::ivec2 bearing;
        uint advance;
    };

    std::unordered_map<char, Character> characters;

    Font();
    ~Font();

    int load(cstr filePath, int fontSize);
};

class Text {
public:
    Transform transform;
    Font &font;

    Text(Font &font, glm::vec2 pos, float scale, glm::vec3 color, uint shader, Window &window);
    ~Text();

    void setText(std::string str);
    std::string getText() const;
    void draw();
    inline void setHidden(bool val) { hidden = val; }
    inline void switchHidden() { hidden = !hidden; }

private:
    std::string text;
    bool hidden = false;
    uint shader, VAO, VBO, textColorLocation;
    Window &window;
    glm::vec3 color;
    float scale;

};
