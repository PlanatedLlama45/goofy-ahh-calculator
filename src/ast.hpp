#pragma once

#include "config.hpp"

enum class AST_Type { Value, Const, Unary, Binary };

class Base_AST {
public:
    Base_AST();
    ~Base_AST();

    virtual double getValue() = 0;
    virtual void display(std::stringstream &ss) = 0;
    virtual AST_Type getType() const = 0;

protected:
    static double applyFunction(cstr fun, double arg);
    static double applyFunction(cstr fun, double arg1, double arg2);

};


class Value_AST : public Base_AST {
public:
    Value_AST(double value);
    ~Value_AST();

    double getValue() override;
    void display(std::stringstream &ss) override;
    AST_Type getType() const override;

private:
    double value;

};


class Const_AST : public Base_AST {
public:
    Const_AST(double value, cstr text);
    ~Const_AST();

    double getValue() override;
    void display(std::stringstream &ss) override;
    AST_Type getType() const override;

private:
    double value;
    cstr text;

};


class Unary_AST : public Base_AST {
public:
    Unary_AST(cstr function, Base_AST *inner);
    ~Unary_AST();

    double getValue() override;
    void display(std::stringstream &ss) override;
    AST_Type getType() const override;

    Base_AST *&getInner();
    void setInner(Base_AST *ast, bool del = true);

private:
    cstr function;
    Base_AST *inner;

};


class Binary_AST : public Base_AST {
public:
    enum class Style { Operator, Function };

    Binary_AST(cstr operation, Base_AST *first, Base_AST *second, Style style);
    ~Binary_AST();

    double getValue() override;
    void display(std::stringstream &ss) override;
    AST_Type getType() const override;

    Base_AST *&getFirst();
    Base_AST *&getSecond();

    void setFirst(Base_AST *ast, bool del = true);
    void setSecond(Base_AST *ast, bool del = true);

    Style getStyle() const;
    
    bool getSecondBegun() const;
    void setSecondBegun(bool val);

private:
    cstr operation;
    Base_AST *first, *second;
    Style style;
    bool secondBegun;

};

