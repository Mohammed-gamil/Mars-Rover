#include <Arduino.h>
#include <BluetoothSerial.h>
#include "..\lib\Rover.h"
// Define motor control pins

String Speed_dir_s ; 

BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("Rover");
  // Set the motor control pins as outputs
  pinMode(pwmPinA, OUTPUT);
  pinMode(dirPinA, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  pinMode(dirPinB, OUTPUT);

  // Configure PWM functionalities
  ledcSetup(pwmChannelA, freq, resolution);
  ledcSetup(pwmChannelB, freq, resolution);

  // Attach the PWM channels to the GPIO pins
  ledcAttachPin(pwmPinA, pwmChannelA);
  ledcAttachPin(pwmPinB, pwmChannelB);
}


void loop() {
  
    while ( i <= count)
    {
      while(SerialBT.available()) {
         input = SerialBT.readString();
      }

      
      int index = 0;
      int start = 0;
      for (int j = 0; j < input.length(); j++) { 
        if (input[j] == ' ' || j == input.length() - 1) {
          PWM_DIR[index] = input.substring(start, j).toInt();
          start = j + 1;
        }
      }
    }
    
    move(PWM_DIR[1],PWM_DIR[2]);

}
