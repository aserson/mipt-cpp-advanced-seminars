#include <iostream> 
#include <set> 
#include <random> 
#include <fstream> 
 
 
class DiscreteState { 
private: 
    int const state; 
 
public: 
    DiscreteState() : state(INFINITY) { } 
    DiscreteState(int state) : state(state) { } 
 
    virtual bool contains(int s) const { 
        return s == state; 
    } 
}; 
 
class SegmentState : public DiscreteState { 
private: 
    int const beg, end; 
 
public: 
    SegmentState() : beg(0), end(-1) { } 
    SegmentState(int beg, int end) : beg(beg), end(end) { } 
 
    bool contains(int s) const { 
        return s >= beg && s <= end; 
    } 
}; 
 
class SetState : public DiscreteState { 
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
 
    float operator()(DiscreteState const& s) const { 
        std::default_random_engine rng(seed); 
        std::uniform_int_distribution<int> dstr(test_min, test_max); 
        unsigned good = 0; 
        for (unsigned cnt = 0; cnt != test_count; ++cnt) 
            if (s.contains(dstr(rng))) ++good; 
 
        return static_cast<float>(good) / static_cast<float>(test_count); 
    } 
}; 
 
int main(int argc, const char* argv[]) { 
    std::ofstream out; 
    DiscreteState d(1); 
    SegmentState s(0, 10); 
    SetState ss({ 1, 3, 5, 7, 23, 48, 57, 60, 90, 99 }); 
    out.open("D:\\hello.txt"); 
    for (int i = 1; i < 10000; i++) 
    { 
        ProbabilityTest pt(7700, 0, 100, i); 
        out << i << " - " << pt(d) << std::endl; 
    } 
    return 0; 
}