// Define the pins connected to the IR sensor and the motor driver
const int IRSensorPin = 2;      // Pin connected to the IR sensor module output
const int motorEnablePin = 10;   // Pin connected to the Enable input of the motor driver
const int motorInput1 = 9;       // Pin connected to Input 1 of the motor driver
const int motorInput2 = 8;       // Pin connected to Input 2 of the motor driver

void setup() {
  Serial.begin(9600); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  // Set the IR sensor pin as an input
  pinMode(IRSensorPin, INPUT);
  
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
  // Read the IR sensor value
  int obstacleDetected = digitalRead(IRSensorPin);

  if (obstacleDetected == LOW) {
    // No obstacle detected, rotate the motor clockwise
    motorControl(true, 255);  // Rotate clockwise at full speed
    Serial.println("Obstacle detected! :Motor rotate counterclockwise");
  } else {
    // Obstacle detected, rotate the motor counterclockwise
    motorControl(false, 255); // Rotate counterclockwise at full speed
    Serial.println("No Obstacle detected! : Motor rotate clockwise");
  }
}

// Function to control the motor direction and speed
void motorControl(bool direction, int speed) {
  digitalWrite(motorInput1, direction);
  digitalWrite(motorInput2, !direction);
  analogWrite(motorEnablePin, speed);
}
