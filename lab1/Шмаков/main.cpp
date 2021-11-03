#include <iostream>
#include <set>
#include <random>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class State { //интерфейс -- класс, содержащий только чисто виртуальные методы 
public:
    virtual bool contains(int s) const { //virtual -- дает в дальнейшем изменять наследников класса
        return true;
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

class SegmentState : public State {
private:
    int const beg, end;

public:
    SegmentState() : beg(0), end(-1) { }
    SegmentState(int beg, int end) : beg(beg), end(end) { }

    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState: public State {
private:
    std::set<int> const states;

public:
    SetState() : states() { }
    SetState(std::set<int> const& src) : states(src) { }

    bool contains(int s) const {
        return states.count(s) > 0;
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
};

class CrossingStates : public State {      //Пересечение отрезка и точки(набора точек)
private:
    const State& s1;
    const State& s2;
public:
    CrossingStates (const State& s1, const State& s2) : s1(s1), s2(s2) {};

    bool contains(int s)  {
        return s1.contains(s) && s2.contains(s);
    }

};

class UnionStates : public State {   // Объединение отрезка и точки(набора точек)
private:
    const State& s1;
    const State& s2;
public:
    UnionStates(const State& s1, const State& s2) : s1(s1), s2(s2) { }

    bool contains(int s) const {
        return s1.contains(s) or s2.contains(s);
    }

};

class SubstractStates : public State {  // Вычитание точки(набора точек) из отрезка
private:
    const State& s1;
    const State& s2;
public:
    SubstractStates(const State& s1, const State& s2) : s1(s1), s2(s2) { }

    bool contains(int s) const {
        return !s1.contains(s) and s2.contains(s);
    }
};

void write_to_file(string file_name, string data)
{
    ofstream ofs(file_name + ".txt", ofstream::trunc);
    ofs << data << endl;
    ofs.close();
}

int main(int argc, const char* argv[]) {
    DiscreteState d(1);
    SegmentState s(0, 10);
    SetState ss({ 1, 3, 5, 7, 23, 48, 57, 60, 90, 99 });
    ProbabilityTest pt(10, 0, 100, 100000);
    cout << pt(d) << std::endl;
    cout << pt(s) << std::endl;
    cout << pt(ss) << std::endl;

    vector<ProbabilityTest> TestSet = {};
    for (int i = 10; i <= 100000; i+=10)
    {
        ProbabilityTest x(10, 0, 100, i);
        TestSet.push_back(x);
    }


    bool flag_1 = true;
    if (flag_1)
    {
        ofstream ofss("./calculations/1) SegmentState.txt", ofstream::trunc);
        ofstream ofsss("./calculations/1) SetState.txt", ofstream::trunc);
        for (int i = 0; i < TestSet.size(); i++)
        {
            cout << "Now on " << (i + 1) * 10 << " test 1" << endl;
            string t = " ";

            ofss << to_string((i + 1) * 10) + t + to_string(TestSet[i](s)) << endl;
            ofsss << to_string((i + 1) * 10) + t + to_string(TestSet[i](ss)) << endl;
        }
        ofss.close();
        ofsss.close();
    }


    CrossingStates cs(s, ss);
    UnionStates us(s, ss);
    SubstractStates subss(s, ss);


    bool flag_2 = true;
    if (flag_2)
    {
        ofstream ofs1("./calculations/1) CrossingStates.txt", ofstream::trunc);
        ofstream ofs2("./calculations/1) UnionStates.txt", ofstream::trunc);
        ofstream ofs3("./calculations/1) SubstractStates.txt", ofstream::trunc);
        for (int i = 0; i < TestSet.size(); i++)
        {
            cout << "Now on " << (i + 1) * 10 << " test 2" << endl;
            string t = " ";

            ofs1 << to_string((i + 1) * 10) + t + to_string(TestSet[i](cs)) << endl;
            ofs2 << to_string((i + 1) * 10) + t + to_string(TestSet[i](us)) << endl;
            ofs3 << to_string((i + 1) * 10) + t + to_string(TestSet[i](subss)) << endl;
        }
        ofs1.close();
        ofs2.close();
        ofs3.close();
    }
    

    return 0;
}
