//пример работы деструктора
#include <iostream>

struct SimpleStruct {
    SimpleStruct() {
        std::cout << "Born!" << std::endl;
    }

    ~SimpleStruct() {
        std::cout << "Dead..." << std::endl;
    }
};


int main() {
{
    SimpleStruct S1;
}
std::cout << "Now" << std::endl;
}