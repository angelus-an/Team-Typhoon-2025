#ifndef PID_H
#define PID_H

#include <Arduino.h>
#include <math.h>


class PID{
    public:
        PID(double p, double i, double d, double absolute_maximum);
        double update(double current, double goal); //takes in current value and the goal and returns the correction
    private:
        double P; 
        double I;
        double D;
        double absolute_max;
        unsigned long last_update;
        double last_current
};

#endif
