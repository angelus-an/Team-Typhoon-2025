#include <Attack.h>


//States Orbit ############################################################################################################################
//
//If robot is far away:    
//  go to ball
//else go forward





















double Attack::orbit(const double camera_values[array_length]){

    double x_ball = camera_values[6]; //x-coord of ball
    double y_ball = camera_values[7]; //y-coord of ball  
    int ball_offset_buffer = ball_radius

    if (y_ball <= int ball_offset_buffer) { //remember ball_radius = ball_offset_buffer/asin(M_PI/180 * theta)
        virtual_y = y_ball - ((ball_offset_buffer/sin(M_PI/180 * theta) * sin(M_PI/180 * theta)); //y_coordinate of virtual point
        if (x_ball >= 0) { //quadrant 4
            virtual_x = x_ball - ((ball_offset_buffer/sin(M_PI/180 * theta) * cos(M_PI/180 * theta))); //x_coordinate of virtual point -> can adjust ball_radius and theta
        }    
        if (x_ball < 0) {//quadrant 3
            virtual_x = x_ball + ((ball_offset_buffer/sin(M_PI/180 * theta) * cos(M_PI/180 * theta));//+ since the number u have to add to x to get virt_x is positive
        }
    }

    else if (y_ball >  ball_offset_buffer) {
        virtual_y = y_ball - ball_offset_buffer;
        virtual_x = x_ball;
        //add 90 degrees to the location of the ball
    }

    else {
        //go forwards #########################################################
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