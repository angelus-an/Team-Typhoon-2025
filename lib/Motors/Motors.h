#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>

class Motors{
    public:
        void init();
        void update(float speed[4]);
        Motors(){}
        void move(float speed, float  direction, float rotation);
    private:
        int motorPins[4][3]={{(FL_INA), (FL_INB), (FL_PWM)},{(FR_INA), (FR_INB), (FR_PWM)},{(BR_INA), (BR_INB), (BR_PWM)},{(BL_INA), (BL_INB), (BL_PWM)}}; //{FL}, {Fr}, {BR}, {BL} 

};

#endif


