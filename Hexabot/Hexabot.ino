
#include "Constant.h"

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  1000 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  2000 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Servo test!");

  ServoA.begin();
  ServoA.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  ServoB.begin();
  ServoB.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  Wire.setClock(400000);

  setAllServoPulse(1500);
}

int i = 5;
int tmp = 1000;
void loop() {
//  setAllServoPulse(tmp);
//  tmp += i;
//  delay(20);
//  if (tmp > 2000 || tmp < 1000) i = -i;
}
