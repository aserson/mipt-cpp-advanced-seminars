//пример программы на перегрузку конструктора
#include <iostream>

using namespace std; 

class Counter { //базовый класс
private:
    unsigned count; //счетчик

public:
    //перегрузка конструктора:
    Counter( ): count(0) { }                    //конструктор без аргументов
    Counter(int c): count(c) { }                //конструктор c одним аргументом
    Counter(int c1, int c2): count(c1+c2) { }   //конструктор с тремя аргументами

    //делегирующие конструкторы:
    //Counter( ): Counter(0) { }                  //конструктор без аргументов
    //Counter(int c): count(c) { }                //конструктор c одним аргументом

    unsigned get_count( ) const { 
        return count; //возвращает значение счетчика
    } 

};

int main() {

    Counter C1;
    Counter C2(2);
    Counter C3(2,6);

    cout << "Counter C1 value is " << C1.get_count() << endl;

    cout << "Counter C2 value is " << C2.get_count() << endl;

    cout << "Counter C2 value is " << C3.get_count() << endl;

    cout << endl;

}