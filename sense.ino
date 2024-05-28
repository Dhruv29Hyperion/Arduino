/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3SXfcqT3t"
#define BLYNK_TEMPLATE_NAME "led1"
#define BLYNK_AUTH_TOKEN "23EckB6umDmD9rplwj2K7Hjq6gEdvDmg"


#include <ESP8266WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "jia"; 
char pass[] = "jia12345";

#define DHTPin D2
#define DHTTYPE DHT22  // DHT22 SENSOR CONNECT D2 PIN
DHT dht(DHTPin, DHTTYPE);

#define sensorPin A0
#define relayPin D1  // Pin connected to the relay module

// Declaring a global variable for sensor data
int moistureLevel;
float Humidity;
float Temperature;

// This function creates the timer object. It's part of Blynk library 
BlynkTimer timer; 

void myTimer() 
{
  // This function describes what will happen with each timer tick
  // e.g. writing sensor value to datastream V5
  Blynk.virtualWrite(V0, moistureLevel);  
  Blynk.virtualWrite(V1, Temperature);  
  Blynk.virtualWrite(V2, Humidity);  

}

void setup()
{
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  dht.begin();

  //Connecting to Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
  
  // Setting interval to send data to Blynk Cloud to 1000ms. 
  // It means that data will be sent every second
  timer.setInterval(1000L, myTimer);
}

void dht_read()
{
  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(Humidity) || isnan(Temperature))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(Humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(Temperature);
  Serial.println(F("°C "));
}

int readSensor()
{
  int sensorValue = analogRead(sensorPin); // Read the analog value from the sensor
  int outputValue = map(sensorValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data
  return outputValue;                                  // Return analog moisture value
}

void loop()
{
  dht_read();
  

  moistureLevel = readSensor();          // Read moisture level from the sensor
  Serial.print("Analog output: ");
  Serial.println(moistureLevel);

  if (moistureLevel < 10) // Adjust the threshold value based on your sensor readings
  {
    // If moisture level is below the threshold, turn on the water pump (relay)
    digitalWrite(relayPin, HIGH);
    Serial.println("Pumping Water");
  }
  else
  {
    // If moisture level is above the threshold, turn off the water pump (relay)
    digitalWrite(relayPin, LOW);
  }

    // Runs all Blynk stuff
  Blynk.run(); 
  
  // runs BlynkTimer
  timer.run();

  delay(500);
}