#include <Camera.h>

//byte [254, 254, attack_x, attack_y, orange_x, orange_y]

void Camera::init(){
    camera_serial.begin(baud_rate);
}

void Camera::test() {
    if (Serial7.available()) {
        Serial.print("Serial7 data: ");
        while (Serial7.available()) {
            byte incomingByte = Serial7.read();
            Serial.print(incomingByte);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void Camera::read() {
    Serial.println(Serial7.read());
    // if (Serial7.available() >= 6) { //check that incoming packet is greater than 7
    //     if (Serial7.read() == 254 && Serial7.peek() == 254) { //check that first byte is 254
    //         Serial7.read(); //discard second sync byte

    //         //Read camera values
    //         cam_values[1] = 120 - Serial7.read(); //attack_x
    //         cam_values[2] = Serial7.read() - 120; //attack_y
            
    //         cam_values[4] = Serial7.read() - 120; //ball_y
    //         cam_values[3] = 120 - Serial7.read(); //ball_x
            
    //         attack_distance = sqrt((cam_values[2]*cam_values[2]) + (cam_values[1]*cam_values[1]));
    //         attack_angle = fmod(atan2(cam_values[1], cam_values[2]) * 180.0 / M_PI + 360, 360);

    //         ball_distance = sqrt((cam_values[3]*cam_values[3])+ (cam_values[4]*cam_values[4]));
    //         ball_angle = fmod(atan2(cam_values[3], cam_values[4]) * 180.0 / M_PI + 360, 360);

    //         //ball_angle = fmod((atan2(cam_values[4], cam_values[3]) * 180.0 / M_PI) + 360, 360);
    //         if (ball_angle < 0) ball_angle += 360;
    //         if (attack_angle < 0) attack_angle += 360;

    //         Serial.print("Attack: ");
    //         Serial.print(attack_distance);
    //         Serial.print(", ");
    //         Serial.println(attack_angle);
    //         Serial.print("Ball: ");
    //         Serial.print(ball_distance);
    //         Serial.print(", ");
    //         Serial.println(ball_angle);
    //     } else {
    //         // Second sync byte not found, clear buffer
    //         while (camera_serial.available()) {
    //             camera_serial.read();
    //         }
    //     }
    // }
}
    

Vect Camera::getBall(){
    return Vect(ball_distance, ball_angle);
}

Vect Camera::getAttack(){
    return Vect(attack_distance, attack_angle);
}

