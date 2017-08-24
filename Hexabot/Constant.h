
#define ServoOffset_01 -50  // A
#define ServoOffset_02 -320  // B
#define ServoOffset_03 50  // C 
#define ServoOffset_04 -100  // D
#define ServoOffset_05 -310  // E
#define ServoOffset_06 -50  // F
#define ServoOffset_07 0  // G
#define ServoOffset_08 0  // H
#define ServoOffset_09 0  // I

#define ServoOffset_10 100  // J
#define ServoOffset_11 100  // K
#define ServoOffset_12 0  // L
#define ServoOffset_13 0  // M
#define ServoOffset_14 0  // N
#define ServoOffset_15 0  // O
#define ServoOffset_16 0  // P
#define ServoOffset_17 0  // Q
#define ServoOffset_18 0  // R

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver ServoA = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver ServoB = Adafruit_PWMServoDriver(0x41);

const int OffsetServoPinA[] = {ServoOffset_01, ServoOffset_02, ServoOffset_03, ServoOffset_04, ServoOffset_05, ServoOffset_06, ServoOffset_07, ServoOffset_08, ServoOffset_09};
const int OffsetServoPinB[] = {ServoOffset_10, ServoOffset_11, ServoOffset_12, ServoOffset_13, ServoOffset_14, ServoOffset_15, ServoOffset_16, ServoOffset_17, ServoOffset_18};

const int ServoPinA[] = {4, 5, 6, 8, 9, 10, 12, 13, 14};
const int ServoPinB[] = {4, 5, 6, 8, 9, 10, 12, 13, 14};
int ServoValue[18] = {1500};

void setServoPulseA(uint8_t n, double uS_pulse) {
  double pulselength;
  pulselength = 4.06901042;   //  us per bit
  uS_pulse /= pulselength;
  ServoA.setPWM(n, 0, uS_pulse);
}

void setServoPulseB(uint8_t n, double uS_pulse) {
  double pulselength;
  pulselength = 4.06901042;   //  us per bit
  uS_pulse /= pulselength;
  ServoB.setPWM(n, 0, uS_pulse);
}
void setAllServoPulse(double uS_pulse) {
  for (uint8_t servonum = 0; servonum < 9; servonum++) {
    setServoPulseA(ServoPinA[servonum], uS_pulse + OffsetServoPinA[servonum]);
    setServoPulseB(ServoPinB[servonum], uS_pulse + OffsetServoPinB[servonum]);
  }
}
