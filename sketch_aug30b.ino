#define echoPin                                            
    2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin                                            
    3 // attach pin D3 Arduino to pin Trig of HC-SR04                                          
 
 
long duration; // Variable to store time taken to the pulse
               // to reach receiver
 
double distance; // Variable to store distance calculated using
              // formula

int grid_length = 500;     //in cm

int no_of_grids = 0;

int max_grids = 5;
 
void setup()
{
    pinMode(trigPin,
            OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
 
    // Serial Communication is starting with 9600 of
    // baudrate speed
    Serial.begin(9600);
    delay(500);
}
 
void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); // wait for 2 ms to avoid
                          // collision in serial monitor
 
    digitalWrite(
        trigPin,
        HIGH); // turn on the Trigger to generate pulse
    delayMicroseconds(
        10); // keep the trigger "ON" for 10 ms to generate
             // pulse for 10 ms.
 
    digitalWrite(trigPin,
                 LOW); // Turn off the pulse trigger to stop
                       // pulse generation
 
    // If pulse reached the receiver echoPin
    // become high Then pulseIn() returns the
    // time taken by the pulse to reach the
    // receiver
 
    duration = pulseIn(echoPin, HIGH);
    distance
        = duration * 0.0344 / 2; // Expression to calculate
                                 // distance using time

    no_of_grids = static_cast<int>distance / grid_length;
    if (no_of_grids > max_grids){
      no_of_grids = max_grids;
    }
      // Send data to Raspberry Pi
    Serial.print("Grids: ");
    Serial.println(no_of_grids);
    delay(100);
}