#include "Rover.h"
#include <Arduino.h>

void move(int speedy, int speedx) {
  int speed_motor_r = speedy - speedx;
  int speed_motor_l = speedy + speedx;
  if (speed_motor_r > 28) {
    digitalWrite(dirPinA, HIGH);
    Serial.print("m_r:f ");
  } else if (speed_motor_r < -28) {
    digitalWrite(dirPinA, LOW);
    Serial.print("m_r:b ");
  } else
    speed_motor_r = 0;

  if (speed_motor_l > 28) {
    digitalWrite(dirPinB, HIGH);
    Serial.print("m_L:F ");
  } else if (speed_motor_l < -28) {
    digitalWrite(dirPinB, LOW);
    Serial.print("m_L:b ");
  } else {
    speed_motor_l = 0;
  }
  // speed_motor_r = map(abs(speed_motor_r), 3000, 32000, 0, 255);
  // speed_motor_l = map(abs(speed_motor_l), 3000, 32000, 0, 255);

  ledcWrite(pwmChannelA, abs(speed_motor_r));
  Serial.print(speed_motor_r);
  ledcWrite(pwmChannelB, abs(speed_motor_l));
  Serial.print("");
  Serial.println(speed_motor_l);
}
// void forward(int speedx , int speedy){
//   digitalWrite(dirPinA, HIGH);
//   digitalWrite(dirPinB, HIGH);
//   if (speedx < 3500)
//   {
//     ledcWrite(pwmChannelA, speedy);
//     ledcWrite(pwmChannelB, speedy);
//   } else {
//     if (speedy < 3500)
//     {
//         digitalWrite(dirPinA, HIGH);
//         digitalWrite(dirPinB, LOW);
//         ledcWrite(pwmChannelA, speedx);
//         ledcWrite(pwmChannelB, speedx);
//     }else {
//     ledcWrite(pwmChannelA, speedy);
//     ledcWrite(pwmChannelB, (32000 - speedx);
//     }
//   }

//   ledcWrite(pwmChannelA, speed);
// }

//   ledcWrite(pwmChannelA, speed);
//   ledcWrite(pwmChannelB, speed);

// }

// void backward(int speed){
//   ledcWrite(pwmChannelA, speed);
//   ledcWrite(pwmChannelB, speed);
//   digitalWrite(dirPinA, LOW);
//   digitalWrite(dirPinB, LOW);
// }

// void Stop(){
//   ledcWrite(pwmChannelA, 0);
//   ledcWrite(pwmChannelB, 0);
// }