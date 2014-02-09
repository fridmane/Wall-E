#include "E_Motors.h"

// Onboard Keys Constants               
int adc_key_val[5] ={ 30, 150, 360, 535, 760 };
int NUM_KEYS = 5;
int adc_key_in;
int key=-1;
int oldkey=-1;
char serial_key = -1;

E_Motors motor;

void setup(void) 
{  
  Serial.begin(9600);      //Set Baud Rate
  Serial.println("\nRun keyboard control");
} 
void loop(void) 
{
  // Start by reading a board keypress if one available
  adc_key_in = analogRead(7); // read the value from the sensor  
  key = get_arduino_key(adc_key_in);  // convert into key press
  if (key != oldkey) {        // if keypress is detected
    delay(50);                // wait for debounce time
    adc_key_in = analogRead(7); // read the value from the sensor  
    key = get_arduino_key(adc_key_in);  // convert into key press
    if (key != oldkey)         
      oldkey = key;
      if (key >= 0) {
        Serial.print("Arduino key: ");
        Serial.println(key, DEC);
      }
  }
  
  // Check for any input from the serial terminal
  if(Serial.available()) {
    serial_key = Serial.read();
    Serial.print("I received: ");
    Serial.println(serial_key, DEC);
  }
      
  if ((key >= 0) || (serial_key >= 0))  { 
    if ((key == 0) || (serial_key == 's')) motor.forward(1000);
    if ((key == 2) || (serial_key == 'w')) motor.backward(1000);
    if ((key == 1) || (serial_key == 'a')) motor.left(1000);
    if ((key == 3) || (serial_key == 'd')) motor.right(1000);
  }
  
  serial_key = -1;
}

//------------- Board specific code --------------
// Convert on-board key press into a key value
int get_arduino_key(unsigned int input)
{   
  int k;
  for (k = 0; k < NUM_KEYS; k++) {
    if (input < adc_key_val[k]) {  
      return k;  
    }
  }
  if (k >= NUM_KEYS)
     return -1;     // No valid key pressed
}
