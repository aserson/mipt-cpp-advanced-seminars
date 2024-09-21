#include <iostream>

template <typename T>
class UniqueResourse { //ресурс, который нельзя копировать
private:
    T *u_ptr = nullptr;
public:
    explicit UniqueResourse(T *resourse): u_ptr(resourse) { }
    UniqueResourse(): u_ptr(nullptr) { }
    ~UniqueResourse() { if (u_ptr) delete u_ptr; }

    UniqueResourse(UniqueResourse<T> const &src) = delete;
    UniqueResourse<T>& operator=(UniqueResourse<T> const &src) = delete;

    UniqueResourse(UniqueResourse<T> &&src);
    UniqueResourse<T>& operator=(UniqueResourse<T> const &&src);

    T* get_resource() const {
        return u_ptr;
    }

};

template <typename T>
UniqueResourse<T>::UniqueResourse(UniqueResourse<T> &&src): u_ptr(src.u_ptr) {
    src.u_ptr = nullptr;    
}

//move and swap
template <typename T>
UniqueResourse<T>& UniqueResourse<T>::operator=(UniqueResourse<T> const &&src) {
    UniqueResourse<T> tmp(std::move(src));
    std::swap(this->u_ptr, tmp.u_ptr);
}

template <typename T>
void unique_resourse_print(UniqueResourse<T> const &ur) {
    if (ur.get_resource() == nullptr)
        std::cout << "Resource is empty" << std::endl;
    else
        std::cout << "Resource contains " << *ur.get_resource() << std::endl;
}

int main(){

    UniqueResourse<int> ur(new int(5));
    unique_resourse_print<int>(ur);
    {
        UniqueResourse<int> ur_moved=std::move(ur);
        unique_resourse_print<int>(ur);
        unique_resourse_print<int>(ur_moved);
    }

    return 0;
}