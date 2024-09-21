#include <task-04.h>

int main(){
    PolynomialFunction f; //f=0
    LinearFunction l(1.0,1.0); //l=x+1
    QuadraticFunction q(1.0,1.0,1.0); //q=x^2+x+1

    polymorphic_call(f, 1.0);
    polymorphic_call(l, 1.0);
    polymorphic_call(q, 1.0);

    return 0;
}
