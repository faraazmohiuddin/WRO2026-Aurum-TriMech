#include <Wire.h>
#include <Servo.h>

// WRO 2026 Future Engineers
// BASIC INTEGRATION TEST - NOT FINAL COMPETITION CODE
// Arduino Uno + TB6612FNG + steering servo + MPU6050 + HC-SR04

#define PWMA 5
#define AIN1 7
#define AIN2 8
#define STBY 4

#define SERVO_PIN 9
#define TRIG_PIN 10
#define ECHO_PIN 11
#define MPU_ADDR 0x68

Servo steering;

void setup() {
  Serial.begin(115200);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  steering.attach(SERVO_PIN);
  steering.write(90); // temporary centre - calibrate mechanically

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.println("WRO FE basic vehicle test ready");
  delay(1500);
}

void loop() {
  float distance = getDistanceCM();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Simple bench/drive test only.
  // Replace with calibrated state-machine logic.
  if (distance > 30) {
    steering.write(90);
    driveForward(130);
  } else {
    stopMotor();
    delay(400);

    steering.write(125); // temporary test angle
    driveForward(115);
    delay(900);

    stopMotor();
    steering.write(90);
    delay(300);
  }

  delay(30);
}

void driveForward(int pwm) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, constrain(pwm, 0, 255));
}

void stopMotor() {
  analogWrite(PWMA, 0);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
}

float getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) return 999.0;
  return duration * 0.0343 / 2.0;
}
