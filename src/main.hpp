#include "config.hpp"
#include "maintenance.hpp"
#include "sprite.hpp"
#include "text.hpp"
#include "ast.hpp"

constexpr int maxNum = INT_MAX / 10;

#define makeFont(varName, fontName, size) Font varName; if (varName.load(fontPath(fontName), size)) return -1
#define addButton(id, btnType, label, offsetX, offsetY, posX, posY) Button btn##id(btnType.normalTex, btnType.doHoverTex, btnType.hoverTex, btnType.doPressTex, btnType.pressedTex, label, \
    btnType.font, btnType.textColor, { offsetX, offsetY }, btnType.size, { posX, posY }, btnType.window, btnType.shader, btnType.textShader, btnType.reactButton, btnType.disableOnHide); buttons.push_back(&btn##id)

#define addButtonScreen(screenId, id, btnType, label, offsetX, offsetY, posX, posY) addButton(id, btnType, label, offsetX, offsetY, posX, posY); screen##screenId.push_back(btn##id)

#define screenVar(screenId) std::vector<ref(Button)> screen##screenId
#define hideScreen(screenId) for (ref(Button) btn : screen##screenId) btn.get().setHidden(true)
#define showScreen(screenId) for (ref(Button) btn : screen##screenId) btn.get().setHidden(false)
#define switchScreenHidden(screenId) for (ref(Button) btn : screen##screenId) btn.get().switchHidden()

#define onBtnClick(btnId, func, ...) if (btn##btnId.isClicked()) func(__VA_ARGS__)
#define onBtnHold(btnId, func, ...) if (btn##btnId.isHeld()) func(__VA_ARGS__)
#define onBtnHover(btnId, func, ...) if (btn##btnId.isHover()) func(__VA_ARGS__)

struct CalcData {
public:
    Text &txtRes;

    std::stack<std::string> history;

    bool decimal;
    bool degrees;

    uint16_t exp;
    byte selectedScreen;
};


struct ButtonType {
public:
    uint normalTex;
    bool doHoverTex;
    uint hoverTex;
    bool doPressTex;
    uint pressedTex;

    Font &font;
    glm::vec3 textColor;

    glm::vec2 size;

    Window &window;

    uint shader, textShader;
    int reactButton;
    bool disableOnHide;
};


inline bool isInteger(double num) { return num == (double)(int)num; }
inline bool getNthBit(byte num, uint bit) { return (num >> bit) & 1; }
inline byte setNthBit(byte num, uint bit, bool val) { return (num & ~(1 << bit)) | (val << bit); }

extern void switchScreen(CalcData &cd, byte switchId, screenVar(0), screenVar(1), screenVar(2), screenVar(3));
extern void updateScreens(CalcData &cd, screenVar(0), screenVar(1), screenVar(2), screenVar(3));
extern void switchAngleType(CalcData &cd, Button &btnAng);

extern void updateCalc(CalcData &cd, cstr data);

extern int main(int argc, cstr *argv);
