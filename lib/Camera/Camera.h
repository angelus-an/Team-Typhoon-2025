#ifndef CAMERA_H
#define CAMERA_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>
#include <Common.h>
#include <Vect.h>


class Camera {
    public:
        Camera(){};
        void init();
        void read();
        Vect getBall();
        Vect getAttack();
        // float yellow_distance;
        // float yellow_angle;
        float attack_distance;
        float attack_angle;
        float ball_distance;
        float ball_angle; // I think it is six because of cam_packet_size -1 = 6
    private:
       float cam_values[cam_packet_size - 1];
};



#endif