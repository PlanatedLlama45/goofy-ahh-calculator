#include "config.hpp"
#include "maintenance.hpp"
#include "sprite.hpp"
#include "text.hpp"

constexpr int maxNum = INT_MAX / 10;

struct CalcData {
    Text &txtRes;

    double num1;
    double num2;
    char op;

    bool begunInp;
    bool secondInp;
    bool solved;
    bool decimal;

    int exp;
    byte lastInp;
};

inline bool isInteger(double num) { return num == (double)(int)num; }

extern void display(CalcData &cd);
extern void doNumClick(int btn, CalcData &cd);
extern void doOpClick(char btn, CalcData &cd);
extern void doClear(CalcData &cd);
extern void doSolve(CalcData &cd);
extern void doSign(CalcData &cd);
inline void doDecimal(CalcData &cd) { cd.decimal = true; cd.exp = 1; }
extern void doErase(CalcData &cd);

extern int main(int argc, cstr *argv);
