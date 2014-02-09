/*
 E_Motors.cpp - Wall-E Motor (wheel) control package.
 
 E_Motors Class can control the wheels on Arduino Romeo moving
 left, right, forward and backward.
 */

#include "Arduino.h"
#include "E_Motors.h"

E_Motors::E_Motors()
{
}

void E_Motors::forward(unsigned int length, unsigned int speed)
{
  analogWrite (M1_SPEED,speed);
  analogWrite (M2_SPEED,speed);
  digitalWrite(M1_DIRECTION,LOW);
  digitalWrite(M2_DIRECTION,LOW);
  delay(length);
  this->stop();
}

void E_Motors::backward(unsigned int length, unsigned int speed)
{
  analogWrite (M1_SPEED,speed);
  analogWrite (M2_SPEED,speed);
  digitalWrite(M1_DIRECTION,HIGH);
  digitalWrite(M2_DIRECTION,HIGH);
  delay(length);
  this->stop();
}

void E_Motors::left(unsigned int length, unsigned int speed)
{
  analogWrite (M1_SPEED,speed);
  analogWrite (M2_SPEED,speed);
  digitalWrite(M1_DIRECTION,LOW);
  digitalWrite(M2_DIRECTION,HIGH);
  delay(length);
  this->stop();
}

void E_Motors::right(unsigned int length, unsigned int speed)
{
  analogWrite (M1_SPEED,speed);
  analogWrite (M2_SPEED,speed);
  digitalWrite(M1_DIRECTION,HIGH);
  digitalWrite(M2_DIRECTION,LOW);
  delay(length);
  this->stop();
}

void E_Motors::stop(void)
{
  digitalWrite(M1_SPEED,LOW);
  digitalWrite(M2_SPEED,LOW);
}