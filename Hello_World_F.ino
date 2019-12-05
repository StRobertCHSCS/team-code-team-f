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


 prizm. setRedLED(HIGH);
 delay(500);
 prizm.setRedLED(LOW);
 delay(500);
 prizm. setRedLED(HIGH);
 delay(500);
 prizm.setRedLED(LOW);
 delay(500);
 prizm. setRedLED(HIGH);
 delay(500);
 prizm.setRedLED(LOW);
 delay(500);
 prizm. setGreenLED(HIGH);
 delay(1000);
 prizm.setGreenLED(LOW);
 delay(1000); 
 prizm. setGreenLED(HIGH);
 delay(1000);
 prizm.setGreenLED(LOW);
 delay(1000); //

}
