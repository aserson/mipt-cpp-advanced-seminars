#include <iostream>

void simple_input_output() {
    int unit = 1;   
    char symbol = '!';

    std::cout << unit << std::endl;
    std::cout << symbol << std::endl;

    
    std::cin >> unit;

    std::cout << unit << std::endl;
        
    std::cout.flush(); //принудительная передача данных из буфера
}
