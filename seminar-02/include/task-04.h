#pragma once

#include <iostream>

class PolynomialFunction{
public:
    virtual float operator()(float x) { //virtual -- дает в дальнейшем изменять наследников класса
        return 0.0;
    }
};

class LinearFunction: public PolynomialFunction {
private:
    float a,b;
public:
    LinearFunction(float a, float b): a(a), b(b) { }

    float operator()(float x) {
        return a*x+b;
    } 
};

class QuadraticFunction: public PolynomialFunction {
private:
    float a,b,c;
public:
    QuadraticFunction(float a, float b, float c): a(a), b(b), c(c) { }

    float operator()(float x) {
        return a*x*x+b*x+c;
    }
};

void polymorphic_call(PolynomialFunction &f, float x) {
    std::cout << f(x) << std::endl;
}
