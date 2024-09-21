//пример создания буфера памяти с деконструтором и констрктором копирования
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

    AutoBuffer(AutoBuffer const &src): AutoBuffer(src.buffer_size) {
        for (size_t pos = 0; pos != buffer_size; ++pos)
            buffer[pos] = src.buffer[pos];
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

    AutoBuffer<float> buf_float_1(1);
    buf_float_1[0] = 5.f;

    std::cout << buf_float_1[0] << std::endl;

    AutoBuffer<float> buf_float_2(buf_float_1);

    std::cout << buf_float_2[0] << std::endl;


}