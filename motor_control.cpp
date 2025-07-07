#include <Arduino.h>
#include "motor_control.h"

const int motorPin = D5;
static int speedPercent = 0;
static int pwmValue = 0;

void motor_init() {
  pinMode(motorPin, OUTPUT);
  analogWriteFreq(1000);
  analogWrite(motorPin, 0);
}

void motor_set_speed(int percent) {
  speedPercent = constrain(percent, 0, 100);
  pwmValue = map(speedPercent, 0, 100, 0, 1023);
  analogWrite(motorPin, pwmValue);
}

int motor_get_speed() {
  return speedPercent;
}

int motor_get_pwm() {
  return pwmValue;
} 