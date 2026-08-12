// Arduino Uno + TB6612FNG single-motor bench test
#define PWMA 5
#define AIN1 7
#define AIN2 8
#define STBY 4

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void loop() {
  // Forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 130);
  delay(2000);

  // Stop
  analogWrite(PWMA, 0);
  delay(1000);

  // Reverse - bench test only
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 130);
  delay(2000);

  analogWrite(PWMA, 0);
  delay(1500);
}
