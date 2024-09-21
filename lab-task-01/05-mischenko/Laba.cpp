#include <iostream>
#include <set>
#include <random>
#include<fstream>


class State {
public:
    State() = default;

    virtual bool contains(int s) const {
        return true;
    }

};

class DiscreteState : public State {
private:
    int const state;

public:
    DiscreteState(int state): state(state) { }

    bool contains(int s) const {
        return s == state;
    }
};

class SegmentState : public State {
protected:
    int const beg, end;

public:
    SegmentState(): beg(0), end(-1) { }
    SegmentState(int beg, int end): beg(beg), end(end) { }

    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState : public State {
private:
    std::set<int> const states;

public:
    SetState(): states() { }
    SetState(std::set<int> const &src): states(src) { }

    bool contains(int s) const {
        return states.count(s) > 0;
    }
};

class SegmentStateDisPlus : public State {
private:
    SegmentState ss;
    DiscreteState ds;

public:
    SegmentStateDisPlus(SegmentState ss, DiscreteState ds): ss(ss), ds(ds) { }

    bool contains(int s) const {
        return (ss.contains(s) || ds.contains(s));
    }
};

class SegmentStateDisMinus : public State {
private:
    SegmentState ss;
    DiscreteState ds;

public:
    SegmentStateDisMinus(SegmentState ss, DiscreteState ds): ss(ss), ds(ds) { }

    bool contains(int s) const {
        return (ss.contains(s) && !(ds.contains(s)));
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
    DiscreteState d(10);
    SegmentState s(0,10);
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    ProbabilityTest pt(10, 0, 100, 1000000);
    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    std::cout << pt(ss) << std::endl;

    //for graphics

    std::ofstream fout;
    fout.open("Segment_test_max.txt");
    for (int test_max = 100; test_max <= 1000; test_max += 50){
            ProbabilityTest pt(10, 0, test_max, 1000000);
            fout << pt(s) << std::endl;
    }
    fout.close();

    return 0;
}
