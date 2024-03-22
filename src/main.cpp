#include "main.hpp"

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

    std::vector<Button *> buttons;

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
    comingSoon.setHidden(true);

    CalcData cd = {
        txtRes,
        { },
        0, 1,
        0, 0
    };
    // DO NOT touch
    cd.selectedScreen = 0b00000001;
    updateScreens(cd, screen0, screen1, screen2, screen3);
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window.glWin)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        // Render sprites
        for (Button *btn : buttons)
            btn->draw();

        txtRes.draw();
        if (!getNthBit(cd.selectedScreen, 0))
            comingSoon.draw();

        // Button events
        // Screen switches
        onBtnClick(Scr, switchScreen, cd, 0, screen0, screen1, screen2, screen3);
        onBtnClick(Inv, switchScreen, cd, 1, screen0, screen1, screen2, screen3);
        onBtnClick(Ang, switchAngleType, cd, btnAng);

        // Screen 0
        onBtnClick(0, updateCalc, cd, "0");
        onBtnClick(1, updateCalc, cd, "1");
        onBtnClick(2, updateCalc, cd, "2");
        onBtnClick(3, updateCalc, cd, "3");
        onBtnClick(4, updateCalc, cd, "4");
        onBtnClick(5, updateCalc, cd, "5");
        onBtnClick(6, updateCalc, cd, "6");
        onBtnClick(7, updateCalc, cd, "7");
        onBtnClick(8, updateCalc, cd, "8");
        onBtnClick(9, updateCalc, cd, "9");

        onBtnClick(Sum, updateCalc, cd, "op sum");
        onBtnClick(Sub, updateCalc, cd, "op sub");
        onBtnClick(Mul, updateCalc, cd, "op mul");
        onBtnClick(Div, updateCalc, cd, "op div");

        onBtnClick(Res, updateCalc, cd, "solve");
        onBtnClick(Com, updateCalc, cd, "decimal");
        onBtnClick(Sgn, updateCalc, cd, "sign");

        onBtnClick(Del, updateCalc, cd, "erase");
        onBtnClick(Clr, updateCalc, cd, "clear");

        // Screen 1
        onBtnClick(Pi, updateCalc, cd, "const pi");
        onBtnClick(Eul, updateCalc, cd, "const e");

        onBtnClick(Sqrt, updateCalc, cd, "fun sqrt");
        onBtnClick(Cbrt, updateCalc, cd, "fun cbrt");
        onBtnClick(Lg, updateCalc, cd, "fun lg");

        onBtnClick(Pow, updateCalc, cd, "op pow");
        onBtnClick(Mod, updateCalc, cd, "op mod");
        onBtnClick(Oneover, updateCalc, cd, "op oneover");

        // Screen 2
        onBtnClick(Sin, updateCalc, cd, "fun sin");
        onBtnClick(Cos, updateCalc, cd, "fun cos");
        onBtnClick(Tan, updateCalc, cd, "fun tan");
        onBtnClick(Cot, updateCalc, cd, "fun cot");
        onBtnClick(Sinh, updateCalc, cd, "fun sinh");
        onBtnClick(Cosh, updateCalc, cd, "fun cosh");
        onBtnClick(Tanh, updateCalc, cd, "fun tanh");
        onBtnClick(Coth, updateCalc, cd, "fun coth");

        // Screen 3
        onBtnClick(Asin, updateCalc, cd, "fun asin");
        onBtnClick(Acos, updateCalc, cd, "fun acos");
        onBtnClick(Atan, updateCalc, cd, "fun atan");
        onBtnClick(Acot, updateCalc, cd, "fun acot");
        onBtnClick(Asinh, updateCalc, cd, "fun asinh");
        onBtnClick(Acosh, updateCalc, cd, "fun acosh");
        onBtnClick(Atanh, updateCalc, cd, "fun atanh");
        onBtnClick(Acoth, updateCalc, cd, "fun acoth");

        glfwSwapBuffers(window.glWin);
        if (glfwGetKey(window.glWin, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            break;
    }

    deleteStack(cd.ast);
    closeOpenGL({ shader, textShader }, window);

    return 0;
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

void updateCalc(CalcData &cd, cstr code) {
    // Clear / erase
    if (code == "erase") {
        if (!cd.ast.empty()) {
            deleteStackTop(cd.ast);
            if (cd.decimal) {
                cd.exp--;
                if (cd.exp == 1)
                    cd.decimal = false;
            }
            updateDisplay(cd);
        }
        return;
    } else if (code == "clear") {
        deleteStack(cd.ast);
        cd.decimal = false;
        updateDisplay(cd);
        return;
    }
    Base_AST *prevAst = (!cd.ast.empty() ? cd.ast.top() : nullptr);
    // Numbers
    if (code[1] == '\0' && '0' <= code[0] && code[0] <= '9') {
        byte num = code[0] - '0';
        if (prevAst) {
            if (prevAst->getType() == AST_Type::Unary) {
                Unary_AST *u_prevAst = (Unary_AST *)prevAst;
                if (u_prevAst->getInner()->getType() == AST_Type::Value)
                    addNumToAST_Node((Value_AST *&)u_prevAst->getInner(), num, cd.decimal, cd.exp);
            } else if (prevAst->getType() == AST_Type::Binary) {
                Binary_AST *b_prevAst = (Binary_AST *)prevAst;
                if (b_prevAst->getStyle() == Binary_AST::Style::Function) {
                    if (b_prevAst->getSecondBegun())
                        addNumToAST_Node((Value_AST *&)b_prevAst->getSecond(), num, cd.decimal, cd.exp);
                    else
                        addNumToAST_Node((Value_AST *&)b_prevAst->getFirst(), num, cd.decimal, cd.exp);
                } else {
                    if (!b_prevAst->getSecond() || b_prevAst->getSecond()->getType() == AST_Type::Value)
                        addNumToAST_Node((Value_AST *&)b_prevAst->getSecond(), num, cd.decimal, cd.exp);
                }
            } else if (prevAst->getType() == AST_Type::Value)
                addNumToAST_Node((Value_AST *&)prevAst, num, cd.decimal, cd.exp);
        } else
            addNumToAST_Node((Value_AST *&)prevAst, num, cd.decimal, cd.exp);
    }
    // Radix point
    else if (code == "decimal" && !cd.decimal) {
        cd.decimal = true;
        cd.exp = 1;
    }
    // Simple operations
    else if (code[0] == 'o' && code[1] == 'p') {
        if (code == "op sum")
            prevAst = new Binary_AST("+", prevAst, nullptr, Binary_AST::Style::Operator);
        else if (code == "op sub")
            prevAst = new Binary_AST("-", prevAst, nullptr, Binary_AST::Style::Operator);
        else if (code == "op mul")
            prevAst = new Binary_AST("*", prevAst, nullptr, Binary_AST::Style::Operator);
        else if (code == "op div")
            prevAst = new Binary_AST("/", prevAst, nullptr, Binary_AST::Style::Operator);
        ((Binary_AST *)prevAst)->setSecondBegun(true);
        cd.decimal = false;
    }

    // Append to history
    if (prevAst)
        cd.ast.push(prevAst);

    updateDisplay(cd);
}

void updateDisplay(CalcData &cd) {
    if (cd.ast.empty()) {
        cd.txtRes.setText("");
        return;
    }
    std::stringstream ss;
    cd.ast.top()->display(ss);
    cd.txtRes.setText(ss.str());
}

void addNumToAST_Node(Value_AST *&ast, int num, bool decimal, uint16_t &exp) {
    if (ast) {
        double prev = ast->getValue();
        // delete ast;
        if (decimal) {
            ast = new Value_AST(prev + num / pow(10.0, exp));
            exp++;
        } else
            ast = new Value_AST(prev * 10 + num);
    } else {
        // delete ast;
        if (decimal) {
            ast = new Value_AST(num / 10.0);
            exp++;
        } else
            ast = new Value_AST(num);
    }
}
