#ifndef LS_H
#define LS_H

#include <Arduino.h>
#include <Pins.h>
#include <math.h>

class LS {
    public:
        LS(){};
        void init();
        double ls_value[LS_NUM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        float read(float ls_value[LS_NUM]);
        float line_avoid(float ls_value[LS_NUM], int white_threshold);
        float getAvoidVector(float ls_value[LS_NUM], int white_threshold);
        float avoid_direction;  
    private:
        float ls_x[LS_NUM] = {
            0,                              // Sensor 1: 270°
            33*cos((M_PI/180)*292.5),      // Sensor 2: 292.5°
            33*cos((M_PI/180)*315),        // Sensor 3: 315°
            33*cos((M_PI/180)*337.5),      // Sensor 4: 337.5°
            -33,                           // Sensor 5: 180°
            33*cos((M_PI/180)*202.5),      // Sensor 6: 202.5°
            33*cos((M_PI/180)*225),        // Sensor 7: 225°
            33*cos((M_PI/180)*247.5),      // Sensor 8: 247.5°
            0,                             // Sensor 9: 90°
            33*cos((M_PI/180)*112.5),      // Sensor 10: 112.5°
            33*cos((M_PI/180)*135),        // Sensor 11: 135°
            33*cos((M_PI/180)*157.5),      // Sensor 12: 157.5°
            33,                            // Sensor 13: 0°
            33*cos((M_PI/180)*22.5),       // Sensor 14: 22.5°
            33*cos((M_PI/180)*45),         // Sensor 15: 45°
            33*cos((M_PI/180)*67.5)        // Sensor 16: 67.5°
        };

        float ls_y[LS_NUM] = {
            -33,                           // Sensor 1: 270°
            33*sin((M_PI/180)*292.5),      // Sensor 2: 292.5°
            33*sin((M_PI/180)*315),        // Sensor 3: 315°
            33*sin((M_PI/180)*337.5),      // Sensor 4: 337.5°
            0,                             // Sensor 5: 180°
            33*sin((M_PI/180)*202.5),      // Sensor 6: 202.5°
            33*sin((M_PI/180)*225),        // Sensor 7: 225°
            33*sin((M_PI/180)*247.5),      // Sensor 8: 247.5°
            33,                            // Sensor 9: 90°
            33*sin((M_PI/180)*112.5),      // Sensor 10: 112.5°
            33*sin((M_PI/180)*135),        // Sensor 11: 135°
            33*sin((M_PI/180)*157.5),      // Sensor 12: 157.5°
            0,                             // Sensor 13: 0°
            33*sin((M_PI/180)*22.5),       // Sensor 14: 22.5°
            33*sin((M_PI/180)*45),         // Sensor 15: 45°
            33*sin((M_PI/180)*67.5)        // Sensor 16: 67.5°
        };
        float mux_pins[4] = {LS_S0, LS_S1, LS_S2, LS_S3};

}
#endif
