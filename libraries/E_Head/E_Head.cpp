/*
 E_Head.cpp - Wall-E head (Servo) control package.
 
 E_Head Class can control the head of Wall-E on Arduino Romeo moving
 left, right, up, down and center.
 */

#include "E_Head.h"
 
E_Head::E_Head()
{
  // Calling Servo.attach() in constructor causes some bad behavior.
  // http://stackoverflow.com/questions/17335592
}

// begin initialize the servos.
// It can also get the pin number for horizontal and vertical servos
void E_Head::begin(unsigned int h_pin, unsigned int v_pin)
{
  _h_servo.attach(9);
  _v_servo.attach(10);
}

void E_Head::left(void)
{
  _h_pos = 150;
  _h_servo.write(_h_pos);
}

void E_Head::right(void)
{
  _h_pos = 30;
  _h_servo.write(_h_pos);
}

void E_Head::up(void)
{
  _v_pos = 80;
  _v_servo.write(_v_pos);
}

void E_Head::down(void)
{
  _v_pos = 170;
  _v_servo.write(_v_pos);
}

void E_Head::center(void)
{
  _h_pos = H_CENTER;
  _v_pos = V_CENTER;
  _h_servo.write(_h_pos);
  _v_servo.write(_v_pos);
}