#pragma once
//пример программы на перегрузку конструктора

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
