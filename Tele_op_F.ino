
#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library
#include <PRIZM.h>     // include PRIZM library
PRIZM prizm;           // instantiate a PRIZM object “prizm” so we can use its functions
PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4


int PowerM1;          // Channel 1 Motor Power 
int PowerM2;          // Channel 2 Motor Power

void setup() {  
  
  prizm.PrizmBegin();    delay(5000);  
    prizm.setServoPosition(1,0);
    delay(5000);; //initialize PRIZM
  pulse.PulseBegin();            // Intializes the PULSE controller and waits here for press of green start button
  ps4.setDeadZone (LEFT,10);     // Sets a Left Joystick Dead Zone axis range of +/- 10 about center stick
  ps4.setDeadZone(RIGHT,10);     // Sets a Right Joystick Dead Zone axis range of +/- 10 about center stick

  Serial.begin(115200);
}

void loop() {
  Serial.println("running ...]\n");

  ps4.getPS4();

  if(ps4.Connected){                            // If PS4 controller has been succesfully connected, control motors
      PowerM1 = ps4.Motor(LY);                  // Power (speed) and direction of Motor 1 is set by position of Left Y-axis Joystick
      PowerM2 = ps4.Motor(RY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      pulse.setMotorPowers(PowerM1, PowerM2);   // set motor output power levels for PULSE DC motor channels 1 and 2

      Serial.println(PowerM1);
  }
  else{                                         // If PS4 is not connected, stop motors
      pulse.setMotorPowers(0,0);
  }
  
  if (prizm.readSonicSensorCM(3) > 5)     // obstacle sense range set at 25 centimeters
  {
    Serial.println("out of range");
    prizm.setGreenLED(LOW);
    prizm.setRedLED(LOW);
    delay(500);// turn off the red LED
    prizm.setRedLED(HIGH);   
    delay(500);
    prizm.setServoPosition(1,0);
  }
  else
  {
    Serial.println("in range");
    prizm.setGreenLED(HIGH);
    prizm.setRedLED(LOW);
    prizm.setServoPosition(1,-45); 
  }
  if (ps4.Button(TRIANGLE) == 1)
  {
    prizm.setServoPosition(2,-30);
  }
  else
  {
    prizm.setServoPosition(2,0);
  }
}    
