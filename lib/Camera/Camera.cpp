#include <Camera.h>

void Camera::init(){
    camera_serial.begin(baud_rate);
}

void Camera::read(){
    Serial.println(camera_serial.read());
    // if (camera_serial.available() > cam_packet_size) { //check that incoming packet is greater than 7
    //     if (camera_serial.read() == 254) { //check that first byte is 254
    //         for (int i = 0; i < cam_packet_size - 1; i ++) {
    //             cam_values[i] = camera_serial.read() - 120;
    //         }
            
    //             // yellow_distance = sqrt(pow(cam_values[0], 2)+ pow(cam_values[1], 2));
    //             // yellow_angle = atan2(cam_values[1], cam_values[0]);
    //         attack_distance = sqrt(pow(cam_values[0], 2)+ pow(cam_values[1], 2));
    //         attack_angle = atan2(cam_values[1], cam_values[0]);
    //         ball_distance = sqrt(pow(cam_values[2], 2)+ pow(cam_values[3], 2));
    //         ball_angle = atan2(cam_values[3], cam_values[2]);
    //         ball_angle = floatMod(ball_angle + 270, 360) - 180;
    //         ball_angle = (ball_angle < 0) ? ball_angle - 360 : ball_angle;
            
    //     }
    // }

}     

Vect Camera::getBall(){
    return Vect(ball_distance, ball_angle);
}

Vect Camera::getAttack(){
    return Vect(attack_distance, attack_angle);
}

