#include <Motors.h>
#include <PID.h>
#include <Common.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Camera.h>
//#include <LS.h>
#include <Pins.h>
#include <Common.h>
#include <Vect.h>
#include <i2c.h>



Motors motors;
PID compass_pid(compass_P, compass_I, compass_D, absolute_max);
Adafruit_BNO055 bno;
sensors_event_t currentHeading;
sensors_event_t targetHeading;
Camera camera;
PID orbit_pid(1.5, 0.0, 0.0, 10);
//LS lights;








void setup() {
  motors.init();
  camera.init();
  
  // I2Cscan();
  // while (!(bno.begin())){
  //   Serial.println("BNO not working");
  // }
  // bno.setExtCrystalUse(true);
  // targetHeading = currentHeading;  
  

}



void loop() {
  camera.test();
  //camera.read();
}
//   Vect ball = camera.getBall();
 
//   if(ball.mag > 50) {
//     motors.move(1, ball.arg, 0); //correction
//   }
//   else {
//     float ang = -orbit_pid.update(ball.arg, 0);
//     motors.move(40, ang, 0); //correction
//   }  
// }

  //PID for goal
  // Vect attack_goal = camera.getAttack();
  // float attack_goal_angle = (attack_goal.arg < 180) ? attack_goal.arg - 360 : attack_goal.arg;
  // motor.move(30, 0, attack_goal_angle.arg); //change 0 to ang


  
  // If ls_ring is not touching any white lines
    // Camera gives x and y to teensy
    // If ball is behind offsett buffer, 
      // orbit function
    // Elif, ball is in front (between -5 and 5 degrees) but not directly in front
      // move 90 to the direction of the ball
    // Else (the ball is directly in front)
      // move forward 
  // If ls_ring is touching 
      //ls_avoid function
  

  

  

  
//BNO
  //digitalWrite(13, HIGH);
  // bno.getEvent(&currentHeading); //whenever want to access the actual bno heading use extract_bn0.orientation.x
  // float heading = floatMod(currentHeading.orientation.x - targetHeading.orientation.x,360);
  //  float correction = compass_pid.update(heading,0);



    
  // float virt_x = camera.virtual_x;
  // float virt_y = camera.virtual_y;
  // float varying_angle = 

  // motor.move(50, atan2(virt_x/virt_y), correction) //check it will work for all angles -> if need be replace speed with a PID which decreases speed as distance decreases

  // //function to get it to move forward 



