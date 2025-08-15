#ifndef CAMERA_H
#define CAMERA_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>
#include <Common.h>


class Camera {
    public:
        Camera(){};
        float cam_buffer[cam_packet_size - 1];
        void init();
        void read();
        float yellow_distance;
        float yellow_angle;
        float blue_distance;
        float blue_angle;
        float ball_distance;
        float ball_angle;
    private:
        float cam_values[6]; // I think it is six because of cam_packet_size -1 = 6
};



#endif