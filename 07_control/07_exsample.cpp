//пример создания буфера памяти с деконструтором, констрктором копирования, копирование присваивания
//конструктором перемещения и перемещение присваивания
#include <iostream>

template <typename TYPE>
class AutoBuffer {
private:
    TYPE *buffer;
    size_t buffer_size;
public:
    AutoBuffer(): buffer(nullptr), buffer_size(0) {}

    AutoBuffer(size_t buffer_size): 
        buffer_size(buffer_size), 
        buffer(new TYPE[buffer_size]) { }

    //деструктор        
    ~AutoBuffer() { if (buffer) delete[] buffer; }

    //конструктор копирования
    AutoBuffer (AutoBuffer const &src): AutoBuffer(src.buffer_size) {
        for (size_t pos = 0; pos != buffer_size; ++pos)
            buffer[pos] = src.buffer[pos];
    }

    //копирование присваивание 
    AutoBuffer<TYPE>& operator=(AutoBuffer<TYPE> const &src) {
        AutoBuffer<TYPE> tmp(src);
        std::swap(this->buffer,tmp.buffer);
        std::swap(this->buffer_size,tmp.buffer_size);
    }

    //конструктор перемещения
    AutoBuffer (AutoBuffer<TYPE> &&src): AutoBuffer() {
        std::swap(this->buffer,src.buffer);
        std::swap(this->buffer_size,src.buffer_size);
    }

    //перемещение присваивание 
    AutoBuffer operator=(AutoBuffer const &&src) {
        AutoBuffer<TYPE> tmp(std::move(src));
        std::swap(this->buffer,tmp.buffer);
        std::swap(this->buffer_size,tmp.buffer_size);
    }

    TYPE& operator[](size_t idx) {
        return buffer[idx];
    }

    TYPE operator[](size_t idx) const {
        return buffer[idx];
    }

    size_t size() const {
        return buffer_size;
    }
};

struct Point {
    float x,y;
};

class Route {
private:
    int id;
    AutoBuffer<Point> route;

public:
    Route(int id, size_t route_size): id(id), route(route_size) { }
    
    Route(Route const &src)  = default;
    Route& operator=(Route &stc) = default;
    Route(Route &&) = default;
    Route& operator=(Route &&) = default;

    Point& operator[](size_t idx) {return route[idx]; }
    Point operator[](size_t idx) const {return route[idx]; }
    int get_id() const { return id; }

};

int main(){

    Route r(5,2);
    r[0] = {1.f, 1.f};
    r[1] = {2.f, 2.f};

    Route r2(std::move(r));

    std::cout << r2.get_id() << std::endl;

    return 0;
}