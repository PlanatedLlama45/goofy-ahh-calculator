#include "main.hpp"

std::string dispNum(CalcData &cd, bool secondNum) {
    std::stringstream disp;

    if (secondNum) {
        if (cd.con2 != "")
            disp << cd.con2;
        else
            disp << cd.num2;
    }
    else {
        if (cd.con1 != "")
            disp << cd.con1;
        else
            disp << cd.num1;
    }

    return disp.str();
}

void display(CalcData &cd) {
    if (!cd.secondInp && !cd.begunInp && cd.func == "") {
        cd.txtRes.setText("");
        return;
    }

    std::stringstream disp;

    if (cd.func != "") {
        disp << cd.func << '(';
        if (cd.begunInp)
            disp << dispNum(cd, false);
        disp << ')';
    }
    else if (!cd.secondInp)
        disp << dispNum(cd, false);
    else if (!cd.begunInp)
        disp << dispNum(cd, false) << cd.op;
    else {
        if (cd.num2 < 0.0)
            disp << dispNum(cd, false) << cd.op << '(' << dispNum(cd, true) << ')';
        else
            disp << dispNum(cd, false) << cd.op << dispNum(cd, true);
    }
    
    cd.txtRes.setText(disp.str());
}

void doNumClick(CalcData &cd, int btn) {
    if (!cd.canInput)
        return;
    
    if (cd.solved)
        doClear(cd);
    
    cd.begunInp = true;
    cd.lastInp = btn;

    if (cd.secondInp) {
        if (cd.num2 > maxNum - btn)
            return;
        
        if (!cd.decimal) {
            cd.num2 *= 10;
            cd.num2 += btn;
        }
        else {
            cd.num2 += btn * std::pow(10, -cd.exp);
            cd.exp++;
        }
    }
    else {
        if (cd.num1 > maxNum - btn)
            return;
        
        if (!cd.decimal) {
            cd.num1 *= 10;
            cd.num1 += btn;
        }
        else {
            cd.num1 += btn * std::pow(10, -cd.exp);
            cd.exp++;
        }
    }

    display(cd);
}

void doOpClick(CalcData &cd, char btn) {
    if (!cd.begunInp)
        return;
    else if (cd.secondInp && cd.func == "" || cd.func != "")
        doSolve(cd);

    cd.op = btn;
    cd.begunInp = false;
    cd.secondInp = true;
    cd.solved = false;
    cd.decimal = false;
    cd.canInput = true;
    display(cd);
}

void doClear(CalcData &cd) {
    cd.num1 = 0.0;
    cd.num2 = 0.0;
    cd.op = ' ';
    cd.func = "";
    cd.con1 = "";
    cd.con2 = "";
    cd.begunInp = false;
    cd.secondInp = false;
    cd.solved = false;
    cd.decimal = false;

    display(cd);
}

