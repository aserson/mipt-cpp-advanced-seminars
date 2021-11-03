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
    //конструирование списка
    std::list<std::string> lst = {"Norton", "Heinlein", "Harrison"};


    //доступ к элементам 
    std::cout << lst.front() << " " << lst.back() << std::endl;

    auto it = lst.begin();
    std::cout << *++it << std::endl;

    std::cout << lst << std::endl;

    //вставка элементов
    lst.push_front("Bradbury");
    lst.push_back("Herbert");

    std::cout << lst;

    lst.insert(++lst.begin(),"Asimov");
    std::cout << lst << std::endl;

    //удаление элементов

    lst.pop_back();
    std::cout << lst;
    
    lst.pop_front();
    std::cout << lst;

    lst.erase(++lst.begin(), --lst.end());
    std::cout << lst;

    lst.clear();
    std::cout << lst << std::endl;
}