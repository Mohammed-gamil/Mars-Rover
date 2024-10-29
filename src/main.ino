// Define motor control pins
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

void setup() {
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
    // Move forward
    digitalWrite(dirPinA, HIGH);
    digitalWrite(dirPinB, HIGH);
    ledcWrite(pwmChannelA, 255);
    ledcWrite(pwmChannelB, 255);
    delay(2000);

    // Move backward
    digitalWrite(dirPinA, LOW);
    digitalWrite(dirPinB, LOW);
    ledcWrite(pwmChannelA, 255);
    ledcWrite(pwmChannelB, 255);
    delay(2000);

    // Right tank turn
    digitalWrite(dirPinA, HIGH);
    digitalWrite(dirPinB, LOW);
    ledcWrite(pwmChannelA, 255);
    ledcWrite(pwmChannelB, 255);
    delay(2000);

    // Left tank turn
    digitalWrite(dirPinA, LOW);
    digitalWrite(dirPinB, HIGH);
    ledcWrite(pwmChannelA, 255);
    ledcWrite(pwmChannelB, 255);
    delay(2000);
}
