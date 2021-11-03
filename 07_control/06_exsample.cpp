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

int main(){

    AutoBuffer<float> buf_float_1(2);
    buf_float_1[0] = 5.42366745;
    buf_float_1[1] = 3.42366215;

    std::cout << buf_float_1[0] << std::endl;
    std::cout << buf_float_1[1] << std::endl;

    AutoBuffer<float> buf_float_2(buf_float_1);

    std::cout << buf_float_2[0] << std::endl;
    
    AutoBuffer<float> buf_float_3 = buf_float_1;

    std::cout << buf_float_2[0] << std::endl;


}