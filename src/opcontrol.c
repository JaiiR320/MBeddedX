//Jair Meza - Oct. 5, 2017
//MBedded X
/*
(----Transmitters----)
Drive TX: 2
Lift TX: 1

(----Ports----)
Drive Left = port 2
Drive Right = port 3

Lift Left = 4
Lift Right = 5

Mogo Intake = 6
Cone Intake = 7

(----Important Notes----)
Plans for upcoming regional bot
-Reorganize auton so that it is possible to pick
 autons before the match starts
-Make an autonomous loading system for match loads
 as well as manual loading
*/
#include "main.h"
#include "functions.h"


//Port setup
/*
void autoStack(bool stack){
  while(stack == true) {
    liftSet(127, 127);
    if (distance > 20) {
      liftSet(0, 0);
      fourBarSet(-127);
      delay(800);
      liftSet(-127, -127);
      delay(500);
      motorSet(coneIntake, -80);
      delay(20);
      liftSet(127, 127);
      delay(300);
      fourBarSet(127);
      delay(500);
      liftSet(-127, -127);
      fourBarSet(0);
    }
  }
}
*/
void operatorControl() {
    while (1) {
//Drive Train Setup
      driveSetSpeed(joystickGetAnalog(2, 3), joystickGetAnalog(2, 2));

//Lift Setup
      liftSetSpeed(joystickGetAnalog(1, 3), joystickGetAnalog(1, 3));

//Four Bar Setup
      fourBarSetSpeed(joystickGetAnalog(1, 2));

//Claw Setup
      if (joystickGetDigital(1, 8, JOY_LEFT)) {
        motorSet(coneIntake, -75); //In
      }
      else if (joystickGetDigital(1, 8, JOY_RIGHT)) {
        motorSet(coneIntake, 75); //Out
      }
      else{
        motorSet(coneIntake, -35); //Always applying inwards tourque
      }

//Mobile Goal Intake Buttons
      if(joystickGetDigital(2, 6, JOY_DOWN) == 1){ //Mogo up
        mobileSetSpeed(80, 80);
      }
      else if(joystickGetDigital(2, 5, JOY_DOWN) == 1){ //Mogo down
        mobileSetSpeed(-80, -80);
      }
      else{ //If nothing, sets motors to 0
        mobileSetSpeed(0, 0);
      }

//Sensors
      ultDistance = ultrasonicGet(sonar);
      potValFourBarL = analogRead(1);
      potValFourBarR = analogRead(2);
      potValLiftL = analogRead(3);
      potValLiftR = analogRead(4);
      encValDriveL = encoderGet(encDriveR);
      encValDriveR = encoderGet(encDriveL);
      delay(20);
      }
    }
