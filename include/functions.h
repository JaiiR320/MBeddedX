#ifndef _FUNCTIONS_H_
#define  _FUNCTIONS_H_
#include "main.h"
/*
(----Important Notes----)
Add functions that allow to set drive train to a specific distance
Sdd function that allows to set lift, 4 bar and mogo intake to specific spot
*/
//Universal Port Setup
int driveL = 2;
int driveR = 3;

int liftL = 4;
int liftR = 5;

int fourBar = 6;

int coneIntake = 7;

int mogoL = 8;
int mogoR = 9;

//Sensor ints
int ultDistance = 0;

int potValFourBarL = 0;
int potValFourBarR = 0;

int potValLiftL = 0;
int potValLiftR = 0;

int encValDriveL = 0;
int encValDriveR = 0;

void driveSetSpeed(int leftSpeed, int rightSpeed){
  motorSet(driveL, leftSpeed);
  motorSet(driveR, -rightSpeed);
}

void liftSetSpeed(int left, int right){
  motorSet(liftL, left);
  motorSet(liftR, right);
}

void fourBarSetSpeed(int speed){
  motorSet(fourBar, speed);
}

void mobileSetSpeed(int left, int right){
  motorSet(mogoL, -left);
  motorSet(mogoR, right);
}

#endif
