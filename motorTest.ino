int pin1 = 10;
int pin2 = 11;

void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  analogWrite(pin1,LOW);
  analogWrite(pin2,LOW);

}

void rot_dir1(int speed)
{
  analogWrite(pin2,LOW);
  analogWrite(pin1,speed);
}

void rot_dir2(int speed)
{
  analogWrite(pin1,LOW);
  analogWrite(pin2,speed);
}

void loop() { 
  rot_dir1(255);
  delay(2000);
  rot_dir2(255);
  delay(2000);
}
