// HISTORICAL ESP32 communication concept
// Receive simple R/G commands from an ESP32-CAM or other vision controller.

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
}

void loop() {
  if (Serial2.available()) {
    char c = Serial2.read();
    if (c == 'R' || c == 'G') {
      Serial.print("Vision command: ");
      Serial.println(c);
      // Earlier experiments mapped these to motor actions.
      // Final obstacle logic must use calibrated steering/path planning.
    }
  }
}
