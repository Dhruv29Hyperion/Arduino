
// Define the pin numbers for the sensors and motors
const int leftSensorPin = 2;  // Left sensor connected to digital pin 2
const int rightSensorPin = 4; // Right sensor connected to digital pin 3
const int leftMotorPin1 = 10;  // Left motor control pin 1
const int leftMotorPin2 = 11;  // Left motor control pin 2
const int rightMotorPin1 = 12; // Right motor control pin 1
const int rightMotorPin2 = 13; // Right motor control pin 2

// Define the threshold for detecting the line
const int threshold = 500; // Adjust this value according to your sensors

// Define motor control functions
void forward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void left() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void right() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

void stopMotors() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}

void setup() {
  // Initialize sensor pins as INPUT
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  
  // Initialize motor control pins as OUTPUT
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
}

void loop() {
  // Read sensor values
  forward();
}


