#include <iostream>
#include <set>
#include <random>

class State{//создаем интерфейс
public:
    virtual bool operator()(int s) const{//задаем оператор, чтобы передавать не только числа, но и целые множества. 
    return true;
    }
};

class DiscreteState:public State {
private:
    int const state;

public:
    DiscreteState(int state): state(state) { }//рассматриваем отдельное число

    bool operator()(int s) const {
        return s == state;
    }
};

class SegmentState:public State {//отрезок, смотрим попадает или нет 
private:
    int const beg, end;
    
public:
    SegmentState(int beg, int end): beg(beg), end(end) { }
    
    bool operator()(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState: public State{//набираем множество
private:
    std::set<int> const states;
    
public:
    SetState(std::set<int> const &src): states(src) { }
    
    bool operator()(int s) const {
        return states.count(s) > 0;
    }
};



class Conjunction: public State {//объединение
private:
    const State &s1,&s2;
public:
    Conjunction(State const &s1, State const &s2): s1(s1), s2(s2) { }

    bool operator()(int prob) const {
        return s1(prob) && s2(prob);
    }
};

class Disjunction: public State {//пересечение
private:
    const State &s1,&s2;
public:
    Disjunction(State const &s1, State const &s2): s1(s1), s2(s2) { }

    bool operator()(int prob) const {//проверка на совпадает или нет
        return s1(prob) || s2(prob);
    }
};

class Negation: public State{//отрицание
private:
    const State &s1, &s2;
public:
    Negation(State const &s1, State const &s2): s1(s1), s2(s2) { }
    
    bool operator()(int n) const{
        if (s1(n) and not(s2(n))){
            return true;
        }
        if (s1(n) and not(s2(n))){
            return true;
        }
        else{
            return false;
        }
    }
};

class ProbabilityTest{//задаем интервал, гоняю по этому интервалу много раз, он выдает вероятность. 
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;


public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count): seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }

    float operator()(State const &s) const  {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s(dstr(rng))) ++good;

        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};
void SetStateProbability(int n, State a){
	ofstream fout("SetState.txt");
	for (int i = 1; i < n + 1; i+=100){
        ProbabilityTest pt(0,10,100,i);
        fout << to_string(pt(a)) << endl;
	}

	fout.close();
}
void DiscreteStateProbability(int n, State a){
	ofstream fout("DiscreteState.txt");
	for (int i = 1; i < n + 1; i+=500){
        ProbabilityTest pt(10,0,100,i);
        fout << to_string(pt(a)) << endl;
	}
	fout.close();
}

void SegmentStateProbability(int n, State a){
	ofstream fout("SegmentState.txt");
	for (int i = 1; i < n + 1; i+=500){
        ProbabilityTest pt(10,0,100,i);
        fout << to_string(pt(a)) << endl;
	}
	fout.close();
}

int main(int argc, const char * argv[]) {
    DiscreteState d(1);
    SegmentState s(0,10);
    DiscreteState d2(15);
    SetState ss({6, 9, 15, 47, 55, 58, 64, 78, 91, 95});
    SetState ss1({6, 9, 15, 47, 55, 58});
    SetState ss2({64, 78, 91, 95});
    ProbabilityTest pt(0,10,100,100000);
    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    std::cout << pt(ss) << std::endl;

    Conjunction c(s,ss1);// объединение
    Conjunction c_1(s,ss2);
    
    Disjunction di(d,ss1);//  с пропусками
    Disjunction di_1(d,ss2);
    
    Negation n(s,ss1);// с дополнени€ми
    Negation n2(s,ss1);
    Disjunction di_2(d,ss1);//с пропусками и дополнени€ми
    
    Disjunction di_3(d2,n2);

    std::cout << pt(c) << std::endl;
    std::cout << pt(c_1) << std::endl;
    std::cout << pt(di) << std::endl;
    std::cout << pt(di_1) << std::endl;
    std::cout << pt(n) << std::endl;
    std::cout << pt(di_2) << std::endl;
    std::cout << pt(di_3) << std::endl;
    return 0;
    
}