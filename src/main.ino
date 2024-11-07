#include "Rover.h"
#include <Arduino.h>
#include <BluetoothSerial.h>
// #include <..\lib\src\RemoteXY.h>

// Define motor control pins

String Speed_dir_s;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Rover");
  // Serial.SetTimeout(20);
  // Set the motor control pins as outputs
  pinMode(pwmPinA, OUTPUT);
  pinMode(dirPinA, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  pinMode(dirPinB, OUTPUT);

  // Configure PWM functionalities
  // ledcSetup(pwmChannelA, freq, resolution);
  // ledcSetup(pwmChannelB, freq, resolution);

  // Attach the PWM channels to the GPIO pins
  // ledcAttachPin(pwmPinA, pwmChannelA);
  // ledcAttachPin(pwmPinB, pwmChannelB);
}

void loop() {

  if (SerialBT.available()) {
    DATA = SerialBT.readStringUntil('#');

    // Serial.println(DATA + "\n");

    int index = 0;
    // int PWM_DIR[4]; // Assuming there are 4 values in each line
    int start = 0;

    for (int i = 0; i < 4; i++) {
      int spaceIndex = DATA.indexOf(' ', start);
      String valueString = DATA.substring(start, spaceIndex);
      PWM_DIR[i] = map(valueString.toInt(), -32000, 32000, -255,255);  // Convert the substring to an integer
      start = spaceIndex + 1; // Move start to the next character after space
    }

    // Print out the parsed integers for verification
    // for (int i = 0; i < 4; i++) {
    //   Serial.print("Value ");
    //   Serial.print(i + 1);
    //   Serial.print(": ");
    //   Serial.println(PWM_DIR[i]);
    // }
    DATA = " ";

    // while (i <= count) {
    //   while (SerialBT.available()) {
    //     input = SerialBT.readStringUntil('#');
    //   }

    //   int index = 0;
    //   int start = 0;
    //   for (int j = 0; j < input.length(); j++) {
    //     if (input[j] == ' ' || j == input.length() - 1) {
    //       PWM_DIR[index] = input.substring(start, j).toInt();
    //       start = j + 1;
    //     }
    //   }
    // }
    // PWM_DIR[1] = (map(RemoteXY.joystick_01_x, -100, 100, -32000, 32000));
    // PWM_DIR[2] = (map(RemoteXY.joystick_01_y, -100, 100, -32000, 32000));
    move(PWM_DIR[1], PWM_DIR[2]);
    delay(50);
  }
}
