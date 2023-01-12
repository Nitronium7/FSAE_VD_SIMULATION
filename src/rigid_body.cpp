#ifndef RIGID_BODY_CPP_
#define RIGID_BODY_CPP_
#include <vector>
#include "force.cpp"
using namespace std;
#include "glm/gtc/type_ptr.hpp"

#include "vec.cpp"
class RigidBody{
private:
    double mass;
    Vec momentInertia;
    Vec position;
    Vec velocity;
    Vec acceleration;
    Vec aposition;
    Vec avelocity;
    Vec aacceleration;

    //the hardpoints are as listed:

    vector<Vec> hardpoints;
    vector<Vec> movingHardpoints;
    vector<Force> forces;
public:
//constructor
    RigidBody(double massI, Vec momentInertiaI, Vec positionI, Vec velocityI, Vec
    accelerationI, Vec apositionI, Vec avelocityI, Vec 
    aaccelerationI, vector<Force> forcesI, vector<Vec> hardpointsI){
        mass = massI;
        momentInertia = momentInertiaI;
        position = positionI;
        velocity = velocityI;
        acceleration = accelerationI;
        aposition = apositionI;
        avelocity = avelocityI;
        aacceleration = aaccelerationI;
        forces = forcesI;
        hardpoints = hardpointsI;
    }
    Vec getP(){
        return position;
    }
    Vec getV(){
        return velocity;
    }
    Vec getA(){
        return acceleration;
    }
    Vec getAP(){
        return aposition;
    }
    Vec getAV(){
        return avelocity;
    }
    Vec getAA(){
        return aacceleration;
    }
    void setP(Vec posI){
        position = posI;

    }
    void setV(Vec velocityI){
        velocity = velocityI;

    }
    void setA(Vec accelerationI){
        acceleration = accelerationI;

    }
    void setAP(Vec apositionI){
        aposition = apositionI;

    }
    void setAV(Vec avelocityI){
        avelocity = avelocityI;

    }
    void setAA(Vec aaccelerationI){
        aacceleration = aaccelerationI;

    }
    void addForce(Force input){
        forces.push_back(input);
    }
    void clearForce(){
        forces.clear();
    }
    //moves the body of the vehicle
    void move(double timeIncr){
        Vec directions;
        Vec moments;
        directions = Force::dSum(forces);
        moments = Force::mSum(forces);
        
        for (int i = 0; i<3; i++){
            acceleration.set(directions.get(i) /mass, i);
            velocity.set(velocity.get(i) +acceleration.get(i), i);
            position.set(position.get(i) +velocity.get(i), i);
            aacceleration.set(moments.get(i)/momentInertia.get(i), i);
            avelocity.set(avelocity.get(i) +aacceleration.get(i), i);
            aposition.set(aposition.get(i) +avelocity.get(i), i);
        }
        float a = aposition.get(0);
        float b = aposition.get(1);
        float c = aposition.get(2);
        float rot[9] = {
  cos(b)*cos(c), sin(a)*sin(b)*cos(c)-cos(a)*sin(c), cos(a)*sin(b)*cos(c)+sin(a)*sin(c),
  cos(b)*sin(c), sin(a)*sin(b)*sin(c)+cos(a)*cos(c), cos(a)*sin(b)*sin(c)+sin(a)*cos(c),
  -sin(b), sin(a)*cos(b), cos(a)*cos(b)
};
glm::mat3 rotM = glm::make_mat4(rot);

        for (size_t i = 0; i <hardpoints.size(); i++){
            
            movingHardpoints.push_back(Vec(rotM*hardpoints.at(i).get()));
        }
        forces.clear();
    }
};
#endif