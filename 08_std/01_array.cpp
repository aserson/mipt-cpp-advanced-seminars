#include <iostream>
#include <fstream>
#include <array>
#include <cmath>

class point {
private:
    int x,y,z;
public:
    point(int x, int y, int z): x(x), y(y), z(z) {}

    point(): x(0), y(0), z(0) {}

    friend float sqrt(point const &A) {
        return sqrt(A.x*A.x+A.y*A.y+A.z*A.z);
    }

    bool operator>(point const &A) const {
        return sqrt(*this) > sqrt(A);
    }

    bool operator<(point const &A) const {
        return sqrt(*this) < sqrt(A);
    }

    friend std::ostream &operator<< (std::ostream &out, point const &A) {
        out << A.x << " " << A.y << " " << A.z;
        return out;
    }

    friend std::istream &operator>> (std::istream &in, point &A) {
        in >> A.x >> A.y >> A.z;
        return in;
    }

};


std::array<point,10000>& sort(std::array<point,10000> &A) {
    for (int i1 = 0; i1 < A.size()-1; i1++)    
        for (int i2 = i1+1; i2 < A.size(); i2++)    
            if (A[i2] > A[i1]) std::swap(A[i1],A[i2]);
    
    return A;
    
}

int main(){


    std::array<point,10000> P;

    std::ifstream f_in("points.txt");

    for (int i=0; i<P.size(); ++i)  {
        f_in >> P[i];
    }
    
    f_in.close();

    P=sort(P);

    std::ofstream f_out("points_sorted.txt");

    for (int i=0; i<P.size(); ++i)  
        f_out << P[i] << std::endl;
    
    f_out.close();

}