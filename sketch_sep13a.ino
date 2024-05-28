int pin1 = 10;
int pin2 = 11;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  analogWrite(pin1, LOW);
  analogWrite(pin2, LOW);
}