#include <iostream>

int main(){

    int n,k;
    n = 23;
    k = 32;


    std::cout << "n = " << n << "   k = " << k << std::endl;

    std::cout << "Swapping..." << std::endl;

    std::swap(n,k);

    std::cout << "n = " << n << "   k = " << k << std::endl << std::endl;

    int *a,*b;
    int N = 10;

    a = new int[N];
    std::cout << "a = [ ";
    for (int i = 0; i < N; i++) {
        a[i] = i+1;
        std::cout << a[i] << " ";
    }
    std::cout << "]" << std::endl;

    
    b = new int[N];
    std::cout << "b = [ ";
    for (int i = 0; i < N; i++) {
        b[i] = N-i;
        std::cout << b[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::swap(b,a);
    
    std::cout << "Swapping..." << std::endl;

    std::cout << "a = [ ";
    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "b = [ ";
    for (int i = 0; i < N; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << "]" << std::endl;

}