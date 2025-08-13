#include <PID.h>


void PID::PID(double p, double i, double d, double absolute_maximum){
    //pinMode -> sets pin to a particular Mode --> pinMode(digital pin, input [if sensor], output [if motor])
    P = p;
    I = i;
    D = d;
    absolute_max = absolute_maximum;
    last_update = micros(); //time since boot-up of teensy
    last_current = 0;
}

double PID::update(double current, double goal){
    double elapsed_time=(micros()-last_update)/1000000.0;
    double error = goal - current;
    double derivative = (current - last_current)/elapsed_time;
    double integral = elapsed_time*error;
    last_current = current;
    last_update = micros();
    double correction = (P*error)-(D*derivative)+(I*integral);
    if (abs(correction)>abs(absolute_max)){
        correction *= (absolute_max/abs(correction));
    }
    return correction;
}