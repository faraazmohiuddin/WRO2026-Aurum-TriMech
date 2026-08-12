# Engineering Journal

## Development summary

This journal records the major engineering work completed during the intensive development period before the WRO 2026 national round.

### Controller experiments
We worked with Arduino Uno, ESP32 DevKit V1 and AI Thinker ESP32-CAM. ESP32 gave us more processing and serial options, but upload reliability and integration complexity consumed significant development time. The current core vehicle direction uses Arduino Uno for simpler, more predictable low-level control.

### Motor and drivetrain experiments
We considered/tested BO motors, N20 geared motors and a JGB37-520 12 V 111 RPM motor with encoder. We want one drive motor with a mechanical transmission to the driven wheels. Gearbox, common-axle and differential concepts were explored.

### Motor drivers
L298N was used in early testing. TB6612FNG is the preferred current driver for the Uno build.

### Steering
SG90 was used for initial servo tests. Higher-torque DS3218/DS3225 class servos were considered for the final chassis. Final steering limits must be calibrated mechanically.

### Sensing
MPU6050 was selected for orientation experiments. HC-SR04 ultrasonic sensing was used/considered for distance. ToF sensing was discussed as an upgrade. JGB37 encoder integration is planned for distance/rotation feedback.

### Vision
ESP32-CAM colour detection was explored for red/green traffic signs. A simple serial protocol using `R` and `G` was tested. OpenMV, Pixy2 and other camera options were considered. Vision is being kept separate from the basic mobility milestone.

### Upload/debugging lessons
We encountered ESP32 connection, sync and COM-port problems. We learned to check boot mode, GPIO0, reset timing, board selection, stable power, TX/RX crossing, drivers, and whether the USB cable actually carries data.

### Current milestone
Build the minimum reliable autonomous platform:
Arduino Uno + TB6612FNG + JGB37 motor + servo steering + MPU6050 + distance sensor, then integrate encoder feedback and obstacle perception.

## TODO
Add dated photos, test tables, lap results, steering calibration, encoder counts and final design changes as they happen.
