#include "config.hpp"
#include "maintenance.hpp"
#include "sprite.hpp"
#include "text.hpp"

constexpr int maxNum = INT_MAX / 10;

#define makeFont(varName, fontName, size) Font varName; if (varName.load(fontPath(fontName), size)) return -1
#define addButton(id, btnType, label, offsetX, offsetY, posX, posY) Button btn##id(btnType.normalTex, btnType.doHoverTex, btnType.hoverTex, btnType.doPressTex, btnType.pressedTex, label, \
    btnType.font, btnType.textColor, { offsetX, offsetY }, btnType.size, { posX, posY }, btnType.window, btnType.shader, btnType.textShader, btnType.reactButton); buttons.push_back(btn##id)

#define onBtnClick(btnId, func, ...) if (btn##btnId.isClicked()) func(__VA_ARGS__)
#define onBtnHold(btnId, func, ...) if (btn##btnId.isHeld()) func(__VA_ARGS__)
#define onBtnHover(btnId, func, ...) if (btn##btnId.isHover()) func(__VA_ARGS__)

struct CalcData {
public:
    Text &txtRes;

    double num1;
    double num2;
    char op;
    cstr func;

    bool begunInp;
    bool secondInp;
    bool solved;
    bool decimal;

    int exp;
    byte lastInp;
};


struct ButtonType {
public:
    Font &font;
    glm::vec3 textColor;
    bool doHoverTex, doPressTex;
    uint normalTex, hoverTex, pressedTex;
    glm::vec2 size;
    Window &window;
    uint shader, textShader;
    int reactButton;
};

inline bool isInteger(double num) { return num == (double)(int)num; }
inline double deg2rad(double deg) { return deg * M_PI / 180.0; }

extern void display(CalcData &cd);
extern void doNumClick(int btn, CalcData &cd);
extern void doOpClick(char btn, CalcData &cd);
extern void doClear(CalcData &cd);
extern void doSolve(CalcData &cd);
extern void doSign(CalcData &cd);
extern void doDecimal(CalcData &cd);
extern void doErase(CalcData &cd);
extern void doFunClick(cstr fun, CalcData &cd);

extern int main(int argc, cstr *argv);
