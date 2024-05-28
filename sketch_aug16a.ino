uint8_t LED_PIN;
uint8_t LED_PIN6 = 6;
uint8_t LED_PIN5 = 5;
uint8_t LED_PIN4 = 4;


void setup()
{
  pinMode(LED_PIN6, OUTPUT);
  pinMode(LED_PIN5, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);

}


void dash(int n){
  for (int i = 0; i < n; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(600);
    digitalWrite(LED_PIN, LOW);

    delay(200);
  }
}

void dot(int n){
  for (int i = 0; i < n; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);

    delay(200);
  }
}

void loop()
{
  LED_PIN = LED_PIN6;
  dash(1);
  dot(1);
  dash(3);

  LED_PIN = LED_PIN5;
  dash(1);
  LED_PIN = LED_PIN4;
  dot(1);
  LED_PIN = LED_PIN6;
  dash(1);
  LED_PIN = LED_PIN5;
  dot(1);
  LED_PIN = LED_PIN6;
  dash(1);


  exit(0);
}