#include <iostream>

#include "task-01.h"

int main() {
    Counter C1;
    Counter C2(2);
    Counter C3(2,6);

    std::cout << "Counter C1 value is " << C1.get_count() << std::endl;

    std::cout << "Counter C2 value is " << C2.get_count() << std::endl;

    std::cout << "Counter C2 value is " << C3.get_count() << std::endl;

    return 0;
}