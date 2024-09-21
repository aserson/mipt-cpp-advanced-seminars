#pragma once

//пример программы на перегрузку оператора

class Counter { //базовый класс
protected:
    unsigned count; //счетчик

public:
    //перегруженные конструкторы:
    Counter( ): count(0) { }                    //конструктор без аргументов
    Counter(int c): count(c) { }                //конструктор c одним аргументом
  
    unsigned get_count( ) const { 
        return count; //возвращает значение счетчика
    } 

    Counter operator++( ) { 
        return Counter(++count); //увеличивает значение счетчика (префикс)
    }
};
