#include <iostream>
#include <set>
#include <random>
#include <fstream>
#include <ctime>

using namespace std;

class State {
public:
    virtual bool contains(int s) const
    {
        return true;
    }
};

class DiscreteState: public State {
private:
    int const state;

public:
    DiscreteState(int state): state(state) { }

    bool contains(int s) const {
        return s == state;
    }
};

class SegmentState: public State {
private:
    int const beg, end;

public:
    SegmentState(): beg(0), end(-1) { }
    SegmentState(int beg, int end): beg(beg), end(end) { }

    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState: public State {
private:
    std::set<int> const states;

public:
    SetState(): states() { }
    SetState(std::set<int> const &src): states(src) { }

    bool contains(int s) const
    {
        return states.count(s) > 0;
    }
};

class UnionState: public State {
private:
    const State &S1, &S2;
public:
    UnionState(State &S1, State &S2): S1(S1), S2(S2) { }

    bool contains(int s) const {
        return S1.contains(s) || S2.contains(s);
    }
};

class CrossState: public State {
private:
    const State &S1, &S2;
public:
    CrossState(State &S1, State &S2): S1(S1), S2(S2) { }

    bool contains(int s) const {
        return S1.contains(s) && S2.contains(s);
    }
};

// Реализация непрерывных состояний с пропусками, где предполагается S1 типа SegmentState,
// а S2 - SetState. Непрерывные состояния с дополнениями это буквально UnionState(S1, S2)
class PassState: public State {
private:
    const State &S1, &S2;
public:
    PassState(State &S1, State &S2): S1(S1), S2(S2) { }

    bool contains(int s) const {
        return S1.contains(s) && !(S2.contains(s));
    }
};

// Реализация непрерывных состояний с пропусками и дополнениями, где предполагается S1 типа
// SegmentState, S2 и S3 - SetState
class PassAddState: public State {
private:
    const State &S1, &S2, &S3;
public:
    PassAddState(State &S1, State &S2, State &S3): S1(S1), S2(S2), S3(S3) { }

    bool contains(int s) const {
        return S1.contains(s) && !(S2.contains(s)) || S1.contains(s);
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

    DiscreteState d(62);
    SegmentState s(0,10);
    SetState ss({33, 29, 53, 73, 42, 12, 25, 8, 1, 2});
    UnionState u(ss, s);
    CrossState c(ss, s);

    /* // пункт 1
    ofstream out;
    out.open("out.txt");
    for (int i = 1000; i < 100000; i = i + 1000)
    {
        ProbabilityTest pt(20,0,100,i);
        out << pt(d) << endl;
    }
    out.close();
    */

    /* // пункт 2
    ProbabilityTest pt(20,0,100,100000);
    for(float i = 10; i < 100; i = i + 10)
    {
        SegmentState var(0, i);
        cout << i << " 101 " << i / 101 << ' ' << pt(var) << endl;
    }
    */

    return 0;
}
