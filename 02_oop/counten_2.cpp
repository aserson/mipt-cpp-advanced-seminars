#include <iostream>

using namespace std; 

class Counter { //базовый класс
protected:
    unsigned count; //счетчик

public:
    Counter( ): count(0) { } //конструктор без аргументов

    Counter(int c): count(c) { }

    unsigned get_count( ) const { 
        return count; //возвращает значение счетчика
    } 

    Counter operator++( ) { 
        return Counter(++count); //увеличивает значение счетчика (префикс)
    }

};

class CounterWithDecrease: public Counter { //производный класс
public:

    //CounterWithDecrease(): Counter() { }

    //CounterWithDecrease(int c): Counter(c) { }

    Counter operator--( ) { 
        return Counter(--count); //уменьшает значение счетчика (префикс)
    }
};

int main() {

    Counter C1(2); //создаем счетчик без уменьшения

    cout << "Counter value is " << C1.get_count() << endl;

    cout << "Increase the counter value" << endl;
    ++C1; ++C1;

    cout << "Counter value is " << C1.get_count() << endl;

    cout << endl;

    CounterWithDecrease C2; //создаем счетчик с уменьшением

    cout << "Counter value is " << C2.get_count() << endl;

    cout << "Increase the counter value" << endl;
    ++C2; ++C2; ++C2; ++C2;

    cout << "Counter value is " << C2.get_count() << endl;

    cout << "Decrease the counter value" << endl;
    --C2; --C2; --C2;

    cout << "Counter value is " << C2.get_count() << endl;

}