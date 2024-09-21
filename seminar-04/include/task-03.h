#include <fstream>
#include <iostream>

void universal_output(std::ostream &os, int value){
    os << value;
}

void universal_stream_output() {
    
    int unit = 1;

    universal_output(std::cout, unit);

    {
        std::ofstream fos;
        fos.open("./text.txt");
        universal_output(fos, unit);

    }
}