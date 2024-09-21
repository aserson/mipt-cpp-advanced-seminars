#include <iostream>

#include "task-03.h"

int main() {

    Counter C1(2); //создаем счетчик без уменьшения

    std::cout << "Counter value is " << C1.get_count() << std::endl;

    std::cout << "Increase the counter value" << std::endl;
    ++C1; ++C1;

    std::cout << "Counter value is " << C1.get_count() << std::endl;

    std::cout << std::endl;

    CounterWithDecrease C2; //создаем счетчик с уменьшением

    std::cout << "Counter value is " << C2.get_count() << std::endl;

    std::cout << "Increase the counter value" << std::endl;
    ++C2; ++C2; ++C2; ++C2;

    std::cout << "Counter value is " << C2.get_count() << std::endl;

    std::cout << "Decrease the counter value" << std::endl;
    --C2; --C2; --C2;

    std::cout << "Counter value is " << C2.get_count() << std::endl;

    return 0;
}