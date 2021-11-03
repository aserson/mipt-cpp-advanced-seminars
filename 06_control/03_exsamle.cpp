//пример создания буфера памяти с деконструтором
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

    AutoBuffer<float> buf_float(1);
    buf_float[0] = 5.f;

}