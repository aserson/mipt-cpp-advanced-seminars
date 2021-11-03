#include <iostream>
#include <cstdlib>  //для rand()
#include <ctime>    //для time()
using namespace std; 

class Predicate { //интерфейс -- класс, содержащий только чисто виртуальные методы 
public:
    virtual bool operator()(int prob) const { //virtual -- дает в дальнейшем изменять наследников класса
        return true;
    }
};

class ValuePredicate: public Predicate {
private:
    int const val;
public:
    ValuePredicate(int val): val(val) { }
    bool operator()(int prob) const {
        return val == prob;
    }
};

class IntervalPredicate: public Predicate {
private:
    int const min,max;
public:
    IntervalPredicate(int min, int max): min(min), max(max) { }
    bool operator()(int prob) const {
        return prob >= min && prob <= max;
    }
};

//обобщеная функция подсчёта
unsigned unified_do_count(int const *const beg, int const *const end, Predicate const &predicate) { //const -- данным метод гарантирует, что не будет изменять внутреннее состояние
    unsigned cnt = 0;
    for (const int * it = beg; it !=end; ++it)
        if (predicate(*it)) ++cnt;
    
    return cnt;
}

int main(){

    srand(time(nullptr));  //задаем зерно гернирации псевдослучайных чисел

    int *numbers;
    int N=10;
	numbers = (int *) malloc(N*sizeof(int));

	for (int i=0; i<N; i++) 
        numbers[i]=100*rand()/RAND_MAX;

	for (int i=0; i<N; i++) 
        cout << numbers[i] << " " ;

    cout << endl;

    Predicate P1;                   //предикатор для всех чисел в последовательности 
    ValuePredicate P2(19);          //предикатор для всех чисел равных 19
    IntervalPredicate P3(0,50);     //предикатор для всех чисел в промежутке между 0 и 50

    cout << unified_do_count(&numbers[0],&numbers[N],P1) << endl;

    cout << unified_do_count(&numbers[0],&numbers[N],P2) << endl;

    cout << unified_do_count(&numbers[0],&numbers[N],P3) << endl;

    free(numbers);
}