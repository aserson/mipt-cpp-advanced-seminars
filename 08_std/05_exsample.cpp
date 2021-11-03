//пример написания итератора для класса-контейнера 
#include <iostream>
#include <fstream>
#include <cmath>

template <typename T, size_t N>
class MArrayIterator;

template <typename T, size_t N>
class MArray {
private:
    T elements[N];
public:
    MArray() = default;
    MArray(MArray<T,N> const &src) = default;
    MArray(MArray<T,N> &&src) = default;
    MArray<T,N>& operator=(MArray<T,N> const &src) = default;
    MArray<T,N>& operator=(MArray<T,N> &&src) = default;

    friend MArrayIterator<T,N>;

    MArrayIterator<T,N> begin() {
        return MArrayIterator<T,N>(*this,0);
    }
    
    MArrayIterator<T,N> end() {
        return MArrayIterator<T,N>(*this,N);
    }
};

template <typename T, size_t N>
class MArrayIterator {
private:
    MArray<T,N> &ma;
    size_t pos;         //стартовая позиция
public:
    explicit MArrayIterator(MArray<T,N> &ma): MArrayIterator(ma, 0) { }
    MArrayIterator(MArray<T,N> &ma, size_t pos): ma(ma), pos(pos) { }
    MArrayIterator(MArrayIterator<T,N> const &src) = default;
    MArrayIterator& operator=(MArrayIterator<T,N> const &src) = default;

    T& operator*() const {
        return ma.elements[pos];
    }

    MArrayIterator<T,N>& operator++() {
        ++pos;
        return *this;
    }

    bool operator!=(MArrayIterator<T,N> const &rha) const {
        return !(&ma == &rha.ma && pos == rha.pos);
    }
};

int main(){
    
    MArray<int,3> a; 

    {
        auto it = a.begin();
        *it = 1;
        *++it = 2;
        *++it = 3;
    }
    for (auto it = a.begin(); it != a.end(); ++it)
        std::cout << *it << ' ';
    
    std::cout << std::endl;

}