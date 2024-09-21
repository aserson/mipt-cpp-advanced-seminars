#include <iostream>

//рисунок класса, по которому можно посмтроить классы
template <typename RealNumber> 
class ComplexNumber {
private:
    RealNumber a,b;
public:
    ComplexNumber() : ComplexNumber(0) { }
    ComplexNumber(RealNumber a) : ComplexNumber(a,0) { }
    ComplexNumber(RealNumber a, RealNumber b) : a(a), b(b) { }

    operator RealNumber() const {
        return a;
    }

    //новый синтаксис
    //все операторы говорят о том, что мы работаем не со всем классом операторов перегрузки данного шаблона класса, а именно с <RealNumber>
    ComplexNumber<RealNumber>& operator+=(ComplexNumber<RealNumber> const &rha);
    ComplexNumber<RealNumber>& operator-=(ComplexNumber<RealNumber> const &rha);
    ComplexNumber<RealNumber>& operator*=(ComplexNumber<RealNumber> const &rha);

    template <typename RealNumber1> 
    friend std::ostream& operator<<(std::ostream &out, ComplexNumber<RealNumber1> const &rha);

};

template <typename RealNumber> 
std::ostream& operator<<(std::ostream &out, ComplexNumber<RealNumber> const &rha) {
    out << rha.a << " + " << rha.b << "*i";

    return out;
}

template <typename RealNumber> 
ComplexNumber<RealNumber>& ComplexNumber<RealNumber>::operator+=(ComplexNumber<RealNumber> const &rha) {
    a+=rha.a;
    b+=rha.b;
    return *this;
}
    
template <typename RealNumber> 
ComplexNumber<RealNumber>& ComplexNumber<RealNumber>::operator-=(ComplexNumber<RealNumber> const &rha) {
    a-=rha.a;
    b-=rha.b;
    return *this;
}

template <typename RealNumber> 
ComplexNumber<RealNumber>& ComplexNumber<RealNumber>::operator*=(ComplexNumber<RealNumber> const &rha) {
    auto atmp = a * rha.a - b * rha.b;
    auto btmp = a * rha.b + b * rha.a;
    a = atmp;
    b = btmp;
    return *this;    
}

int main() {
    ComplexNumber<float> i1(2.21,4.f), i2(4.f,5.f);

    i1 += i2;

    std::cout << i1 << std::endl;

    return 0;


}