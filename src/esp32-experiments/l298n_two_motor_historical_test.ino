// HISTORICAL TEST: ESP32 DevKit V1 + L298N
// Retained to document the engineering path.
// Pin map discussed/tested during development.

#define ENA 26
#define IN1 27
#define IN2 14
#define ENB 33
#define IN3 32
#define IN4 13

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  delay(2000);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  delay(1000);
}
