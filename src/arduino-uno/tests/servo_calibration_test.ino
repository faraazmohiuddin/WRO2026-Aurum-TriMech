#include <Servo.h>
Servo steering;

void setup() {
  steering.attach(9);
}

void loop() {
  steering.write(90);   // centre test
  delay(1500);
  steering.write(60);   // conservative left test
  delay(1500);
  steering.write(90);
  delay(1500);
  steering.write(120);  // conservative right test
  delay(1500);
}
// IMPORTANT: Calibrate safe angles on the real steering linkage.
