#define TRIG_PIN 10
#define ECHO_PIN 11

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  float cm = duration ? duration * 0.0343 / 2.0 : 999.0;

  Serial.print("Distance cm: ");
  Serial.println(cm);
  delay(100);
}
