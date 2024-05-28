/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3SXfcqT3t"
#define BLYNK_TEMPLATE_NAME "led1"
#define BLYNK_AUTH_TOKEN "23EckB6umDmD9rplwj2K7Hjq6gEdvDmg"

#include <SPI.h>
//#include <Ethernet.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "jia";
char pass[] = "jia12345";


int LED = D4; // Define LED as an Integer (whole numbers) and pin D8 on Wemos D1 Mini Pro

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(LED, OUTPUT); //Set the LED (D8) as an output
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop()
{
  Blynk.run();
 
}
 
// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V0) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V0 to a variable
 if (pinValue == 1) {
    digitalWrite(LED, HIGH); // Turn LED on.
  } else {
    digitalWrite(LED, LOW); // Turn LED off.
 }
}