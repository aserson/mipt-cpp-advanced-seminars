#include <fstream>

int main(int argc, const char * argv[]) {
    
    int unit = 1;
    char symbol = '!';

    {

        std::ofstream fos;
        fos.open("./text.txt");

        fos << unit;
        fos << symbol;
    
        fos.flush(); //принудительная передача данных из буфера

        fos.close();
    

    }

    return 0;
}