// Define the pins connected to the L298 module
const int motorEnablePin = 10;   // Pin connected to the Enable input of the L298
const int motorInput1 = 9;   // Pin connected to Input 1 of the L298
const int motorInput2 = 7;      // Pin connected to Input 2 of the L298

void setup() {
  // Set the motor control pins as outputs
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  
  // Initialize the motor to stop
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  
  // Set the initial speed of the motor
  analogWrite(motorEnablePin, 0);  // Motor initially stopped
}

void loop() {
  // Move the motor forward
  motorControl(true, 255);  // Move forward at full speed
  delay(2000);  // Wait for 2 seconds
  
  // Stop the motor
  motorControl(false, 0);   // Stop the motor
  delay(1000);  // Wait for 1 second
  
  // Move the motor backward
  motorControl(false, 200);  // Move backward at reduced speed
  delay(2000);  // Wait for 2 seconds
  
  // Stop the motor again
  motorControl(false, 0);   // Stop the motor
  delay(1000);  // Wait for 1 second
}

// Function to control the motor direction and speed
void motorControl(bool direction, int speed) {
  digitalWrite(motorInput1, direction);
  digitalWrite(motorInput2, !direction);
  analogWrite(motorEnablePin, speed);
}

