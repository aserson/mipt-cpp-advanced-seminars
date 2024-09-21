#pragma once

class Predicate { //интерфейс -- класс, содержащий только чисто виртуальные методы 
public:
    virtual bool operator()(int prob) const { //virtual -- дает в дальнейшем изменять наследников класса
        return true;
    }
};

class ValuePredicate: public Predicate {
private:
    int const val;
public:
    ValuePredicate(int val): val(val) { }
    bool operator()(int prob) const {
        return val == prob;
    }
};

class IntervalPredicate: public Predicate {
private:
    int const min,max;
public:
    IntervalPredicate(int min, int max): min(min), max(max) { }
    bool operator()(int prob) const {
        return prob >= min && prob <= max;
    }
};

//обобщеная функция подсчёта
unsigned unified_do_count(int const *const beg, int const *const end, Predicate const &predicate) { //const -- данным метод гарантирует, что не будет изменять внутреннее состояние
    unsigned cnt = 0;
    for (const int * it = beg; it !=end; ++it)
        if (predicate(*it)) ++cnt;
    
    return cnt;
}
