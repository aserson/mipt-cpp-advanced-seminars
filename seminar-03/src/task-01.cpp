#include <iostream>
#include <random>
#include <ctime>

#include "task-01.h"

int main() {
    int N = 10;
    int* numbers = new int[N];

    srand(time(nullptr));  //задаем зерно гернирации псевдослучайных чисел
    for (int i = 0; i < N; i++)
        numbers[i] = rand() % 100;

    for (int i = 0; i < N; i++)
        std::cout << numbers[i] << " ";

    std::cout << std::endl;

    std::cout << do_count(&numbers[0], &numbers[N]) << std::endl;

    std::cout << do_count_number(&numbers[0], &numbers[N], 19) << std::endl;

    std::cout << do_count_in_interval(&numbers[0], &numbers[N], 0, 50) << std::endl;

    delete[] numbers;

    return 0;
}
