#ifndef ATTACK_H
#define ATTACK_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>
#include <Common.h>
#include <Camera.h>


class Attack {
    public:
        Attack(){};
        float virtual_x;
        float virtual_y;
        float orbit(const float camera_values[array_length]); //returns virtual point needed for orbit
    private:

};



#endif




