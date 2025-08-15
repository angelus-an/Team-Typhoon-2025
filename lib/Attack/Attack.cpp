#include <Attack.h>


float Attack::orbit(const float camera_values[cam_packet_size-1]){ 

    if (camera_values[1] <= ball_radius) { //remember ball_radius = ball_offset_buffer/asin(M_PI/180 * theta)
        virtual_direction = (180 - virtual_theta);
        virtual_distance = ball_distance - pow(ball_radius, 2);
    }
    else if (camera_values[1] >  ball_radius) {
        if (camera_values[0] < 0) { //fourth quadrant
            virtual_direction = 180 - ball_angle; //add 90 degrees to the location of the ball
            virtual_distance = ball_distance;
        }
        else { // third quadrant
            virtual_direction = -180 + ball_angle; //add 90 degrees to the location of the ball
            virtual_distance = ball_distance;
        }
    }   
    else {
        virtual_direction = 0;
        virtual_distance = 10; // change as needed
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