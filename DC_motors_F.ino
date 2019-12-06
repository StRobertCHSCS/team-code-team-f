/*  PRIZM Controller example program
 *  Blink the PRIZM red LED at a 1 second flash rate
 *  author PWU on 08/05/2016
*/
  
  #include <PRIZM.h>      // include the PRIZM library

  PRIZM prizm;            // instantiate a PRIZM object "prizm" so we can use its functions

void setup() {

   prizm.PrizmBegin();   // initialize the PRIZM controller

}

void loop() {     // repeat this code in a loop

  prizm.setMotorPower(1,25); 
  prizm. setGreenLED(HIGH);
  delayprizm.PrizmBegin();(5000);
  prizm.setMotorPower(1,0);
  prizm.setGreenLED(LOW);
  delay(2000);
  prizm.setMotorPower(1,-25);
  prizm.setRedLED(HIGH);
  delay(5000);                  // wait while the motor runs for 5 seconds
  prizm.setMotorPower(1,0);
  prizm.setRedLED(LOW);
  delay(2000);    
}