void doSolve(CalcData &cd) {
    if ((!cd.begunInp || !cd.secondInp) && cd.func == "" || (cd.func != "" && !cd.begunInp))
        return;

    if (cd.func == "")
        switch (cd.op) {
        case '+': cd.num1 = cd.num1 + cd.num2; break;
        case '-': cd.num1 = cd.num1 - cd.num2; break;
        case '*': cd.num1 = cd.num1 * cd.num2; break;
        case '/': cd.num1 = cd.num1 / cd.num2; break;
        case '^': cd.num1 = std::pow(cd.num1, cd.num2); break;
        case '%': cd.num1 = std::fmod(cd.num1, cd.num2); break;
        default: return;
        }
    else {
        // Trig
        if (cd.funIsTrig) {
            if (cd.degrees && cd.func[0] != 'a')
                cd.num1 = deg2rad(cd.num1);
            
            double out;
            // Normal trig
            if (cd.func == "sin")
                out = std::sin(cd.num1);
            else if (cd.func == "cos")
                out = std::cos(cd.num1);
            else if (cd.func == "tan")
                out = std::tan(cd.num1);
            else if (cd.func == "cot")
                out = 1.0 / std::tan(cd.num1);

            // Inversed trig
            else if (cd.func == "asin")
                out = std::asin(cd.num1);
            else if (cd.func == "acos")
                out = std::acos(cd.num1);
            else if (cd.func == "atan")
                out = std::atan(cd.num1);
            else if (cd.func == "acot")
                out = std::atan(1.0 / cd.num1);

            // Hyperbolic trig
            if (cd.func == "sinh")
                out = std::sinh(cd.num1);
            else if (cd.func == "cosh")
                out = std::cosh(cd.num1);
            else if (cd.func == "tanh")
                out = std::tanh(cd.num1);
            else if (cd.func == "coth")
                out = 1.0 / std::tanh(cd.num1);

            // Inversed hyperbolic trig
            else if (cd.func == "asinh")
                out = std::asinh(cd.num1);
            else if (cd.func == "acosh")
                out = std::acosh(cd.num1);
            else if (cd.func == "atanh")
                out = std::atanh(cd.num1);
            else if (cd.func == "acoth")
                out = std::atanh(1.0 / cd.num1);
            
            if (cd.degrees && cd.func[0] == 'a')
                out = rad2deg(out);
            
            cd.num1 = out;
        }
        // Other functions
        else {
            if (cd.func == "sqrt")
                cd.num1 = std::sqrt(cd.num1);
            else if (cd.func == "cbrt")
                cd.num1 = std::cbrt(cd.num1);
            else if (cd.func == "lg")
                cd.num1 = std::log10(cd.num1);
            else if (cd.func == "ln")
                cd.num1 = std::log(cd.num1);
        }
    }

    cd.num2 = 0;
    cd.op = ' ';
    cd.func = "";
    cd.con1 = "";
    cd.con2 = "";
    cd.begunInp = true;
    cd.secondInp = false;
    cd.solved = true;
    cd.decimal = false;
    cd.canInput = true;

    display(cd);
}

void doSign(CalcData &cd) {
    if (cd.secondInp)
        cd.num2 *= -1;
    else
        cd.num1 *= -1;
    
    display(cd);
}

void doErase(CalcData &cd) {
    if (cd.solved) {
        doClear(cd);
        return;
    }

    if (!cd.begunInp) {
        if (cd.func == "")
            return;
        else {
            cd.func = "";
            display(cd);
        }
    }
    
    if (cd.secondInp) {
        if (cd.decimal) {
            cd.exp--;
            cd.num2 -= cd.lastInp * std::pow(10, -cd.exp);
            if (isInteger(cd.num2))
                cd.decimal = false;
        }
        else
            cd.num2 = (long)(cd.num2 / 10);

        if (cd.num2 == 0)
            cd.begunInp = false;
    }
    else {
        if (cd.decimal) {
            cd.exp--;
            cd.num1 -= cd.lastInp * std::pow(10, -cd.exp);
            if (isInteger(cd.num1))
                cd.decimal = false;
        }
        else
            cd.num1 = (long)(cd.num1 / 10);
        
        if (cd.num1 == 0)
            cd.begunInp = false;
    }

    display(cd);
}

void doDecimal(CalcData &cd) {
    cd.decimal = true;
    cd.begunInp = true;
    cd.exp = 1;
    display(cd);
}

void doFunClick(CalcData &cd, cstr func, bool isTrig) {
    if (cd.solved)
        doClear(cd);

    if (cd.begunInp || cd.secondInp)
        return;
    
    cd.func = func;
    cd.funIsTrig = isTrig;
    display(cd);
}

