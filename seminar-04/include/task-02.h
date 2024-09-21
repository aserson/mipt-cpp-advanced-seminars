#include <fstream>

void file_input() {
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
}
