#ifndef LS_H
#define LS_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>

class LS {
    public:
        LS(){};
        void init();
        float line_avoid(float ls_value[LS_NUM], int white_threshold);
    private:
        double ls_xy[LS_NUM] = {(33, 0), (33*acos((M_PI/180)*22.5, 33*asin((M_PI/180)*22.5), (33*acos((M_PI/180)*45, 33*asin(M_PI/180)*45)), (33*acos(M_PI/180)*67.5, 33*asin(M_PI/180)*67.5), (0, 33), (33*acos(M_PI/180)*112.5, 33*asin(M_PI/180)*112.5), (33*acos(M_PI/180)*135, 33*asin(M_PI/180)*135), (33*acos(M_PI/180)*157.5, 33*asin(M_PI/180)*157.5), (-33, 0), (33*acos(M_PI/180)*202.5, 33*asin((M_PI/180)*202.5), (33*acos(M_PI/180)*225, 33*asin((M_PI/180)*225), (33*acos(M_PI/180)*247.5, 33*asin((M_PI/180)*247.5), (0, -33), (33*acos(M_PI/180)*292.5, 33*asin((M_PI/180)*292.5), (33*acos(M_PI/180)*315, 33*asin((M_PI/180)*315), (33*acos(M_PI/180)*337.5, 33*asin((M_PI/180)*337.5)};
        double ls_value[LS_NUM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        float mux_pins[4] = {LS_S0, LS_S1, LS_S2, LS_S3};
};


#endif
