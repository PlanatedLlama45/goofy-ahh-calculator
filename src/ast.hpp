#pragma once

#include "config.hpp"

class Base_AST {
public:
    Base_AST();
    ~Base_AST();

    virtual double getValue();
    virtual void display(std::stringstream &ss);

protected:
    static double applyFunction(cstr fun, double arg);
    static double applyFunction(cstr fun, double arg1, double arg2);

};


class Value_AST : public Base_AST {
public:
    Value_AST(double value);
    ~Value_AST();

    double getValue();
    void display(std::stringstream &ss);

private:
    double value;

};


class Const_AST : public Base_AST {
public:
    Const_AST(double value, cstr text);
    ~Const_AST();

    double getValue();
    void display(std::stringstream &ss);

private:
    double value;
    cstr text;

};


class Function_AST : public Base_AST {
public:
    Function_AST(cstr function, Base_AST *inner);
    ~Function_AST();

    double getValue();
    void display(std::stringstream &ss);

private:
    cstr function;
    Base_AST *inner;

};


class Operator_AST : public Base_AST {
public:
    enum class Style { Operator, Function };

    Operator_AST(cstr operation, Base_AST *first, Base_AST *second, Style style);
    ~Operator_AST();

    double getValue();
    void display(std::stringstream &ss);

private:
    cstr operation;
    Base_AST *first, *second;
    Style style;

};

