#include <iostream>
#include <random>

#include "task-03.h"

int main(){
    int N = 10;
    int* numbers = new int[N];

    srand(time(nullptr));  //задаем зерно гернирации псевдослучайных чисел
    for (int i = 0; i < N; i++)
        numbers[i] = rand() % 100;

	for (int i=0; i<N; i++) 
        std::cout << numbers[i] << " " ;

    std::cout << std::endl;

    SmallerPredicate P1(70);        //предикатор для всех чисел меньше 30
    LargerPredicate P2(30);         //предикатор для всех чисел больше 50
    PredicateConjunction P3(P1,P2); //пересечение (конъюнкция)
    PredicateDisjunction P4(P1,P2); //объединение (дизъюнкция)

    std::cout << unified_do_count(&numbers[0],&numbers[N],P1) << std::endl;
    std::cout << unified_do_count(&numbers[0],&numbers[N],P2) << std::endl;
    std::cout << unified_do_count(&numbers[0],&numbers[N],P3) << std::endl;
    std::cout << unified_do_count(&numbers[0],&numbers[N],P4) << std::endl;

    delete[] numbers;

    return 0;
}