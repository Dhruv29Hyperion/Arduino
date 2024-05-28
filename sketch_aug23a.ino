// LED Brightness control using PWM

int low = 0;
int high = 255;

int pin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (low != high){
    analogWrite(pin, low);
    low += 5;
    delay(100);
  }
  while (high != 0){
    analogWrite(pin, high);
    high -= 5;
    delay(100);
  }
  exit(0);
}
