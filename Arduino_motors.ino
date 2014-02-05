// Standard PWM DC control
int M1_SPEED = 5;     //M1 Speed Control
int M2_SPEED = 6;     //M2 Speed Control
int M1_DIRECTION = 4; //M1 Direction Control
int M2_DIRECTION = 7; //M1 Direction Control

// Speed Constants
int MAX_SPEED  = 240;
int TURN_SPEED = 240;

// Onboard Keys Constants               
int adc_key_val[5] ={ 30, 150, 360, 535, 760 };
int NUM_KEYS = 5;
int adc_key_in;
int key=-1;
int oldkey=-1;
char serial_key = -1;

void setup(void) 
{  
  Serial.begin(19200);      //Set Baud Rate
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
    if ((key == 0) || (serial_key == 's')) move_forward(1000);
    if ((key == 2) || (serial_key == 'w')) move_backward(1000);
    if ((key == 1) || (serial_key == 'a')) move_left(1000);
    if ((key == 3) || (serial_key == 'd')) move_right(1000);
  }
  
  serial_key = -1;
}

// ------------ Motor Functions ------------------
// Move Forward
void move_forward(unsigned int length) {
  Serial.println("Moving forward!");
  analogWrite (M1_SPEED,MAX_SPEED);
  analogWrite (M2_SPEED,MAX_SPEED);
  digitalWrite(M1_DIRECTION,LOW);
  digitalWrite(M2_DIRECTION,LOW);
  delay(length);
  stop();
}

// Move Backward
void move_backward(unsigned int length) {
  Serial.println("Moving backword?!");
  analogWrite (M1_SPEED,MAX_SPEED);
  analogWrite (M2_SPEED,MAX_SPEED);
  digitalWrite(M1_DIRECTION,HIGH);
  digitalWrite(M2_DIRECTION,HIGH);
  delay(length);
  stop();
}

// Move Left
void move_left(unsigned int length) {
  Serial.println("Moving left <-");
  analogWrite (M1_SPEED,TURN_SPEED);
  analogWrite (M2_SPEED,TURN_SPEED);
  digitalWrite(M1_DIRECTION,LOW);
  digitalWrite(M2_DIRECTION,HIGH);
  delay(length);
  stop();
}

// Move Right
void move_right(unsigned int length) {
  Serial.println("Moving right ->");
  analogWrite (M1_SPEED,TURN_SPEED);
  analogWrite (M2_SPEED,TURN_SPEED);
  digitalWrite(M1_DIRECTION,HIGH);
  digitalWrite(M2_DIRECTION,LOW);
  delay(length);
  stop();
}

void stop(void) {
  digitalWrite(M1_SPEED, LOW);
  digitalWrite(M2_SPEED, LOW);
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
