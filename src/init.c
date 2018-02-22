#include "main.h"








int auton = 0;

bool buttonsPressed() {
  unsigned int record = 0;
  bool isPressed = false;

  while (isPressed == false) {
    record = lcdReadButtons(uart1);
    if (record != 0) {
      delay(20);
      record = lcdReadButtons(uart1);
      if (record == 1) {
        return true;
        isPressed = true;
      }
      else {
        return false;
        isPressed = true;
      }
    }
    delay(20);
  }
  return false;
}

int whichSide() {
  unsigned int record = 0;
  bool isPressed = false;

  while (isPressed == false) {
    record = lcdReadButtons(uart1);
    if (record != 0) {
      delay(20);
      record = lcdReadButtons(uart1);
      if (record == 1) {
        return 0;
        isPressed = true;
      }
      else if (record == 2) {
        return 1;
      }
      else {
        return 2;
      }
    }
    delay(20);
  }
  return 0;
}

void initializeIO() {
  lcdInit(uart1);
  lcdClear(uart1);
}

void initialize() {
  ultrasonicInit(2, 1);
  encoderInit(3, 4, false);
  encoderInit(5, 6, true);
  lcdPrint(uart1, 1, "   Alliance??   ");
  lcdPrint(uart1, 2, "RED         BLUE");
  delay(10);

  if (buttonsPressed() == true) {
    lcdPrint(uart1, 1, "     Side??     ");
    lcdPrint(uart1, 2, "LEFT  MID  RIGHT");
    delay(10);

    switch (whichSide()) {
      case 0:
        auton = 1; // red left
        break;
      case 1:
        lcdPrint(uart1, 1, "  Side Block??  ");
        lcdPrint(uart1, 2, "LEFT       RIGHT");
        delay(10);

        if (buttonsPressed() == false) {
          auton = 2; // block Right
        }
        else {
          auton = 3; // block Left
        }
        break;
      case 2:
        auton = 4; // red right
        break;
    }
  }
  else if (buttonsPressed() == false) {
    lcdPrint(uart1, 1, "     Side??     ");
    lcdPrint(uart1, 2, "LEFT  MID  RIGHT");
    delay(10);

      switch (whichSide()) {
        case 0:
          auton = 5; // blue left
          break;
        case 1:
          if (buttonsPressed() == false) {
            auton = 6; // block Right
          }
          else {
            auton = 7; // block Left
          }
          break;
        case 2:
          auton = 8; // blue right
          break;
      }
  }
  else {
    delay(10);
  }
}
