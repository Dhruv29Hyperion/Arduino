// Variable for sensor value
int sensorval;
 
// Analog input port
#define SENSOR_IN 0
 
void setup() {
  // Open Serial Monitor
  Serial.begin(9600);
 
  // Set ADC to use 3.3-volt AREF input
  analogReference(EXTERNAL);
}
void loop() {
 
  // Read sensor value
  sensorval = analogRead(SENSOR_IN);
 
  // Print to Serial Monitor
  Serial.println(sensorval);
 
  delay(100);
}

