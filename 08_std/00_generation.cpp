#include <iostream>
#include <fstream>
#include <array>

class point {
private:
    int x,y,z;
public:
    point(int x, int y, int z): x(x), y(y), z(z) {}

    point() {
        x = rand() % 2000 - 1000;
        y = rand() % 2000 - 1000;
        z = rand() % 2000 - 1000;
    }

    friend std::ostream &operator<< (std::ostream &out, point const &A) {
        out << A.x << " " << A.y << " " << A.z;
        return out;
    }

};


int main(){

    srand(time(nullptr));

    std::array<point,10000> P;

    std::ofstream f_out("points.txt");

    for (int i=0; i<P.size(); ++i)  {
        f_out << P[i] << std::endl;
        std::cout << P[i] << std::endl;
    }
    
    f_out.close();
}