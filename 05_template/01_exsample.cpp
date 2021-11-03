
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

//Шаблон счётчика чисел из последовательности, лежащих в интервале [min,max]
template <typename ComparableType>
unsigned do_count_in_interval(ComparableType const* const beg, ComparableType const* const end,
    ComparableType min, ComparableType max) {
    unsigned cnt = 0;
    for (auto it = beg; it != end; ++it)
        if (*it >= min && *it <= max) ++cnt;

    return cnt;
}

//Шаблон счётчика чисел из последовательности, лежащих в интервале [min,max], для разных типов последовательности и границ интервала
template <typename ComparableType, typename IntervalType>
unsigned do_count_in_interval_various_types(ComparableType const* const beg, ComparableType const* const end,
    IntervalType min, IntervalType max) {
    unsigned cnt = 0;
    for (auto it = beg; it != end; ++it)
        if (*it >= min && *it <= max) ++cnt;

    return cnt;
}

//Шаблон счётчика чисел из последовательности, лежащих в интервале [min,max]
template <typename ComparableType, int min = 20, int max = 52>
unsigned do_count_in_interval_non_type_parametrs(ComparableType const* const beg, ComparableType const* const end) {
    unsigned cnt = 0;
    for (auto it = beg; it != end; ++it)
        if (*it >= min && *it <= max) ++cnt;

    return cnt;
}


//Шаблон фукнции-генератора последовательности чисел с выводом последовательности
template <typename TYPE>
TYPE* rand_n(int const n, TYPE const rand_ax) {
    TYPE* rand_out = new TYPE[n];
    cout.setf(ios::fixed);
    cout << "[";
    for (auto it = 0; it != n; ++it) {
        rand_out[it] = (rand_ax * rand() / RAND_MAX);
        cout << setw(4) << setprecision(1) << left << rand_out[it] << " ";
    }
    cout << "]" << endl;
    return rand_out;
    free(rand_out);
}



int main() {

    int N = 10;
    int* int_numbers;
    float* float_numbers;
    
    cout << "Subsequence of integers S1:" << endl;
    int_numbers = rand_n(N, 100);
    cout << endl;

    cout << "Subsequence of floats S2:" << endl;
    float_numbers = rand_n(N, 100.f);

    cout << endl;

    cout << setw(50) << "Numbers of elements in S1 in interval [0, 50]:";
    cout << do_count_in_interval(&int_numbers[0], &int_numbers[N], 0, 50) << endl ;

    cout << setw(50) << "Numbers of elements in S2 in interval [0, 40]:";
    cout << do_count_in_interval_various_types(&float_numbers[0], &float_numbers[N], 0, 40) << endl ;

    cout << setw(50) << "Numbers of elements in S2 in interval [20, 70]:";
    cout << do_count_in_interval_non_type_parametrs<float, 20, 70>(&float_numbers[0], &float_numbers[N]) << endl;

    free(int_numbers); free(float_numbers);

    return 0;
}