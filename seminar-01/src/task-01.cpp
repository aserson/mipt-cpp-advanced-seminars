#include <iostream>

#include "task-01.h"

int main() {
    ChargedMass e1(1.0, 1.0, 0.0, 0.0);
    ChargedMass e2(-1.0, 1.0, 1.0, 1.0);
    std::cout << e1.distance(e2) << std::endl;

    return 0;
}