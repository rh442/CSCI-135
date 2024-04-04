/*
Author: Raymond Huang
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Lab9A

This code calculate position of particle at a certain time given position and velocity
*/
// dynamically allocate memory for a particle and initialize it
#include <iostream>
using namespace std;
class Coord3D {
public:
    double x;
    double y;
    double z;
};
class Particle{
    public:
    Coord3D pos;
    Coord3D vel;

};
Particle* createParticle(double x, double y, double z,double vx, double vy, double vz){
    Particle *p = new Particle;
    p->pos={x,y,z};
    p->vel={vx,vy,vz};
    return p;


                         }
// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
    p->vel={vx,vy,vz};
    

}
// get its current position
Coord3D getPosition(Particle *p){
    return p->pos;


}
// update particle's position after elapsed time dt
void move(Particle *p, double dt){
    p->pos.x = p->pos.x + dt*(p->vel.x);
    p->pos.y = p->pos.y + dt*(p->vel.y);
    p->pos.z = p->pos.z + dt*(p->vel.z);

}
// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
    delete p;

}
int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}