void switchScreen(CalcData &cd, byte switchId, screenVar(0), screenVar(1), screenVar(2), screenVar(3)) {
    /*
    * bit - true / false
    *
    * Screen (also switch) id:
    * 
    * 0 (1s bit) - main / advanced screen
    * 1 (2s bit) - normal / inversed trig
    * 
    * Screen ids:
    * 
    * 0 - main screen
    * 1 - advanced screen
    * 2 - normal trig screen
    * 3 - inversed trig screen
    * 
    */
    if (switchId == 0) {
        // Switch to advanced sreen
        if (getNthBit(cd.selectedScreen, 0)) {
            cd.selectedScreen = setNthBit(cd.selectedScreen, 0, 0); // advanced
            cd.selectedScreen = setNthBit(cd.selectedScreen, 1, 1); // normal trig
        }
        // Switch to main screen
        else
            cd.selectedScreen = 1; // main
    }
    else if (switchId == 1) {
        // Switch to inversed trig
        if (getNthBit(cd.selectedScreen, 1))
            cd.selectedScreen = setNthBit(cd.selectedScreen, 1, 0); // inversed trig
        // Switch to normal trig
        else
            cd.selectedScreen = setNthBit(cd.selectedScreen, 1, 1); // normal trig
    }

    updateScreens(cd, screen0, screen1, screen2, screen3);
}

void updateScreens(CalcData &cd, screenVar(0), screenVar(1), screenVar(2), screenVar(3)) {
    // Main / Advanced screen
    if (getNthBit(cd.selectedScreen, 0)) {
        showScreen(0);

        hideScreen(1);
        hideScreen(2);
        hideScreen(3);
        return;
    }
    else {
        showScreen(1);
        hideScreen(0);
    }
    // Normal / Inversed trig
    if (getNthBit(cd.selectedScreen, 1)) {
        showScreen(2);
        hideScreen(3);
    }
    else {
        showScreen(3);
        hideScreen(2);
    }
}

void switchAngleType(CalcData &cd, Button &btnAng) {
    cd.degrees = !cd.degrees;
    if (cd.degrees)
        btnAng.setLabel("deg");
    else
        btnAng.setLabel("rad");
}

void doConstant(CalcData &cd, const double val, cstr disp) {
    if (cd.begunInp)
        return;
    
    cd.begunInp = true;
    cd.canInput = false;
    
    if (cd.func != "")
        cd.num1 = val;
    else {
        if (cd.secondInp) {
            cd.num2 = val;
            cd.con2 = disp;
        }
        else {
            cd.num1 = val;
            cd.con1 = disp;
        }
    }
    display(cd);
}

void doOneOver(CalcData &cd) {
    doOpClick(cd, '/');
    cd.secondInp = true;
    cd.begunInp = true;
    cd.num2 = cd.num1;
    cd.num1 = 1.0;
    if (cd.con1 != "") {
        cd.con2 = cd.con1;
        cd.con1 = "";
    }
    display(cd);
}


