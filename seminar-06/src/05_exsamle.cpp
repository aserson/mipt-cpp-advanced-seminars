//пример создания буфера памяти с деконструтором, констрктором копирования и копирование присваивания
#include <iostream>

template <typename TYPE>
class AutoBuffer {
private:
    TYPE *buffer;
    size_t buffer_size;
public:
    AutoBuffer(size_t buffer_size): 
        buffer_size(buffer_size), 
        buffer(new TYPE[buffer_size]) { }

    AutoBuffer (AutoBuffer const &src): AutoBuffer(src.buffer_size) {
        for (size_t pos = 0; pos != buffer_size; ++pos)
            buffer[pos] = src.buffer[pos];
    }

    AutoBuffer operator=(AutoBuffer const &src) {
        AutoBuffer<TYPE> tmp(src);
        std::swap(this->buffer,tmp.buffer);
        std::swap(this->buffer_size,tmp.buffer_size);
    }

    ~AutoBuffer() { delete[] buffer; }

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