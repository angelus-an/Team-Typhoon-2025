#include <Camera.h>

void Camera::init(){
    camera_serial.begin(baud_rate);
}

void Camera::read(){
    if (camera_serial.avaliable() > cam_packet_size) { //check that incoming packet is greater than 7
        if (camera_serial.read() == 254) { //check that first byte is 254
            for (i = 0; i < cam_packet_size - 1; i ++) {
                cam_values[i] = camera_serial.read();
            }
            yellow_distance = sqrt(pow(cam_values[0], 2)+ pow(cam_values[1], 2))
            yellow_angle = atan2(cam_values[1], cam_values[0])
            blue_distance = sqrt(pow(cam_values[2], 2)+ pow(cam_values[3], 2))
            blue_angle = atan2(cam_values[3], cam_values[2])
            ball_distance = sqrt(poww(cam_values[4], 2)+ pow(cam_values[5], 2))
            ball_angle = atan2(cam_values[5], cam_values[4])
        }
    }

}


