#include <iostream>


class Grid {										
private:											
    float *memory;									
    size_t x_size, y_size;								
    												
public:											
    Grid(size_t x_size, size_t y_size): 
        x_size(x_size), y_size(y_size), memory(new float(x_size*y_size)) {}		

    Grid(Grid const &old_field): 
        x_size(old_field.x_size), y_size(old_field.y_size), memory(new float(old_field.x_size*old_field.y_size)) {
            for (size_t pos=0; pos!=y_size*x_size; pos++) 
                memory[pos] = old_field.memory[pos];    
        }
    

    Grid operator=(Grid const &old_field) {
        Grid tmp_field(old_field);
        std::swap(this->memory,tmp_field.memory);
        std::swap(this->x_size,tmp_field.x_size);
        std::swap(this->y_size,tmp_field.y_size);
        return *this;
    }

    ~Grid() { delete[] memory; }				
     												
    float operator()(size_t x_idx, size_t y_idx) const {
        return memory[x_idx + y_idx*y_size];   
    }
    float& operator()(size_t x_idx, size_t y_idx) {
        return memory[x_idx + y_idx*y_size];   
    }   

    size_t get_xsize() const {return x_size; }							
    size_t get_ysize() const {return y_size; }								
    												
    Grid& operator=(float);							
    												
    friend std::ostream& operator<<(std::ostream&, Grid const&);
    friend std::istream& operator>>(std::istream&, Grid &);		
};




int main(){

    Grid XY(5,1);

    XY(0,0) = 1.f;
    XY(1,0) = 2.f;
    XY(2,0) = 3.f;
    XY(3,0) = 4.f;
    XY(4,0) = 5.f;
    std::cout << XY(2,0) << std::endl;

    Grid XY_new=XY;

    std::cout << XY_new(2,0) << std::endl;

    return 0;
}
