# Power and Sense Management

## Power
Development used a 2×18650 battery concept (nominal 7.4 V), USB power for programming, and several regulator/power-routing experiments. L298N 5 V output was used in some early tests. Stable regulated power is especially important for servos and ESP32-CAM.

All communicating modules require a common ground.

Do not power a high-current steering servo from the Arduino Uno 5 V pin without verifying current requirements and regulation.

## Sensors

### MPU6050
Purpose: orientation and turn measurement.
Uno I2C pins: SDA=A4, SCL=A5.

### HC-SR04
Purpose: basic distance/wall/obstacle measurement.
One test assignment: TRIG=D10, ECHO=D11.

### Motor encoder
The JGB37-520 encoder is intended for rotation/distance feedback. Pin mapping and counts-per-revolution must be measured for the exact motor.

### Vision
AI Thinker ESP32-CAM was tested as a colour-detection subsystem. OpenMV and Pixy2 were considered alternatives. Final vision hardware is not yet frozen.
