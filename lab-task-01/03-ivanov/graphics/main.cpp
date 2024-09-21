#include <iostream>
#include <set>
#include <random>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
using std::string;

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

void SetStateProbability(int n, State a){
	ofstream fout("SetState.txt");
	for (int i = 1; i < n + 1; i+=500){
        ProbabilityTest pt(10,0,100,i);
        fout << to_string(pt(a)) << endl;
	}

	fout.close();
}

int main(int argc, const char * argv[]) {
    State d(1);
    State s(0,10);
    State ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    DiscreteStateProbability(100000, d);
    SegmentStateProbability(100000, s);
    SetStateProbability(100000, ss);
    return 0;
}
