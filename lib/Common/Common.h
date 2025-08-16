#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <math.h>

//Compass
#define compass_P 0
#define compass_I 0
#define compass_D 0
#define absolute_max 0

//Camera
#define baud_rate 115200
#define camera_serial Serial7
#define cam_packet_size 5

//Attack
#define ball_radius 5 //cm offsett from the of ball -> think of it like a range of error
#define virtual_theta 60 //angle in degrees of virtual point horizontal across ball

//LS
#define LS_NUM 16
#define white_threshold //calibrate this

float angleMap(float angle, float max);
int8_t findSign(float value);
float floatMod(float x, float m);
float angleBetween(float angleCounterClockwise, float angleClockwise);
float smallestAngleBetween(float angleCounterClockwise, float angleClockwise);
float midAngleBetween(float angleCounterClockwise, float angleClockwise);
uint8_t mod(int8_t x, int8_t m);
bool angleIsInside(float angleBoundCounterClockwise, float angleBoundClockwise, float angleCheck);



#endif