#include <iostream>
#include <cstdlib>

using namespace std; 

unsigned do_count(int const *const beg, int const *const end) {
    unsigned cnt = 0;
    for (auto it = beg; it !=end; ++it)
        if (true) ++cnt;
    
    return cnt;
}

unsigned do_count_number(int const *const beg, int const *const end, int prob) {
    unsigned cnt = 0;
    for (auto it = beg; it !=end; ++it)
        if (*it == prob) ++cnt;
    
    return cnt;
}

unsigned do_count_in_interval(int const *const beg, int const *const end, int min, int max) {
    unsigned cnt = 0;
    for (auto it = beg; it !=end; ++it)
        if (*it >= min && *it <= max) ++cnt;
    
    return cnt;
}

int main(){

    int *numbers;
    int N=10;
	numbers = (int *) malloc(N*sizeof(int));

	for (int i=0; i<N; i++) 
        numbers[i]=100*rand()/RAND_MAX;

	for (int i=0; i<N; i++) 
        cout << numbers[i] << " " ;

    

    cout << endl;

    cout << do_count(&numbers[0],&numbers[N]) << endl;

    cout << do_count_number(&numbers[0],&numbers[N],19) << endl;

    cout << do_count_in_interval(&numbers[0],&numbers[N],0,50) << endl;

    free(numbers);
}