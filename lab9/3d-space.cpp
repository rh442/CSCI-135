
/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab9A

This code computes the distanc from a point to an origin in a 3D space
*/

#include <iostream>
#include <math.h>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};
double length(Coord3D *p){
    double a = pow(p->x,2);
    double b = pow(p->y,2);
    double c = pow(p->z,2);
    double sum= a+b+c;
    double total=sqrt(sum);
    return total;

}
Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1)>length(p2)){
        return p1;
    }
    else{
        return p2;
    }
    

}
void move(Coord3D*p,Coord3D*v, double dt){
    p->x = p->x + dt*(v->x);
    p->y = p->y + dt*(v->y);
    p->z = p->z + dt*(v->z);


}
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *p = new Coord3D;
    p->x=x;
    p->y=y;
    p->z=z;

    return p;

    
}

// free memory
void deleteCoord3D(Coord3D *p){
    delete p;
}
int main() {
   double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}