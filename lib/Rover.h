#ifndef Rover_h
#define Rover_h
#include <Arduino.h>
#define freq  5000
#define resolution 8
#define pwmChannelA 5
#define pwmChannelB 6
#define pwmPinA 5
#define pwmPinB 6
#define dirPinA 7
#define dirPinB 8
#define Speed_m 255

int Speed_dir ;
int speed;
int count = 4;
int i ;
String input ;
int PWM_DIR[4];

void move(int speedx, int speedy);

#endif // 