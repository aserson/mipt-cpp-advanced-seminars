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
        list(): first(nullptr), last(nullptr) {}
        
        list(list const &&l_old): list() {
            node *p = l_old.first;
            while (p) {
                push_back(p->number);
                p=p->next;
            }
        }
        
        ~list(){
            if (is_empty()) 
                return;

            node *p = first;
            node *tmp;
            
            while (p) {
                tmp = p->next;
                delete p;
                p = tmp;
            }
                        
        }

        list operator=(list const &l_old) {
            list tmp(l_old);

            node *p = first;
            node *p_tmp;
            
            while (p) {
                p_tmp = p->next;
                delete p;
                p = p_tmp;
            }

            return tmp;
        }

        bool is_empty(){
            return first==nullptr;
        }
        
        void push_back(int val) {
            node *p = new node(val);
            if (is_empty()) {
                first = p;
                last = p;
                return;
            }
            last->next = p;
            last = p;
        }

        void print(){
            if (is_empty()) 
                return;

            node *p = first;
            while (p) {
                std::cout << p->number << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }

};


int main(){

    list l;
    l.push_back(1);    
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    list l_new(l);

    l.push_back(7);
    l_new.push_back(8);

    
    list l_new2=l;
    l_new2.push_back(9);

    l.print();
    l_new.print();
    l_new2.print();

    
    return 0;
}