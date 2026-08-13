# Changelog

This file records meaningful architecture and documentation changes. Dates can be added/adjusted to match the team's actual build log.

## v0.3 – Current Architecture Direction

- Selected N20 6V 200 RPM encoder motor as current drive motor.
- Second identical N20 retained as backup.
- Selected DRV8833 as current motor driver.
- Selected MPU6500 as current IMU.
- Defined LEGO Technic chassis direction.
- Defined Ackermann-style front steering.
- Defined mechanical differential gearbox for driving axle.
- Defined three distance-sensor positions: left, front and right.
- Moved intended vision processing to Raspberry Pi.
- Kept Arduino Uno vs Mega as an open integration decision.
- Began comparison of ~11V battery and high-quality power-bank approaches.
- Added MP1584 and TPS565201 power-regulation options.
- Added engineering decision, calibration, testing and risk documentation.

## v0.2 – Controller and Vision Experiments

- Tested Arduino/ESP32 motor-control concepts.
- Explored ESP32-CAM for vision.
- Tested simple controller-to-controller serial messages.
- Investigated JGB37-520 and N20 drivetrain options.
- Considered L298N and TB6612FNG motor drivers.
- Conducted MPU6050/IMU experiments.

## v0.1 – Early Prototype Work

- Basic motor-driver tests.
- BO motor tests.
- Servo steering tests.
- Initial autonomous-vehicle architecture exploration.

## Future Releases

Future entries should include:
- final Uno/Mega selection;
- final distance-sensor selection;
- final power architecture;
- Raspberry Pi/camera configuration;
- first complete rolling chassis;
- first autonomous Open Challenge run;
- first Obstacle Challenge run;
- measured performance improvements.
