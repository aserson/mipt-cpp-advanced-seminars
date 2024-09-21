#include <iostream>
#include <set>
#include <random>

class State{
private:
    int state, begin, end, a;
    std::set<int> const states;

public:
    State(int state): state(state) {a=1;}
    State(int begin, int end): begin(begin), end(end) {a=2;}
    State(std::set<int> const &src): states(src) {a=3;}

    bool contains(int s) const {
        if(a == 1){
            return s == state;
        }
        if(a == 2){
            return s >= begin && s <= end;
        }
        if(a == 3){
            return states.count(s) > 0;
        }
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
    State d(1);
    State s(0,10);
    State ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    ProbabilityTest pt(10,0,100,100000);
    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    std::cout << pt(ss) << std::endl;
    return 0;
}
