#include <Attack.h>


double Attack::orbit(const double camera_values[cam_packet_size]){

    double x_ball = camera_values[0]; //x-coord of ball
    double y_ball = camera_values[1]; //y-coord of ball  
    int ball_offset_buffer = ball_radius

    if (y_ball <= int ball_offset_buffer) { //remember ball_radius = ball_offset_buffer/asin(M_PI/180 * theta)
        virtual_direction = (180 - virtual_theta);
        virtual_distance = sqrt((pow(x_ball, 2) + pow(y_ball, 2)) - pow(ball_radius, 2));

    else if (y_ball >  ball_offset_buffer) {
        if (x_ball < 0) { //fourth quadrant
            virtual_direction = 180 - atan2(y_ball, x_ball); //add 90 degrees to the location of the ball
            virtual_distance = sqrt(pow(x_ball, 2) + pow(y_ball, 2));
        }
        else // third quadrant
            virtual_direction = -180 + atan2(y_ball, x_ball); //add 90 degrees to the location of the ball
            virtual_distance = sqrt(pow(x_ball, 2) + pow(y_ball, 2));
        }
        
    else {
        virtul_direction = 0
        virtual_distance = 50
    }
    
}

// Accurate way
    // if ball - offsett = negative -> if ball is behind minimum to go forward: 
    //      if ball is in quadrant 4
    //          (go to virtual point)
    //      if ball is in quadrant 3
    //          (go to virtual point)
    // else if ball  is in front of offsett (ball - offset > 0)
    //      go to point behind ball () -> y-coord = (ball positon - offset) -> go to direction which closes the angle (PID)
    // else:
    //      go forwards towards the goal for set distance before stopping

}