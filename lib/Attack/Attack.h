#ifndef ATTACK_H
#define ATTACK_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>
#include <Common.h>
#include <Camera.h>
#include <Vect.h>


class Attack {
    public:
        Attack(){};
        float virtual_distance;
        float virtual_direction;
        Vect orbit(Vect data); //returns virtual point needed for orbit
    private:

};



#endif




