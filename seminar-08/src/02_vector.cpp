#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cmath>

template <typename ComparableType, typename IntervalType>
std::vector<ComparableType> array_to_vector(ComparableType const* const beg, ComparableType const* const end,
    IntervalType min, IntervalType max) {
    std::vector<ComparableType> Vout;
    auto Cap = Vout.capacity();
    for (auto it = beg; it != end; ++it)
        if (*it >= min && *it <= max) {
            Vout.push_back(*it);
            if (Cap != Vout.capacity()) { 
                std::cout << Vout.size() << " " << Vout.capacity() << std::endl;
                Cap = Vout.capacity();
            }
        }
    return Vout;
}

class point {
private:
    int x,y,z;
public:
    point(int x, int y, int z): x(x), y(y), z(z) {}

    point(): x(0), y(0), z(0) {}

    bool is_zero() {
        return ((x==0)&&(y==0)&&(z==0));
    }

    friend float sqrt(point const &A) {
        return sqrt(A.x*A.x+A.y*A.y+A.z*A.z);
    }

    bool operator>=(point const &A) const {
        return (sqrt(*this)>= sqrt(A));
    }

    bool operator<=(point const &A) const {
        return (sqrt(*this)<= sqrt(A));
    }

    template <typename IntervalType>
    bool operator>=(IntervalType A) const {
        return (sqrt(*this)>= A);
    }

    template <typename IntervalType>
    bool operator<=(IntervalType A) const {
        return (sqrt(*this)<= A);
    }


    friend std::ostream &operator<< (std::ostream &out, point const &A) {
        out << A.x << " " << A.y << " " << A.z;
        return out;
    }

    friend std::istream &operator>> (std::istream &in, point &A) {
        A.x=0; A.y=0; A.z=0;
        in >> A.x >> A.y >> A.z;
        return in;
    }

};

std::vector<point> read_v(std::ifstream &in) {
    
    std::vector<point> V;
    point A;

    while (in) {
        in >> A;
        if (!A.is_zero()) 
            V.push_back(A);
            
    }

    return V;
}

int main(){


    std::ifstream f_in("points_sorted.txt");

    std::vector<point> V = read_v(f_in);

    std::cout << V.size() << std::endl;

    f_in.close();

    
    std::vector V2 = array_to_vector<point,float>(V.data(),V.data()+V.size(),500.f,600.f);


    std::ofstream f_out("vector.txt");

    for (int i=0; i<V2.size(); ++i)  
        f_out << V2[i] << std::endl;
    
    f_out.close();

    std::cout << V2.size() << std::endl;
    

    
}