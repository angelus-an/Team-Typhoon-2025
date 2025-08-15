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
        int motorPins[4][3]={{0},{0},{0},{0}}; //{FL}, {Fr}, {BR}, {BL} 

};

#endif


