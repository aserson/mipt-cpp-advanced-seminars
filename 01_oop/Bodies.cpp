#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class MathPoint {
private:
    float const x, y;

public:
    MathPoint(float x, float y): x(x), y(y) { }

    float distance(MathPoint const &p) {
        return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
    }
};

class MassiveBody: public MathPoint {
private:
    float const mass;

public:
    MassiveBody(float mass, float x, float y): MathPoint(x,y), mass(mass) { }
    
    float acceleration(float force) {
        return force/mass;
    }
    
};

class ChargedMass: public MassiveBody {
private:
    float charge;

public:
    ChargedMass(float charge, float mass, float x, float y): MassiveBody(mass,x,y), charge(charge) { }

    float electric_acceleration (ChargedMass const &chm) {
        return acceleration(charge * chm.charge / distance(chm));
    }    
    
};

int main() {

    ChargedMass e1(1.0,1.0,0.0,0.0);
    ChargedMass e2(-1.0,1.0,1.0,1.0);
    cout << e1.distance(e2) << endl;

}