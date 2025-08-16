#include <Attack.h>


Vect Attack::orbit(Vect data){ 
    //data.mag 
    //data.arg
    if (data.j <= ball_radius) { //remember ball_radius = ball_offset_buffer/asin(M_PI/180 * theta)
        virtual_direction = (180 - virtual_theta);
        virtual_distance = data.mag - pow(ball_radius, 2);
    }
    else if (data.j >  ball_radius) {
        virtual_distance = data.mag;
        if (data.i < 0) { //fourth quadrant
            virtual_direction = - 90 + ball_angle; //add 90 degrees to the location of the ball
        }
        else { // third quadrant
            virtual_direction = 90 - ball_angle; //add 90 degrees to the location of the ball
        }
    }   
    else {
        virtual_direction = 0;
        virtual_distance = 10; // change as needed

        virtual_direction = (virtual_direction < 0) ? (virtual_direction + 360) : virtual_direction;
    }
    return Vect(virtual_distance, virtual_direction);
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

