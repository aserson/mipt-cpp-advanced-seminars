#include <iostream>

#include "task-02.h"

int main() {

    Counter C;

    std::cout << "Counter value is " << C.get_count() << std::endl;

    ++C; ++C; ++C;

    std::cout << "Counter value is " << C.get_count() << std::endl;

    return 0;
}