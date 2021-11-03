#include <iostream>

struct node {
    int number;
    node* next;

    node(int val) : number(val), next(nullptr) {}
};

class list {

    private:    
        node* first;
        node* last;

    public:
        list(): first(nullptr), last (nullptr) {}

        list(list const &l_old);
        list operator=(list const &l_old);
        ~list();

        bool is_empty();            //Оператор проверки наличия первого элемента
        void push_back(int val);    //Оператор добавление элемента в конец списка
        void print();

        list inverse();

};


int main(){

    list l;
    
    
    
    return 0;
}