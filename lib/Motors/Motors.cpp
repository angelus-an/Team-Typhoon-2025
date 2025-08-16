#include <Motors.h>


void Motors::init(){
    //pinMode -> sets pin to a particular Mode --> pinMode(digital pin, input [if sensor], output [if motor])
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){ // j variable for loop of 3
            pinMode(motorPins[i][j], OUTPUT); //three pin for each pin in_A (digital -> High or Low), in_B (digital -> HIGH or LOW), PWM (PWM)

        }
    }
}


void Motors::update(float speed[4]){
    for (int i = 0; i < 4; i++) {
        if(speed[i] > 0) {
            digitalWrite(motorPins[i][0], HIGH); //motorPins[i][0] -> pin INA
            digitalWrite(motorPins[i][1], LOW);
            analogWrite(motorPins[i][2], abs(speed[i])); //accesses speed[i] for the value for the speed
        } else if(speed[i] < 0){
            digitalWrite(motorPins[i][0], LOW);
            digitalWrite(motorPins[i][1], HIGH);
            analogWrite(motorPins[i][2], abs(speed[i]));
        }
        else {
            digitalWrite(motorPins[i][0], HIGH);
            digitalWrite(motorPins[i][1], HIGH);
            analogWrite(motorPins[i][2], abs(speed[i]));
        }
        
    }
}

void Motors::move(float speed, float direction, float rotation) { //I put the float in there to return the direction its going
    float motorSpeeds[4]={0,0,0,0};
    float largest = 0;
    for (int num_motors = 0; num_motors < 4; num_motors++ ){
        motorSpeeds[num_motors] = speed*cos(M_PI/180*(45+(90*num_motors-direction)))+rotation; //the dot product thingamabob
    }
    for (int num_motors = 0; num_motors < 4; num_motors++){
        if (abs(motorSpeeds[num_motors]) > largest) {   
            largest = abs(motorSpeeds[num_motors]);
        }             
    }
    // for (int num_motors = 0; num_motors < 4; num_motors++){
    //     motorSpeeds[num_motors]*=(100/largest);
    // }
    update(motorSpeeds);
}


