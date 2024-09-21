#include <iostream>
#include <list>

template <typename T>
std::ostream& operator<<(std::ostream &os, std::list<T> const &lst) {
    for(auto &e : lst)
        std::cout << e << " ";
    std::cout << std::endl;
    return os;
}       

int main() {
    std::list<std::string> lst = {"Norton", "Harrison", "Heinlein", "Harrison", "Asimov", "Bradbury"};


    //специальные методы
    //не проиходит перемещение элементов, изменяется ссылочная структура списка  
    lst.sort();
    std::cout << lst << std::endl;

    lst.reverse();
    std::cout << lst << std::endl;

    lst.remove("Heinlein");
    std::cout << lst << std::endl;

    struct {
        bool operator()(std::string const &s) const {
            return 'N' == s[0];
        }
    } pred;
    lst.remove_if(pred);
    std::cout << lst << std::endl;

    lst.unique(); //удаляет повторяющиеся объекты
    std::cout << lst << std::endl;


    
}