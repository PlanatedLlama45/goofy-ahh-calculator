#include "main.hpp"

void display(CalcData &cd) {
    if (!cd.secondInp && !cd.begunInp && cd.func == "") {
        cd.txtRes.setText("");
        return;
    }

    std::stringstream disp;

    if (cd.func != "") {
        disp << cd.func << '(';
        if (cd.begunInp)
            disp << cd.num1;
        disp << ')';
    }
    else if (!cd.secondInp)
        disp << cd.num1;
    else if (!cd.begunInp)
        disp << cd.num1 << cd.op;
    else {
        if (cd.num2 < 0.0)
            disp << cd.num1 << cd.op << '(' << cd.num2 << ')';
        else
            disp << cd.num1 << cd.op << cd.num2;
    }
    
    cd.txtRes.setText(disp.str());
}

void doNumClick(CalcData &cd, int btn) {
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
    display(cd);
}

void doClear(CalcData &cd) {
    cd.num1 = 0.0;
    cd.num2 = 0.0;
    cd.op = ' ';
    cd.func = "";
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
        default: return;
        }
    else {
        if (cd.func == "sin")
            cd.num1 = std::sin(deg2rad(cd.num1));
        else if (cd.func == "cos")
            cd.num1 = std::cos(deg2rad(cd.num1));
        else if (cd.func == "tan")
            cd.num1 = std::tan(deg2rad(cd.num1));
        else if (cd.func == "cot")
            cd.num1 = 1.0 / std::tan(deg2rad(cd.num1));
    }

    cd.num2 = 0;
    cd.op = ' ';
    cd.func = "";
    cd.begunInp = true;
    cd.secondInp = false;
    cd.solved = true;
    cd.decimal = false;

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

void doFunClick(CalcData &cd, cstr func) {
    if (cd.solved)
        doClear(cd);

    if (cd.begunInp || cd.secondInp)
        return;
    
    cd.func = func;
    display(cd);
}


int main(int argc, cstr *argv) {
    uint shader, textShader;
    Window window;

    if (init(
            324, 524, "Goofy ahh calculator", false, &window
        )) return -1;
    
    shader = makeShader(shaderPath("main.vert"), shaderPath("main.frag"));
    textShader = makeShader(shaderPath("text.vert"), shaderPath("text.frag"));

    glm::mat4 projection = glm::ortho(0.0f, (float)window.width, 0.0f, (float)window.height);
    glUseProgram(textShader);
    glUniformMatrix4fv(glGetUniformLocation(textShader, "model"), 1, GL_FALSE, glm::value_ptr(projection));

    makeFont(btnFont, "arial", 54);
    makeFont(smallBtnFont, "arial", 32);

    ButtonType normalBtn = {
        btnFont,
        { 0.0f, 0.0f, 0.0f },
        true, true,
        loadTexture(texPath("button.png")),
        loadTexture(texPath("button_hover.png")),
        loadTexture(texPath("button_pressed.png")),
        { 80.0f, 80.0f },
        window,
        shader, textShader,
        GLFW_MOUSE_BUTTON_LEFT
    };

    ButtonType smallBtn = {
        smallBtnFont,
        { 0.0f, 0.0f, 0.0f },
        true, true,
        loadTexture(texPath("small_button.png")),
        loadTexture(texPath("small_button_hover.png")),
        loadTexture(texPath("small_button_pressed.png")),
        { 80.0f, 40.0f },
        window,
        shader, textShader,
        GLFW_MOUSE_BUTTON_LEFT
    };

    std::vector<ref(Button)> buttons;

    addButton(0,   normalBtn,  "0",    -15.0f,   -20.0f,    -40.0f,  -220.0f);
    addButton(1,   normalBtn,  "1",    -15.0f,   -20.0f,    -120.0f,  20.0f);
    addButton(2,   normalBtn,  "2",    -15.0f,   -20.0f,    -40.0f,   20.0f);
    addButton(3,   normalBtn,  "3",    -15.0f,   -20.0f,     40.0f,   20.0f);
    addButton(4,   normalBtn,  "4",    -15.0f,   -20.0f,    -120.0f, -60.0f);
    addButton(5,   normalBtn,  "5",    -15.0f,   -20.0f,    -40.0f,  -60.0f);
    addButton(6,   normalBtn,  "6",    -15.0f,   -20.0f,     40.0f,  -60.0f);
    addButton(7,   normalBtn,  "7",    -15.0f,   -20.0f,    -120.0f, -140.0f);
    addButton(8,   normalBtn,  "8",    -15.0f,   -20.0f,    -40.0f,  -140.0f);
    addButton(9,   normalBtn,  "9",    -15.0f,   -20.0f,     40.0f,  -140.0f);

    addButton(Sum, normalBtn,  "+",    -15.0f,   -20.0f,     120.0f, -140.0f);
    addButton(Sub, normalBtn,  "-",    -7.5f,    -20.0f,     120.0f, -60.0f);
    addButton(Mul, normalBtn,  "*",    -10.0f,   -20.0f,     120.0f,  20.0f);
    addButton(Div, normalBtn,  "/",    -7.5f,    -20.0f,     120.0f,  100.0f);
    addButton(Pow, normalBtn,  "^",    -12.5f,   -20.0f,     40.0f,   100.0f);

    addButton(Res, normalBtn,  "=",    -15.0f,   -20.0f,     120.0f, -220.0f);
    addButton(Com, normalBtn,  ",",    -10.0f,   -20.0f,     40.0f,  -220.0f);
    addButton(Sgn, normalBtn,  "+/-",  -35.0f,   -20.0f,    -120.0f, -220.0f);

    addButton(Clr, normalBtn,  "C",    -20.0f,   -20.0f,    -120.0f,  100.0f);
    addButton(Del, normalBtn,  "<",    -15.0f,   -20.0f,    -40.0f,   100.0f);

    addButton(Sin, smallBtn,   "sin",  -22.5f,   -10.0f,    -120.0f,  160.0f);
    addButton(Cos, smallBtn,   "cos",  -25.0f,   -10.0f,    -40.0f,   160.0f);
    addButton(Tan, smallBtn,   "tan",  -22.5f,   -10.0f,     40.0f,   160.0f);
    addButton(Cot, smallBtn,   "cot",  -22.5f,   -10.0f,     120.0f,  160.0f);

    Text txtRes(smallBtnFont, { -150.0f, 210.0f }, 1.0f, { 0.0f, 0.0f, 0.0f }, textShader, window);

    CalcData cd = {
        txtRes,
        0.0, 0.0, ' ', "",
        false, false, false, false,
        1, 0
    };
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window.glWin)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        // draw shit
        for (ref(Button) btn : buttons)
            btn.get().draw();

        txtRes.draw();

        // do button pressing shit
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
        onBtnClick(Pow, doOpClick, cd, '^');

        onBtnClick(Res, doSolve, cd);
        onBtnClick(Com, doDecimal, cd);
        onBtnClick(Sgn, doSign, cd);

        onBtnClick(Del, doErase, cd);
        onBtnClick(Clr, doClear, cd);

        onBtnClick(Sin, doFunClick, cd, "sin");
        onBtnClick(Cos, doFunClick, cd, "cos");
        onBtnClick(Tan, doFunClick, cd, "tan");
        onBtnClick(Cot, doFunClick, cd, "cot");

        glfwSwapBuffers(window.glWin);
        if (glfwGetKey(window.glWin, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            break;
    }

    closeOpenGL(shader);

    return 0;
}
