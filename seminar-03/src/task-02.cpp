#include <iostream>
#include <random>
#include <ctime>

#include "task-02.h"

int main(){
    int N = 10;
    int *numbers = new int[N];

    srand(time(nullptr));  //задаем зерно гернирации псевдослучайных чисел
    for (int i = 0; i < N; i++)
        numbers[i] = rand() % 100;

	for (int i=0; i<N; i++) 
        std::cout << numbers[i] << " " ;

    std::cout << std::endl;

    Predicate P1;                   //предикатор для всех чисел в последовательности 
    ValuePredicate P2(19);          //предикатор для всех чисел равных 19
    IntervalPredicate P3(0,50);     //предикатор для всех чисел в промежутке между 0 и 50

    std::cout << unified_do_count(&numbers[0],&numbers[N],P1) << std::endl;

    std::cout << unified_do_count(&numbers[0],&numbers[N],P2) << std::endl;

    std::cout << unified_do_count(&numbers[0],&numbers[N],P3) << std::endl;

    delete[] numbers;

    return 0;
}