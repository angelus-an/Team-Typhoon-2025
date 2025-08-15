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
        float virtual_distance;
        float virtual_direction;
        float orbit(const float camera_values[cam_packet_size-1]); //returns virtual point needed for orbit
    private:

};



#endif




