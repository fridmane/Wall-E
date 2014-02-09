/*
  E_Motors.h - Wall-E Motor (wheel) control package.
  
  E_Motors Class can control the wheels on Arduino Romeo moving
  left, right, forward and backward.
*/

#ifndef E_Motors_h
#define E_Motors_h


// Standard PWM DC control
#define M1_SPEED       5     // M1 Romeo Speed Control
#define M2_SPEED       6     // M2 Romeo Speed Control
#define M1_DIRECTION   4     // M1 Romeo Direction Control
#define M2_DIRECTION   7     // M1 Romeo Direction Control

// Speed Constants
#define MAX_SPEED      240   // Global Max for motor speed

// E_Motor Class
class E_Motors {
public:
  E_Motors();
  void forward(unsigned int length, unsigned int speed = MAX_SPEED);
  void backward(unsigned int length, unsigned int speed = MAX_SPEED);
  void left(unsigned int length, unsigned int speed = MAX_SPEED);
  void right(unsigned int length, unsigned int speed = MAX_SPEED);
  void stop(void);
};

#endif
