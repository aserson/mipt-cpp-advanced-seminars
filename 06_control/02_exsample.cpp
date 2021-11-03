//пример последовательности вызова деструкторов
#include <iostream>

struct SimpleStruct {

    unsigned id;

    SimpleStruct(unsigned id): id(id) {
        std::cout << "Born!(" << id << ")" << std::endl;
    }

    ~SimpleStruct() {
        std::cout << "Dead...(" << id << ")" << std::endl;
    }
};


int main() {

    SimpleStruct a1(1);
    SimpleStruct a2(2);
    
    {
        SimpleStruct a3(3);
    }
    SimpleStruct a4(4);



}