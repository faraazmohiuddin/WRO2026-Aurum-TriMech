// HISTORICAL ESP32-CAM SERIAL COMMUNICATION TEST
// This does NOT perform image detection.
// It verifies that simple colour-result commands can be transmitted.

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println('G');
  delay(3000);
  Serial.println('R');
  delay(3000);
}
