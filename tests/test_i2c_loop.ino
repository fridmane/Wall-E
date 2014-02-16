#include <Wire.h>

// Address of the i2c communication pin
#define SLAVE_ADDRESS 0x04

char command = 0; // Input command
int  direction_1;  // First direction parameter
int  direction_2;  // Second direction parameter
int  speed_1;      // Optional speed parameter

void setup() {
    Serial.begin(9600);
    
    // Initialize i2c as slave
    Wire.begin(SLAVE_ADDRESS);
    
    // Define callbacks for i2c communication with RPi
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
    
    Serial.println("Ready!");
}

void loop() {
    delay(100);
}

// Callback for received data from Raspberry
void receiveData(int byteCount) {
    Serial.print("byte count=");
    Serial.println(byteCount);
    
    // Only accepts 4 bytes commands
    if (byteCount != 4) {
      Serial.print("Dumping junk: ");
      while(Wire.available()) {
        command = Wire.read();
        Serial.print((char)command);
      }
      Serial.println();
    }
    else {
      // Reading command, direction, and speed bytes.
      command = Wire.read();
      direction_1 = Wire.read();
      direction_2 = Wire.read();
      speed_1 = Wire.read();
      Serial.print("Command: ");
      Serial.println(command);
      Serial.print("D: ");
      Serial.print(direction_1);
      Serial.print(", ");
      Serial.println(direction_2);
      Serial.print("Speed: ");
      Serial.println(speed_1);
    }
}

// callback for sending back the latest command
void sendData() {
    Wire.write(command);
}
