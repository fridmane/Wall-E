/*
 E_Head.h - Wall-E head (Servo) control package.
 
 E_Head Class can control the head of Wall-E on Arduino Romeo moving
 left, right, up, down and center.
 */

#ifndef E_Head_h
#define E_Head_h

#include <Servo.h>

#define H_CENTER  90  // Center of Horizontal position
#define V_CENTER  90  // Center of Vertical position

// E_Head Class
class E_Head {
public:
  E_Head();
  
  // begin can get the pin number for horizontal and vertical servos
  void begin(unsigned int h_pin = 9, unsigned int v_pin = 10);
  
  void up(void);
  void down(void);
  void left(void);
  void right(void);
  void center(void);
  
private:
  unsigned int _h_pos;
  unsigned int _v_pos;
  Servo _h_servo;
  Servo _v_servo;
};

#endif
