#ifndef CAMERA_H
#define CAMERA_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>
#include <Common.h>


class Camera {
    public:
        Camera(){};
        void init();
        void read();
        // float yellow_distance;
        // float yellow_angle;
        // float blue_distance;
        // float blue_angle;
        float ball_distance;
        float ball_angle;
        float cam_values[cam_packet_size - 1]; // I think it is six because of cam_packet_size -1 = 6
    private:
       
};



#endif