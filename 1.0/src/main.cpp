#include "main.hpp"

void display(CalcData &cd) {
    if (!cd.secondInp && !cd.begunInp) {
        cd.txtRes.setText("");
        return;
    }

    std::stringstream disp;

    if (!cd.secondInp)
        disp << cd.num1;
    else if (!cd.begunInp)
        disp << cd.num1 << cd.op;
    else {
        if (cd.num2 < 0)
            disp << cd.num1 << cd.op << '(' << cd.num2 << ')';
        else
            disp << cd.num1 << cd.op << cd.num2;
    }
    
    cd.txtRes.setText(disp.str());
}

void doNumClick(int btn, CalcData &cd) {
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

void doOpClick(char btn, CalcData &cd) {
    if (!cd.begunInp && cd.secondInp)
        return;
    
    cd.op = btn;
    cd.begunInp = false;
    cd.secondInp = true;
    cd.solved = false;
    cd.decimal = false;
    display(cd);
}

void doClear(CalcData &cd) {
    cd.num1 = 0;
    cd.num2 = 0;
    cd.begunInp = false;
    cd.secondInp = false;
    cd.solved = false;

    display(cd);
}

void doSolve(CalcData &cd) {
    if (!cd.begunInp || !cd.secondInp)
        return;

    switch (cd.op)
    {
    case '+': cd.num1 = cd.num1 + cd.num2; break;
    case '-': cd.num1 = cd.num1 - cd.num2; break;
    case '*': cd.num1 = cd.num1 * cd.num2; break;
    case '/': cd.num1 = cd.num1 / cd.num2; break;
    case '%': cd.num1 = std::fmod(cd.num1, cd.num2); break;
    default: return;
    }

    cd.num2 = 0;
    cd.op = ' ';
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
    if (!cd.begunInp)
        return;
    
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


int main(int argc, cstr *argv) {
    uint shader, textShader;
    Window window;

    if (init(
            324, 484, "Goofy ahh calculator", false, &window
        )) return -1;
    
    shader = makeShader("../src/shaders/main.vert", "../src/shaders/main.frag");
    textShader = makeShader("../src/shaders/text.vert", "../src/shaders/text.frag");

    glm::mat4 projection = glm::ortho(0.0f, (float)window.width, 0.0f, (float)window.height);
    glUseProgram(textShader);
    glUniformMatrix4fv(glGetUniformLocation(textShader, "model"), 1, GL_FALSE, glm::value_ptr(projection));

    Font fontBtn;
    if (fontBtn.load("../fonts/arial.ttf", 54))
        return -1;
    
    Font fontDisp;
    if (fontDisp.load("../fonts/arial.ttf", 32))
        return -1;

    Button btn0("../img/button.png", "0", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -40.0f, -200.0f }, window, shader, textShader);
    Button btn1("../img/button.png", "1", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -120.0f, 40.0f }, window, shader, textShader);
    Button btn2("../img/button.png", "2", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -40.0f, 40.0f }, window, shader, textShader);
    Button btn3("../img/button.png", "3", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { 40.0f, 40.0f }, window, shader, textShader);
    Button btn4("../img/button.png", "4", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -120.0f, -40.0f }, window, shader, textShader);
    Button btn5("../img/button.png", "5", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -40.0f, -40.0f }, window, shader, textShader);
    Button btn6("../img/button.png", "6", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { 40.0f, -40.0f }, window, shader, textShader);
    Button btn7("../img/button.png", "7", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -120.0f, -120.0f }, window, shader, textShader);
    Button btn8("../img/button.png", "8", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { -40.0f, -120.0f }, window, shader, textShader);
    Button btn9("../img/button.png", "9", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { 40.0f, -120.0f }, window, shader, textShader);

    Button btnSum("../img/button.png", "+", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { 120.0f, -120.0f }, window, shader, textShader);
    Button btnSub("../img/button.png", "-", fontBtn, { 0.0f, 0.0f, 0.0f }, { -90.0f, 60.0f }, { 80.0f, 80.0f }, { 120.0f, -40.0f }, window, shader, textShader);
    Button btnMul("../img/button.png", "*", fontBtn, { 0.0f, 0.0f, 0.0f }, { -90.0f, 60.0f }, { 80.0f, 80.0f }, { 120.0f, 40.0f }, window, shader, textShader);
    Button btnDiv("../img/button.png", "/", fontBtn, { 0.0f, 0.0f, 0.0f }, { -90.0f, 60.0f }, { 80.0f, 80.0f }, { 120.0f, 120.0f }, window, shader, textShader);
    Button btnMod("../img/button.png", "%", fontBtn, { 0.0f, 0.0f, 0.0f }, { -102.5f, 60.0f }, { 80.0f, 80.0f }, { 40.0f, 120.0f }, window, shader, textShader);

    Button btnRes("../img/button.png", "=", fontBtn, { 0.0f, 0.0f, 0.0f }, { -95.0f, 60.0f }, { 80.0f, 80.0f }, { 120.0f, -200.0f }, window, shader, textShader);
    Button btnCom("../img/button.png", ",", fontBtn, { 0.0f, 0.0f, 0.0f }, { -90.0f, 60.0f }, { 80.0f, 80.0f }, { 40.0f, -200.0f }, window, shader, textShader);
    Button btnSgn("../img/button.png", "+/-", fontBtn, { 0.0f, 0.0f, 0.0f }, { -112.5f, 60.0f }, { 80.0f, 80.0f }, { -120.0f, -200.0f }, window, shader, textShader);

    Button btnClr("../img/button.png", "C", fontBtn, { 0.0f, 0.0f, 0.0f }, { -100.0f, 60.0f }, { 80.0f, 80.0f }, { -120.0f, 120.0f }, window, shader, textShader);
    Button btnDel("../img/button.png", "<", fontBtn, { 0.0f, 0.0f, 0.0f }, { -100.0f, 60.0f }, { 80.0f, 80.0f }, { -40.0f, 120.0f }, window, shader, textShader);

    Text txtRes(fontDisp, { -220.0f, 265.0f }, 1.0f, { 0.0f, 0.0f, 0.0f }, textShader, window);
    txtRes.setText("");

    CalcData cd = {
        txtRes,
        0, 0, ' ',
        false, false, false, false,
        1, 0
    };

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window.glWin)) {
        glfwPollEvents();

        // draw shit
        glClear(GL_COLOR_BUFFER_BIT);

        btn0.draw();
        btn1.draw();
        btn2.draw();
        btn3.draw();
        btn4.draw();
        btn5.draw();
        btn6.draw();
        btn7.draw();
        btn8.draw();
        btn9.draw();

        btnSum.draw();
        btnSub.draw();
        btnMul.draw();
        btnDiv.draw();
        btnMod.draw();

        btnRes.draw();
        btnCom.draw();
        btnSgn.draw();

        btnDel.draw();
        btnClr.draw();

        txtRes.draw();

        // do button pressing shit
        if (btn0.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(0, cd);
        if (btn1.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(1, cd);
        if (btn2.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(2, cd);
        if (btn3.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(3, cd);
        if (btn4.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(4, cd);
        if (btn5.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(5, cd);
        if (btn6.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(6, cd);
        if (btn7.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(7, cd);
        if (btn8.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(8, cd);
        if (btn9.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doNumClick(9, cd);
        
        if (btnSum.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doOpClick('+', cd);
        if (btnSub.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doOpClick('-', cd);
        if (btnMul.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doOpClick('*', cd);
        if (btnDiv.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doOpClick('/', cd);
        if (btnMod.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doOpClick('%', cd);
        
        if (btnRes.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doSolve(cd);
        if (btnCom.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doDecimal(cd);
        if (btnSgn.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doSign(cd);
        
        if (btnDel.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doErase(cd);
        if (btnClr.isClicked(GLFW_MOUSE_BUTTON_LEFT))
            doClear(cd);

        glfwSwapBuffers(window.glWin);
        if (glfwGetKey(window.glWin, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            break;
    }

    closeOpenGL(shader);

    return 0;
}
