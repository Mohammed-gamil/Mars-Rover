#include <Arduino.h>
#include <BluetoothSerial.h>
// #include "lib/Rover.h"
// Define motor control pins

void forward();
void backward();
void right_tank_turn();
void left_tank_turn();
void setup();

const int pwmPinA = 3; // PWM pin for motor A
const int dirPinA = 4; // Direction pin for motor A
const int pwmPinB = 5; // PWM pin for motor B
const int dirPinB = 6; // Direction pin for motor B

// Define PWM channels
const int pwmChannelA = 0;
const int pwmChannelB = 1;

// Define PWM properties
const int freq = 5000;
const int resolution = 8;
String Speed_dir_s ; 
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
  
    Speed_dir = Speed_dir_s.toInt(); //100070
    int direction = Speed_dir %1000 ; //070
    speed = (Speed_dir % 1000000)/1000; //100
    int Speed_m = map(speed , 0 , 100 , 0 , 255);
    
    if (speed > 50) {
      if (direction > 0 && direction < 50)
      {
        left_tank_turn(Speed_m);
      }else if (direction > 50 && direction < 100)
      {
        right_tank_turn(Speed_m);
      }
      } else {
        forward(Speed_m);
      }
      
    if (speed < 50) {
      if (direction > 0 && direction < 50)
      {
        left_tank_turn(Speed_m);
      }else if (direction > 50 && direction < 100)
      {
        right_tank_turn(Speed_m);
      }
      } else {
        backward(Speed_m);
    }

  // int signal = SerialBT.read();
  // if(signal == 1){
  //   forward();
  // }
  // if (signal == 2) {
  //   backward();
  // }
  // if (signal == 3) {
  //   right_tank_turn();
  // }
  // if (signal == 3) {
  //   left_tank_turn();
  // }
}
void forward (int speed){

  // Move forward
  digitalWrite(dirPinA, HIGH);
  digitalWrite(dirPinB, HIGH);
  ledcWrite(pwmChannelA, speed);
  ledcWrite(pwmChannelB, speed);
  delay(2000);
}
void backward(int speed) {
  // Move backward
  digitalWrite(dirPinA, LOW);
  digitalWrite(dirPinB, LOW);
  ledcWrite(pwmChannelA, speed);
  ledcWrite(pwmChannelB, speed);
  delay(2000);
}
void right_tank_turn(int speed) {
  // Right tank turn
  digitalWrite(dirPinA, HIGH);
  digitalWrite(dirPinB, LOW);
  ledcWrite(pwmChannelA, speed);
  ledcWrite(pwmChannelB, speed);
  delay(2000);
}
void left_tank_turn(int speed) {
  // left tank turn
  digitalWrite(dirPinA, LOW);
  digitalWrite(dirPinB, HIGH);
  ledcWrite(pwmChannelA, speed);
  ledcWrite(pwmChannelB, speed);
  delay(2000);
}