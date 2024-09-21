//работа счётчика с различными контейнерами
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <deque>
#include <cmath>

template <typename IndirectT, typename P>
size_t count(IndirectT beg, IndirectT end, P pred) {
    size_t c = 0;
    for (auto it = beg; it != end; ++it) 
        if (pred(*it)) ++c;

    return c;
}

int main(){
    
    struct  Pred     {
        bool operator()(int x) const {
            return x>0;
        }
    };
    
    //array
    std::array<int,5> a = {-2, -1, 0, 1, 2};
    std::cout << count(a.data(),a.data() + a.size(), Pred()) << std::endl;


    //vector
    std::vector<int> v = {-2, -1, 0, 1, 2};
    std::cout << count(v.data(),v.data() + v.size(), Pred()) << std::endl;

    //deque
    std::deque<int> d = {-2, -1, 0, 1, 2};

}