int main(int argc, cstr *argv) {
    uint shader, textShader;
    Window window;

    if (init(
            324, 484, "Goofy ahh calculator", false, window
        )) return -1;
    
    shader = makeShader(shaderPath("main.vert"), shaderPath("main.frag"));
    textShader = makeShader(shaderPath("text.vert"), shaderPath("text.frag"));

    glm::mat4 projection = glm::ortho(0.0f, (float)window.width, 0.0f, (float)window.height);
    glUseProgram(textShader);
    glUniformMatrix4fv(glGetUniformLocation(textShader, "model"), 1, GL_FALSE, glm::value_ptr(projection));

    makeFont(normalBtnFont, "arial", 54);
    makeFont(smallBtnFont, "arial", 28);
    makeFont(dispFont, "arial", 32);

    ButtonType normalBtn = {
        loadTexture(texPath("button.png")),
        true,
        loadTexture(texPath("button_hover.png")),
        true,
        loadTexture(texPath("button_pressed.png")),
        normalBtnFont,
        { 0.0f, 0.0f, 0.0f },
        { 80.0f, 80.0f },
        window,
        shader, textShader,
        GLFW_MOUSE_BUTTON_LEFT,
        true
    };

    ButtonType normalBtnMidFont = {
        loadTexture(texPath("button.png")),
        true,
        loadTexture(texPath("button_hover.png")),
        true,
        loadTexture(texPath("button_pressed.png")),
        dispFont,
        { 0.0f, 0.0f, 0.0f },
        { 80.0f, 80.0f },
        window,
        shader, textShader,
        GLFW_MOUSE_BUTTON_LEFT,
        true
    };

    ButtonType smallBtn = {
        loadTexture(texPath("small_button.png")),
        true,
        loadTexture(texPath("small_button_hover.png")),
        true,
        loadTexture(texPath("small_button_pressed.png")),
        smallBtnFont,
        { 0.0f, 0.0f, 0.0f },
        { 80.0f, 40.0f },
        window,
        shader, textShader,
        GLFW_MOUSE_BUTTON_LEFT,
        true
    };

    std::vector<ref(Button)> buttons;

    screenVar(0);
    screenVar(1);
    screenVar(2);
    screenVar(3);

    // Screen 0
    addButtonScreen(0, 0,   normalBtn,  "0",   -15.0f, -20.0f,   -40.0f,  -200.0f);
    addButtonScreen(0, 1,   normalBtn,  "1",   -15.0f, -20.0f,   -120.0f,  40.0f);
    addButtonScreen(0, 2,   normalBtn,  "2",   -15.0f, -20.0f,   -40.0f,   40.0f);
    addButtonScreen(0, 3,   normalBtn,  "3",   -15.0f, -20.0f,    40.0f,   40.0f);
    addButtonScreen(0, 4,   normalBtn,  "4",   -15.0f, -20.0f,   -120.0f, -40.0f);
    addButtonScreen(0, 5,   normalBtn,  "5",   -15.0f, -20.0f,   -40.0f,  -40.0f);
    addButtonScreen(0, 6,   normalBtn,  "6",   -15.0f, -20.0f,    40.0f,  -40.0f);
    addButtonScreen(0, 7,   normalBtn,  "7",   -15.0f, -20.0f,   -120.0f, -120.0f);
    addButtonScreen(0, 8,   normalBtn,  "8",   -15.0f, -20.0f,   -40.0f,  -120.0f);
    addButtonScreen(0, 9,   normalBtn,  "9",   -15.0f, -20.0f,    40.0f,  -120.0f);

    addButtonScreen(0, Sum, normalBtn,  "+",   -15.0f, -20.0f,    120.0f, -120.0f);
    addButtonScreen(0, Sub, normalBtn,  "-",   -7.5f,  -20.0f,    120.0f, -40.0f);
    addButtonScreen(0, Mul, normalBtn,  "*",   -10.0f, -20.0f,    120.0f,  40.0f);
    addButtonScreen(0, Div, normalBtn,  "/",   -7.5f,  -20.0f,    120.0f,  120.0f);

    addButtonScreen(0, Res, normalBtn,  "=",   -15.0f, -20.0f,    120.0f, -200.0f);
    addButtonScreen(0, Com, normalBtn,  ",",   -10.0f, -20.0f,    40.0f,  -200.0f);
    addButtonScreen(0, Sgn, normalBtn,  "+/-", -35.0f, -20.0f,   -120.0f, -200.0f);

    addButtonScreen(0, Clr, normalBtn,  "C",   -20.0f, -20.0f,   -40.0f,   120.0f);
    addButtonScreen(0, Del, normalBtn,  "<",   -15.0f, -20.0f,    40.0f,   120.0f);

    addButton(Scr, normalBtn,  "<=",  -30.0f, -20.0f,   -120.0f,  120.0f);

    // Screen 1
    addButtonScreen(1, Ang, normalBtnMidFont, "deg", -25.0f, -15.0f,   -40.0f,  120.0f);

    addButtonScreen(1, Inv, normalBtnMidFont, "inv", -20.0f, -15.0f,    120.0f,  120.0f);
    addButtonScreen(1, Pi,  normalBtnMidFont, "pi",  -12.5f, -15.0f,    40.0f,  120.0f);
    addButtonScreen(1, Eul, normalBtn,        "e",   -15.0f, -15.0f,    120.0f, -80.0f);

    addButtonScreen(1, Sqrt, smallBtn,  "sqrt",  -25.0f, -10.0f,   -120.0f, -20.0f);
    addButtonScreen(1, Cbrt, smallBtn,  "cbrt",  -25.0f, -10.0f,   -40.0f,  -20.0f);
    addButtonScreen(1, Lg,   smallBtn,  "lg",    -12.5f, -10.0f,    40.0f,  -20.0f);
    addButtonScreen(1, Ln,   smallBtn,  "ln",    -12.5f, -10.0f,    120.0f, -20.0f);

    addButtonScreen(1, Pow, normalBtn,  "^",   -12.5f, -20.0f,   -120.0f,  -80.0f);
    addButtonScreen(1, Mod, normalBtn,  "%",   -22.5f, -20.0f,   -40.0f,   -80.0f);
    addButtonScreen(1, Oneover, normalBtnMidFont,  "1/x", -22.5f, -15.0f,    40.0f,   -80.0f);

    // Screen 2
    addButtonScreen(2, Sin, smallBtn,  "sin",  -17.5f, -10.0f,   -120.0f,  60.0f);
    addButtonScreen(2, Cos, smallBtn,  "cos",  -22.5f, -10.0f,   -40.0f,   60.0f);
    addButtonScreen(2, Tan, smallBtn,  "tan",  -20.0f, -10.0f,    40.0f,   60.0f);
    addButtonScreen(2, Cot, smallBtn,  "cot",  -20.0f, -10.0f,    120.0f,  60.0f);

    addButtonScreen(2, Sinh, smallBtn,  "sinh",  -26.0f, -10.0f,   -120.0f,  20.0f);
    addButtonScreen(2, Cosh, smallBtn,  "cosh",  -31.0f, -10.0f,   -40.0f,   20.0f);
    addButtonScreen(2, Tanh, smallBtn,  "tanh",  -26.0f, -10.0f,    40.0f,   20.0f);
    addButtonScreen(2, Coth, smallBtn,  "coth",  -26.0f, -10.0f,    120.0f,  20.0f);

    // Screen 3
    addButtonScreen(3, Asin, smallBtn, "asin", -26.0f, -10.0f,   -120.0f,  60.0f);
    addButtonScreen(3, Acos, smallBtn, "acos", -31.0f, -10.0f,   -40.0f,   60.0f);
    addButtonScreen(3, Atan, smallBtn, "atan", -26.0f, -10.0f,    40.0f,   60.0f);
    addButtonScreen(3, Acot, smallBtn, "acot", -26.0f, -10.0f,    120.0f,  60.0f);

    addButtonScreen(3, Asinh, smallBtn, "asinh", -32.5f, -10.0f,   -120.0f,  20.0f);
    addButtonScreen(3, Acosh, smallBtn, "acosh", -37.5f, -10.0f,   -40.0f,   20.0f);
    addButtonScreen(3, Atanh, smallBtn, "atanh", -32.5f, -10.0f,    40.0f,   20.0f);
    addButtonScreen(3, Acoth, smallBtn, "acoth", -32.5f, -10.0f,    120.0f,  20.0f);

    hideScreen(1);
    hideScreen(2);
    hideScreen(3);

    Text txtRes(dispFont, { -150.0f, 190.0f }, 1.0f, { 0.0f, 0.0f, 0.0f }, textShader, window);
    Text comingSoon(normalBtnFont, { -130.0f, -190.0f }, 0.8f, { 0.0f, 0.0f, 0.0f }, textShader, window);
    comingSoon.setText("Coming soon");

    CalcData cd = {
        txtRes,
        0.0, 0.0, ' ', "", "", "",
        false, false, false, false, true, false, true,
        1, 0,
        0b00000001
    };
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window.glWin)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        // Render sprites
        for (ref(Button) btn : buttons)
            btn.get().draw();

        txtRes.draw();
        if (!getNthBit(cd.selectedScreen, 0))
            comingSoon.draw();

        // Button events
        // Screen switches
        onBtnClick(Scr, switchScreen, cd, 0, screen0, screen1, screen2, screen3);
        onBtnClick(Inv, switchScreen, cd, 1, screen0, screen1, screen2, screen3);
        onBtnClick(Ang, switchAngleType, cd, btnAng);

        // Screen 0
        onBtnClick(0, doNumClick, cd, 0);
        onBtnClick(1, doNumClick, cd, 1);
        onBtnClick(2, doNumClick, cd, 2);
        onBtnClick(3, doNumClick, cd, 3);
        onBtnClick(4, doNumClick, cd, 4);
        onBtnClick(5, doNumClick, cd, 5);
        onBtnClick(6, doNumClick, cd, 6);
        onBtnClick(7, doNumClick, cd, 7);
        onBtnClick(8, doNumClick, cd, 8);
        onBtnClick(9, doNumClick, cd, 9);

        onBtnClick(Sum, doOpClick, cd, '+');
        onBtnClick(Sub, doOpClick, cd, '-');
        onBtnClick(Mul, doOpClick, cd, '*');
        onBtnClick(Div, doOpClick, cd, '/');

        onBtnClick(Res, doSolve, cd);
        onBtnClick(Com, doDecimal, cd);
        onBtnClick(Sgn, doSign, cd);

        onBtnClick(Del, doErase, cd);
        onBtnClick(Clr, doClear, cd);

        // Screen 1
        onBtnClick(Pi, doConstant, cd, M_PI, "pi");
        onBtnClick(Eul, doConstant, cd, M_E, "e");

        onBtnClick(Sqrt, doFunClick, cd, "sqrt", false);
        onBtnClick(Cbrt, doFunClick, cd, "cbrt", false);
        onBtnClick(Lg, doFunClick, cd, "lg", false);

        onBtnClick(Pow, doOpClick, cd, '^');
        onBtnClick(Mod, doOpClick, cd, '%');
        onBtnClick(Oneover, doOneOver, cd);

        // Screen 2
        onBtnClick(Sin, doFunClick, cd, "sin", true);
        onBtnClick(Cos, doFunClick, cd, "cos", true);
        onBtnClick(Tan, doFunClick, cd, "tan", true);
        onBtnClick(Cot, doFunClick, cd, "cot", true);
        onBtnClick(Sinh, doFunClick, cd, "sinh", true);
        onBtnClick(Cosh, doFunClick, cd, "cosh", true);
        onBtnClick(Tanh, doFunClick, cd, "tanh", true);
        onBtnClick(Coth, doFunClick, cd, "coth", true);

        // Screen 3
        onBtnClick(Asin, doFunClick, cd, "asin", true);
        onBtnClick(Acos, doFunClick, cd, "acos", true);
        onBtnClick(Atan, doFunClick, cd, "atan", true);
        onBtnClick(Acot, doFunClick, cd, "acot", true);
        onBtnClick(Asinh, doFunClick, cd, "asinh", true);
        onBtnClick(Acosh, doFunClick, cd, "acosh", true);
        onBtnClick(Atanh, doFunClick, cd, "atanh", true);
        onBtnClick(Acoth, doFunClick, cd, "acoth", true);

        glfwSwapBuffers(window.glWin);
        if (glfwGetKey(window.glWin, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            break;
    }

    closeOpenGL({ shader, textShader }, window);

    return 0;
}
