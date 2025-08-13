#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>

class Motors{
    public:
        void init();
        void update(int speed[4]);
        Motors(){}
        void move(int speed, int direction, int rotation);
    private:
        int motorPins[4][3]={{0},{0},{0},{0}}; //{FL}, {Fr}, {BR}, {BL} 

};

#endif


