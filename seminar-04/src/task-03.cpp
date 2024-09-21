#include <fstream>
#include <iostream>

void universal_output(std::ostream &os, int value){
    os << value;
}

int main(int argc, const char * argv[]) {
    
    int unit = 1;

    universal_output(std::cout, unit);

    {

        std::ofstream fos;
        fos.open("./text.txt");
        universal_output(fos, unit);

    }

    return 0;
}