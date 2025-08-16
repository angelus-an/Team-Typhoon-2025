//circle with radius of ls-ring (smaller one)
//  for i < 16
//      if ls.read > white_threshold
//          x_ sum += x
//          y_sum += y
//          num_of_num += 1
//      find average 
//      give angle (using atan) and direction    

#include <LS.h>


void init() { //u5 mux
//initialise array of light sensors by giving them coordinates on the circle of radius = 33 mmm -> 16 sensors
    pinMode(LSOUT1, INPUT);
    pinMode(LSOUT, INPUT);
    pinMode(LS_S0, OUTPUT); //MEANS TEENSY IS SENDING SOMETHING
    pinMode(LS_S1, OUTPUT);
    pinMode(LS_S2, OUTPUT);
    pinMode(LS_S3, OUTPUT);
}

float LS::line_avoid(float ls_value[LS_NUM], int white_threshold){
    for (int i = 0; i < 16; i++) {
        float x_sum = 0;
        float y_sum = 0;
        int num_of_num = 0;

        for (int j = 0; j < 4; j++) { //loop to find sensor
            if ((i & (1 <<j)) == 1<<j){
                digitalWrite(mux_pins[j], HIGH);
            }
            else {
                digitalWrite(mux_pins[j], LOW);
            }
        }
        ls_value[i] = analogRead(INPUT); //could be a read function
        

        if (ls_value[i] > white_threshold) { //add an array of white sensor thresholds
            x_sum += ls_xy[2*i];
            y_sum += ls_xy[1+(2*i)];
            num_of_num += 1;
        }
        float average_x = x_sum/num_of_num;
        float average_y = y_sum/num_of_num;
        float avoid_direction = atan2(y_sum, x_sum);   
        //float avoid_distance = sqrt(pow(average_x, 2) + (average_y, 2));
        // it should return avoid_direction and avoid_distance so what now ################################################################
        }
    }
}
