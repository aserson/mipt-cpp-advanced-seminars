#pragma once

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
