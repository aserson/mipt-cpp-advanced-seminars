#include <iostream>
#include <set>
#include <random>
#include <fstream>

class State {
public:
    virtual bool contains(int s) const { 
        return true;
    }
};

class DiscreteState: public State { //одиночное состояние
private:
    int const state;

public:
    DiscreteState(int state): state(state) { }

    bool contains(int s) const {
        return s == state;
    }
};

class SegmentState: public State { //подряд идущие состояния
private:
    int const beg, end;
    
public:
    SegmentState(): beg(0), end(-1) { }
    SegmentState(int beg, int end): beg(beg), end(end) { }
    
    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState: public State {    //произвольно расположенные состояния
private:
    std::set<int> const states;
    
public:
    SetState(): states() { }
    SetState(std::set<int> const &src): states(src) { }
    
    bool contains(int s) const {
        return states.count(s) > 0;
    }
};

class Conjunction: public State {
private:
    const State &s1,&s2;
public:
    Conjunction(State const &s1, State const &s2): s1(s1), s2(s2) { }

    bool contains(int prob) const {
        return s1.contains(prob) && s2.contains(prob);
    }
};

class Disjunction: public State {
private:
    const State &s1,&s2;
public:
    Disjunction(State const &s1, State const &s2): s1(s1), s2(s2) { }

    bool contains(int prob) const {
        return s1.contains(prob) || s2.contains(prob);
    }
};

class DisjunctionNegative: public State {
private:
    const State &s1,&s2;
public:
    DisjunctionNegative(State const &s1, State const &s2): s1(s1), s2(s2) { }

    bool contains(int prob) const {
        return s1.contains(prob) || !s2.contains(prob);
    }
};

class Negation: public State {
private:
    const State &s1;
public:
    Negation(State const &s1): s1(s1) { }

    bool contains(int prob) const {
        return !s1.contains(prob);
    }
};

class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;
    
public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count): seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }

    float operator()(State const &s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;
        
        return static_cast<float>(good)/static_cast<float>(test_count);
    } 
    
};

int main(int argc, const char * argv[]) {
    DiscreteState d(1);
    SegmentState s(0,9);
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});

    //набор непрерывных состояний с пропусками
    SegmentState s11(20,50);           //31
    SetState s12({23, 31, 48});        //3
    Negation s13(s12);                 //-3
    Conjunction out1(s11,s13);   //31-3=28

    //набор непрерывных состояний с дополнениями
    SegmentState s21(10,25);             //16
    SetState s22({5, 28, 78});          //3
    Disjunction out2(s21,s22);     //16+3=19

    //набор непрерывных состояний с пропусками и дополнениями
    SegmentState s31(37,73);             //37
    SetState s32({5, 28, 78});         //3
    SetState s33({43, 51, 68});        //3
    Negation s34(s33);               //100-3
    Disjunction s35(s31,s32);   //37+3=40
    Conjunction out3(s35,s34);      //37

    //состояние как объединение двух других состояний
    SegmentState s41(37,73);
    SegmentState s42(25,50);
    Disjunction  out4(s41,s42);

    //состояние как пересечение двух других состояний
    SegmentState s51(37,73);
    SegmentState s52(25,50);
    Conjunction  out5(s51,s52);

    ProbabilityTest pt(10,0,100,100000);

    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    std::cout << pt(ss) << std::endl;
    std::cout << pt(out1) << std::endl;
    std::cout << pt(out2)  << std::endl;
    std::cout << pt(out3) << std::endl;
    std::cout << pt(out4)  << std::endl;
    std::cout << pt(out5)  << std::endl;

    std::ofstream fout("file.txt");

    for (unsigned i = 10; i<10001; ++i) {
        ProbabilityTest pt(10,0,100,i);         
        fout << i << " " << pt(s) << " " << pt(ss) << std::endl;        
    }

    return 0;
}