#ifndef FORCE_CPP_
#define FORCE_CPP_
#include <math.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "vec.cpp"
#include <tuple>
class Force{
private:
    Vec dir;
    Vec pos;
    double mag =0;
public:
    Force(Vec dirI, Vec posI, double magI) {
        dir = dirI;
        pos = posI;
        mag = magI;
    }
    Force(){
    }
    void setD(Vec dirI){
        dir = dirI;
    }
    void setP(Vec posI){
        pos = posI;
    }
    void setM(double magI){
        mag = magI;
    }
    Vec getD(){
        return dir;
    }
    Vec getP(){
        return pos;
    }
    double getM(){
        return mag;
    }
    double getD(int component){
        return dir.get(component);
    }
    double getP(int component){
        return pos.get(component);
    }
    Force inv(){
        Force inverted;
        Vec direction;

        for (int i=0; i<3;i++){
            direction.set(i, -dir.get(i));
        }
        inverted.setD(direction);
        inverted.setP(pos);
        inverted.mag = mag;
        return inverted;        
    }

    void norm(){
        double sum=0;
        for (int i=0; i<3; i++){
            sum+=pow(dir.get(i), 2);
        }
        for (int i = 0; i<3; i++){
            dir.set(i,dir.get(i)/pow(sum, 0.5));
        }
        mag = mag*pow(sum, 0.5);
    }
    static Vec mSum(vector<Force> forces){
        Vec momentsSum;
        Force temp;
        for (size_t i= 0; i<forces.size();i++){
            temp = forces.at(i);
            momentsSum = Vec::add(momentsSum, Vec::crossProduct(temp.getP(), temp.getD()));
        }
        return momentsSum;
    }

    static Vec dSum(vector<Force> forces){
        Force temp;
        Vec directions;
        for (size_t i= 0; i<forces.size();i++){
            temp = forces.at(i);
            for (int j = 0; j<3;j++){
                directions.set(j, directions.get(j)+temp.getD(j)*temp.getM());
            }
        }
        return directions;
    }
    

};
#endif