#include <iostream>

using namespace std; 

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
    cout << f(x) << endl;
}

int main(){
    PolynomialFunction f; //f=0
    LinearFunction l(1.0,1.0); //l=x+1
    QuadraticFunction q(1.0,1.0,1.0); //q=x^2+x+1

    polymorphic_call(f, 1.0);
    polymorphic_call(l, 1.0);
    polymorphic_call(q, 1.0);

}