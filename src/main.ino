#include <Arduino.h>
#include <BluetoothSerial.h>
#include "..\lib\Rover.h"
// Define motor control pins

char Speed_dir_s ; 
int Speed_dir ;
int speed;

BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
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

    if (SerialBT.available()) {
         Speed_dir_s = SerialBT.read();
        switch (Speed_dir_s)
        {
        case 'F' :
            forward(255);
            break;
        case 'B' :
            backward(255);
            break;
        case 'R' :
            right_tank_turn(255);
            break;
        case 'L' :
            left_tank_turn(255);
            break;
        default:
            Stop();
        }
    } else
    {
    printf("No data received");
    }
    
}
