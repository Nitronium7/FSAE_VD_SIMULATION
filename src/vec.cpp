//USING FOUND VECTORS FUNCTIONS
//MAKE EVERYTHING VEC type
//IMPLEMENT DOT/CROSS PRODUCTS FOR VEC TYPE
//SPRUNG BODY SHOULD ONLY HAVE 2 DEGREES OF FREEDOM, OK TO IMPLEMENT ALL, BUT SHOULD BE RIGID BODY TYPE INSTEAD

#ifndef VEC_CPP_
#define VEC_CPP_
#include "glm/glm.hpp"
#include <tgmath.h>
#include <math.h>
#include <stdexcept>
#include <iostream>
#include <array>
#include <vector>
using namespace std;
#define vec3 glm::dvec3
#define n 3
#define PI 3.1415926535

// Function that return
// dot product of two vector array.


class Vec{

private:
    vec3 storedVec = {0,0,0};
public:
    Vec(vec3 newVec) {
        set(newVec);
    }
    Vec(double x, double y, double z){
        storedVec = {x,y,z};
    }
    Vec(){
        storedVec = {0,0,0};
    }
    vec3 get(){
        return storedVec;
    }
    double get(int component){
        return storedVec[component];
    }
    void set(vec3 newValue){
        storedVec = newValue;
    }
    void set(double newValue, int component){
        storedVec[component] = newValue;
    }

    static Vec add(Vec vectA, Vec vectB){
        return Vec(vectA.get(0)+vectB.get(0), vectA.get(1)+vectB.get(1), vectA.get(2)+vectB.get(2));
    }
    static double dotProduct(Vec vectA, Vec vectB)
    {
        return glm::dot(vectA.get(), vectB.get());
    }
    static Vec crossProduct(Vec vectA, Vec vectB){
        return Vec(glm::cross(vectA.get(), vectB.get()));
    }
// Function to find
// cross product of two vector array.
//returns polar in the form, radius, theta, phi with phi in z direction

    static float getPhi(float y, float x)
    {
        if (x == 0.0) {
            if (y == 0.0) {
                return 0.0;
            } else if (y > 0.0) {
                return PI/2.0;
            } else {
                return -1.0 * PI/2.0;
            }
        } else if (x > 0.0) {
            return atan(y/x);
        } else if (x < 0.0) {
            if (y >= 0.0) {
                return atan(y/x) + PI;
            } else {
                return atan(y/x) + PI;
            }
        }
    }


    static Vec toPolar(Vec cart)
    {
        float xySquared = (cart.get(0) * cart.get(0)) + (cart.get(1) * cart.get(1));
        float radius = sqrt(xySquared + (cart.get(2) * cart.get(2)));
        return Vec(radius, atan(sqrt(xySquared)/cart.get(2)), getPhi(cart.get(1), cart.get(0)));
    }

    static Vec toCartesian(Vec sph) {
        return Vec(
            sin(sph.get(1)) * cos(sph.get(2)) * sph.get(0),
            sin(sph.get(1)) * sin(sph.get(2)) * sph.get(0),
            cos(sph.get(1)) * sph.get(0)
        );
    }
};




#endif