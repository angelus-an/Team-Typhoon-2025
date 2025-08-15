#include <Motors.h>
#include <PID.h>
#include <Common.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Camera.h>

Motors motor;
PID compass_pid(compass_P, compass_I, compass_D, absolute_max);
Adafruit_BNO055 bno;
sensors_event_t extract_bno;
Camera camera;







void setup() {
  motor.init();
  while (!(bno.begin())){
    Serial.println("BNO not working");
  }
  bno.setExtCrystalUse(true);
}














void loop() {
  bno.getEvent(&extract_bno); //whenever want to access the actual bno heading use extract_bn0.orientation.x
  if (extract_bno.orientation.x > 180) { //for values to be from -180 to 180 not 0 to 360 because the robot is a dumb shit
    extract_bno.orientation.x -= 360;
  }
  float correction = compass_pid.update(extract_bno.orientation.x,0);
    motor.move(0,0,correction);

  

  // If ls_ring is not touching any white lines
    // If ball is behind offsett buffer, 
      // orbit function
    // Elif, ball is in front (between -5 and 5 degrees) but not directly in front
      // move 90 to the direction of the ball
    // Else (the ball is directly in front)
      // move forward 
  // If ls_ring is touching 
      //ls_avoid function
  

  

  

  




    
  // float virt_x = camera.virtual_x;
  // float virt_y = camera.virtual_y;
  // float varying_angle = 

  // motor.move(50, atan2(virt_x/virt_y), correction) //check it will work for all angles -> if need be replace speed with a PID which decreases speed as distance decreases

  // //function to get it to move forward 

}

