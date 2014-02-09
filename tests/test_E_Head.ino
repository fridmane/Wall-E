#include <Servo.h>
#include "E_Head.h" 

char serial_key = -1;
E_Head e_head;
 
void setup() 
{ 
  Serial.begin(9600);      //Set Baud Rate
  Serial.println("\nReady for commands");
  e_head.begin();
} 

void loop() 
{
  // Check for any input from the serial terminal
  if(Serial.available()) {
    serial_key = Serial.read();
    Serial.print("I received: ");
    Serial.println(serial_key, DEC);
  }
      
  if (serial_key >= 0)  {
    if (serial_key == 'l') e_head.left();
    if (serial_key == 'r') e_head.right();
    if (serial_key == 'u') e_head.up();
    if (serial_key == 'd') e_head.down();
    if (serial_key == 'c') e_head.center();
  }

  serial_key = -1;
}
