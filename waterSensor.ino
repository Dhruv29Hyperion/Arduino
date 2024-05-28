#include <ESP8266WiFi.h>
#define sensorPin A0
#define relayPin D1  // Pin connected to the relay module


void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT); // Set relay pin as an output
}

void loop() {
  int moistureLevel = readSensor(); // Read moisture level from the sensor
  Serial.print("Analog output: ");
  Serial.println(moistureLevel);
  
  if (moistureLevel < 10) {  // Adjust the threshold value based on your sensor readings
    // If moisture level is below the threshold, turn on the water pump
    digitalWrite(relayPin, HIGH);
    Serial.print("Pumping Water");
  } else {
    // If moisture level is above the threshold, turn off the water pump
    digitalWrite(relayPin, LOW);
  }

  delay(500);
}

int readSensor() {
  int sensorValue = analogRead(sensorPin);  // Read the analog value from the sensor
  int outputValue = map(sensorValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data
  return outputValue; // Return analog moisture value
}