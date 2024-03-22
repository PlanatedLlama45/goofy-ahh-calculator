#include "ast.hpp"

// Base_AST

Base_AST::Base_AST()
{}

Base_AST::~Base_AST()
{}

double Base_AST::applyFunction(cstr fun, double arg) {
    // Algebra / Calculus
    if (fun == "lg")
        return std::log10(arg);
    else if (fun == "ln")
        return std::log(arg);

    // Trig
    // Normal trig
    else if (fun == "sin")
        return std::sin(arg);
    else if (fun == "cos")
        return std::cos(arg);
    else if (fun == "tan" || fun == "tg")
        return std::tan(arg);

    // Complements
    else if (fun == "csc" || fun == "cosec")
        return 1.0 / std::sin(arg);
    else if (fun == "sec")
        return 1.0 / std::cos(arg);
    else if (fun == "cot" || fun == "ctg" || fun == "cotan")
        return 1.0 / std::tan(arg);

    // Hyperbolic trig
    else if (fun == "sinh" || fun == "sh")
        return std::sinh(arg);
    else if (fun == "cosh" || fun == "ch")
        return std::cosh(arg);
    else if (fun == "tanh" || fun == "th")
        return std::tanh(arg);

    // Complements    
    else if (fun == "csch" || fun == "cosech")
        return 1.0 / std::sinh(arg);
    else if (fun == "sech" || fun == "sch")
        return 1.0 / std::cosh(arg);
    else if (fun == "coth" || fun == "cth")
        return 1.0 / std::tanh(arg);

    // Inverse trig
    // Normal trig
    else if (fun == "arcsin")
        return std::asin(arg);
    else if (fun == "arccos")
        return std::acos(arg);
    else if (fun == "arctan" || fun == "arctg")
        return std::tan(arg);

    // Complements
    else if (fun == "csc" || fun == "cosec")
        return 1.0 / std::sin(arg);
    else if (fun == "sec")
        return 1.0 / std::cos(arg);
    else if (fun == "arccot" || fun == "arcctg" || fun == "arccotan")
        return 1.0 / std::tan(arg);

    // Hyperbolic trig
    else if (fun == "arsinh" || fun == "arsh")
        return std::asinh(arg);
    else if (fun == "arcosh" || fun == "arch")
        return std::acosh(arg);
    else if (fun == "artanh" || fun == "arth")
        return std::atanh(arg);

    // Complements    
    else if (fun == "arcsch" || fun == "cosech")
        return std::asinh(1.0 / arg);
    else if (fun == "arsech" || fun == "arsch")
        return std::acosh(1.0 / arg);
    else if (fun == "arcoth" || fun == "arcth")
        return std::atanh(1.0 / arg);

    return 0.0;
}

double Base_AST::applyFunction(cstr fun, double arg1, double arg2) {
    // Arithmetic
    if (fun == "+")
        return arg1 + arg2;
    else if (fun == "-")
        return arg1 - arg2;
    else if (fun == "*")
        return arg1 * arg2;
    else if (fun == "/")
        return arg1 / arg2;
    else if (fun == "^")
        return std::pow(arg1, arg2);

    // Algebra / Calculus
    else if (fun == "log")
        return std::log(arg2) / std::log(arg1);
    else if (fun == "root")
        return std::pow(arg2, 1.0 / arg1);

    // Combinatorics / number theory
    else if (fun == "nCr" || fun == "ncr")
        return nCr(arg1, arg2);
    else if (fun == "nPr" || fun == "npr")
        return nCr(arg1, arg2);

    return 0.0;
}


// Value_AST

Value_AST::Value_AST(double value) {
    this->value = value;
}

Value_AST::~Value_AST() { }

double Value_AST::getValue() {
    return value;
}

void Value_AST::display(std::stringstream &ss) {
    ss << value;
}

AST_Type Value_AST::getType() const {
    return AST_Type::Value;
}


// Const_AST

Const_AST::Const_AST(double value, cstr text) {
    this->value = value;
    this->text = text;
}

Const_AST::~Const_AST()
{}

double Const_AST::getValue() {
    return value;
}

void Const_AST::display(std::stringstream &ss) {
    ss << text;
}

AST_Type Const_AST::getType() const {
    return AST_Type::Const;
}


// Function_AST

Unary_AST::Unary_AST(cstr function, Base_AST *inner) {
    this->function = function;
    this->inner = inner;
}

Unary_AST::~Unary_AST() {
    delete inner;
}

double Unary_AST::getValue() {
    return Base_AST::applyFunction(function, inner->getValue());
}

void Unary_AST::display(std::stringstream &ss) {
    ss << function << '(';
    inner->display(ss);
    ss << ")";
}

AST_Type Unary_AST::getType() const {
    return AST_Type::Unary;
}

Base_AST *&Unary_AST::getInner() {
    return inner;
}

void Unary_AST::setInner(Base_AST *ast, bool del) {
    if (del)
        delete inner;
    inner = ast;
}

// Operator_AST

Binary_AST::Binary_AST(cstr operation, Base_AST *first, Base_AST *second, Style style) {
    this->operation = operation;
    this->first = first;
    this->second = second;
    this->style = style;
}

Binary_AST::~Binary_AST() {
    delete first;
    delete second;
}

double Binary_AST::getValue() {
    return Base_AST::applyFunction(operation, first->getValue(), second->getValue());
}

void Binary_AST::display(std::stringstream &ss) {
    if (style == Style::Function) {
        ss << operation << '(';
        if (first)
            first->display(ss);
        ss << ", ";
        if (second)
            second->display(ss);
        ss << ')';
    } else {
        if (first)
            first->display(ss);
        ss << operation;
        if (second)
            second->display(ss);
    }
}

AST_Type Binary_AST::getType() const {
    return AST_Type::Binary;
}

Base_AST *&Binary_AST::getFirst() {
    return first;
}

Base_AST *&Binary_AST::getSecond() {
    return second;
}

void Binary_AST::setFirst(Base_AST *ast, bool del) {
    if (del)
        delete first;
    first = ast;
}

void Binary_AST::setSecond(Base_AST *ast, bool del) {
    if (del)
        delete second;
    second = ast;
}

Binary_AST::Style Binary_AST::getStyle() const {
    return style;
}

bool Binary_AST::getSecondBegun() const {
    return secondBegun;
}

void Binary_AST::setSecondBegun(bool val) {
    secondBegun = val;
}
