#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <deque>
#include <cmath>

template <typename ComparableType, typename IntervalType>
void add_right(ComparableType const* const beg, ComparableType const* const end,
    IntervalType min, IntervalType max, std::deque<ComparableType> &Dout) {
    for (auto it = beg; it != end; ++it)
        if (*it >= min && *it <= max) 
            Dout.push_back(*it);

}

template <typename ComparableType, typename IntervalType>
void add_left(ComparableType const* const beg, ComparableType const* const end,
    IntervalType min, IntervalType max, std::deque<ComparableType> &Dout) {
    for (auto it = end-1; it != beg-1; --it)
        if (*it >= min && *it <= max) 
            Dout.push_front(*it);

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

    template <typename ComparableType>
    bool operator>=(ComparableType A) const {
        return (sqrt(*this)>= A);
    }

    template <typename ComparableType>
    bool operator<=(ComparableType A) const {
        return (sqrt(*this)<= A);
    }


    friend std::ostream &operator<< (std::ostream &out, point const &A) {
        out << A.x << " " << A.y << " " << A.z << " " << sqrt(A);
        return out;
    }

    friend std::istream &operator>> (std::istream &in, point &A) {
        A.x=0; A.y=0; A.z=0;
        in >> A.x >> A.y >> A.z;
        return in;
    }

};

template <typename MassiveType>
MassiveType read_d(std::ifstream &in) {
    
    MassiveType X;
    point A;

    while (in) {
        in >> A;
        if (!A.is_zero())
            X.push_back(A);
    }

    return X;
}

int main(){

    std::ifstream f_in("points_sorted.txt");

    std::vector<point> V = read_d<std::vector<point>>(f_in);

    std::cout << V.size() << std::endl;

    f_in.close();



    std::ifstream f_in_2("vector.txt");

    std::deque<point> D = read_d<std::deque<point>>(f_in_2);

    std::cout << D.size() << std::endl;

    f_in_2.close();

    add_left<point,float>(V.data(),V.data()+V.size(),800.f,900.f,D);

    add_right<point,float>(V.data(),V.data()+V.size(),200.f,300.f,D);

    std::ofstream f_out("deque.txt");

    for (auto i = V.data(); i< V.data()+V.size(); i++)
        f_out << *i << std::endl;
    
    f_out.close();

    std::cout << D.size() << std::endl;


}