#pragma once

class Predicate { //интерфейс -- класс, содержащий только чисто виртуальные методы 
public:
    virtual bool operator()(int prob) const { //virtual -- дает в дальнейшем изменять наследников класса
        return true;
    }
};

class SmallerPredicate: public Predicate {
private:
    int const value;
public:
    SmallerPredicate(int value): value(value) { }

    bool operator()(int prob) const {
        return prob <= value ;
    }
};

class LargerPredicate: public Predicate {
private:
    int const value;
public:
    LargerPredicate(int value): value(value) { }

    bool operator()(int prob) const {
        return prob >= value ;
    }
};

class PredicateConjunction: public Predicate {
private:
    const Predicate &p1,&p2;
public:
    PredicateConjunction(Predicate const &p1, Predicate const &p2): p1(p1), p2(p2) { }

    bool operator()(int prob) const {
        return p1(prob) && p2(prob);
    }
};

class PredicateDisjunction: public Predicate {
private:
    const Predicate &p1,&p2;
public:
    PredicateDisjunction(Predicate const &p1, Predicate const &p2): p1(p1), p2(p2) { }

    bool operator()(int prob) const {
        return p1(prob) || p2(prob);
    }
};

//обобщеная функция подсчёта
unsigned unified_do_count(int const *const beg, int const *const end, Predicate const &predicate) { //const -- данным метод гарантирует, что не будет изменять внутреннее состояние
    unsigned cnt = 0;
    for (auto it = beg; it !=end; ++it)
        if (predicate(*it)) ++cnt;
    
    return cnt;
}
