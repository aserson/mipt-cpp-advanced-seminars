#include <iostream>
#include <set>
#include <random>
#include<fstream>
#include<string>
#include <vector>
using namespace std;

class State {
public:
    virtual bool contains(int s) const{ 
        return true;
    }
};

class SegmentState: public State {
private:
    int const beg, end;

public:
    SegmentState() : beg(0), end(-1) { }
    SegmentState(int beg, int end) : beg(beg), end(end) { }

    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState: public State{
private:
    std::set<int> const states;

public:
    SetState() : states() { }
    SetState(std::set<int> const& src) : states(src) { }

    bool contains(int s) const {
        return states.count(s) > 0;
    }
};


class DiscreteState: public State {
private:
    int const state;

public:
    DiscreteState(int state) : state(state) { }

    bool contains(int s) const {
        return s == state;
    }
};

class AddidionState :public State {   // объединение SetState и SegmentState
private:
    State const &s1;
    State const &s2;
public:
    AddidionState(State const &s1, State const &s2) : s1(s1), s2(s2) {}

    bool contains(int s) const {
        return s1.contains(s) or s2.contains(s);
    }
};

class IntersectionState :public State {   // пересечение SetState и SegmentState
private:
    State const &s1;
    State const &s2;
public:
    IntersectionState(State const &s1, State const &s2) : s1(s1), s2(s2) {}

    bool contains(int s) const {
        return s1.contains(s) and s2.contains(s);
    }
};

class SubtractionState :public State {   //вычитание SetState из SegmentState
private:
    State const &s1;
    State const &s2;
public:
    SubtractionState(State const &s1, State const &s2) : s1(s1), s2(s2) {}

    bool contains(int s) const {
        return s1.contains(s) and !s2.contains(s);
    }
};

class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;

public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count) : seed(seed), test_min(test_min), test_max(test_max), test_count(test_count) { }

    float operator()(State const& s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min, test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;

        return static_cast<float>(good) / static_cast<float>(test_count);
    }
    void change_test_count (int n){
        test_count = n;
    }
};

int main(int argc, const char* argv[]) {
    DiscreteState d(1);
    SegmentState s(0, 10);
    SetState ss({ 1, 3, 5, 7, 23, 48, 57, 60, 90, 99 });
    ProbabilityTest test(10, 0, 100, 100000);
    AddidionState as(s, ss);
    IntersectionState is(s, ss);
    SubtractionState sus(s, ss);

    std::cout << test(as) << std::endl;
    std::cout << test(is) << std::endl;
    std::cout << test(sus) << std::endl;


    /*
    Здесь решение второго пункта для Segment. Графики - зависимость P(end) для 10 различных значений количества испытаний (test_count)
    Для удобства кол-во испытаний поделено на 1000 (кроме первого) при записи в файл  
    */

    /*ofstream fin2_segment; // пункт 2 для сегмента
    fin2_segment.open("2_segment.txt");
    fin2_segment << "end-P(1000)-P(2)-P(3)-P(4)-P(5)-P(6)-P(7)-P(8)-P(9)-P(10)" << endl; //  в скрбках указано значение Test_count  в тысячах, кроме первого
    for (int i = 1;i <= 110;++i) {
        fin2_segment << i;
        SegmentState s(0, i);
        for (int j = 1;j <= 10;++j) {
            test.change_test_count(1000 * j);
            fin2_segment << "-" << test(s);
        }
        fin2_segment << endl;
    }*/

    /*

    ofstream fin2_set; // пункт 2 для сета
    fin2_set.open("2_set.txt");
    fin2_set << "end-P(1000)-P(2)-P(3)-P(4)-P(5)-P(6)-P(7)-P(8)-P(9)-P(10)" << endl; //  в скрбках указано значение Test_count
    vector<SetState> sets;
    random_device rd;   
    mt19937 gen(rd());  
    uniform_int_distribution<> dist(0, 100);
    for (int i = 1;i <= 300;++i) {
        set <int> st;
        for (int j = 0; j < i;++j) {
            st.insert(dist(gen));//st.insert(rand()%100);
        }
        SetState ss(st);
        sets.push_back(ss);
    }
    
    
    for (int i = 0;i < 300;++i) {
        fin2_set << i;
        for (int j = 1;j <= 10;++j) {
            test.change_test_count(1000 * j);
            fin2_set << "-" << test(sets[i]);
        }
        fin2_set << endl;
    }

    */

    /*ofstream fin1_segment;  //пункты 1 и 3
    ofstream fin1_set;
    ofstream comparison;
    //ofstream test_count;
    fin1_segment.open("1_segment.txt");
    fin1_set.open("1_set.txt");
    comparison.open("3_comparicon.txt");
    fin1_segment << "Test_count-P" << endl;
    fin1_set << "Test_count-P" << endl;
    comparison << "Test_count-P" << endl;
    //test_count.open("test.count.txt");
    int n = 1000;
    ProbabilityTest test(10, 0, 100, n);
    for (int i = 0; i < 1000;++i) {
        float o = test(s);
        float l = test(ss);
        fin1_segment << n << "-" << o << endl;
        fin1_set << n << "-" << l << endl;
        comparison << n << "-" << -l + o << endl;
        //test_count << n << endl;
        n += 1000;
        test.change_test_count(n);
    }*/
    return 0;
}