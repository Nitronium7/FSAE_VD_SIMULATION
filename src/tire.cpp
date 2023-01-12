//hard coded slip angle function

class Tire{

private:
    double mass;
    double moment;
    double rad;
    double width;
    double psi;
    double ang_acc;//angular velocity and acceleration
    double ang_vec;
    double ang_pos;//in radians, 0 is straight
    double normal;
    double lat;
    double lon;
    double torq;
    double coeF;
public:
    Tire(double massI, double momentI, double radI, double widthI, double psiI, double coeFI){
    mass = massI;
    moment = momentI;
    rad = radI;
    width = widthI;
    psi = psiI;
    coeF = coeFI;
    ang_acc = 0;
    ang_vec = 0;
    ang_pos = 0;
    normal = 0;
    lat = 0;
    lon = 0;
    torq = 0;
    }
    
    };