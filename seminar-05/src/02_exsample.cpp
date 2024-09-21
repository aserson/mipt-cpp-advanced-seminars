#include <iostream>

class ComplexNumber {
private:
    int a,b;
public:
    ComplexNumber() : ComplexNumber(0) { }
    ComplexNumber(int a) : ComplexNumber(a,0) { }
    ComplexNumber(int a, int b) : a(a), b(b) { }

    int real() const {
        return a;
    }

    ComplexNumber& operator+=(ComplexNumber const &rha);
    ComplexNumber& operator-=(ComplexNumber const &rha);
    ComplexNumber& operator*=(ComplexNumber const &rha);


    friend std::ostream& operator<<(std::ostream &out, ComplexNumber const &rha);

};

std::ostream& operator<<(std::ostream &out, ComplexNumber const &rha) {
    out << rha.a << " + " << rha.b << "*i";

    return out;
}


ComplexNumber& ComplexNumber::operator+=(ComplexNumber const &rha) {
    a+=rha.a;
    b+=rha.b;
    return *this;
}
    
ComplexNumber& ComplexNumber::operator-=(ComplexNumber const &rha) {
    a-=rha.a;
    b-=rha.b;
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(ComplexNumber const &rha) {
    auto atmp = a * rha.a - b * rha.b;
    auto btmp = a * rha.b + b * rha.a;
    a = atmp;
    b = btmp;
    return *this;    
}

int main() {
    ComplexNumber i1(2,4), i2(4,5);

    i1 *= i2;

    std::cout << i1 << std::endl;

    return 0;


}