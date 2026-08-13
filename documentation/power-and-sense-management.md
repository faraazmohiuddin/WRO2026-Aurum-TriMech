[power-and-sense-management.md](https://github.com/user-attachments/files/31033605/power-and-sense-management.md)
# Power and Sense Management

## Power Source
Two options are being evaluated:
1. approximately 11V rechargeable battery;
2. high-quality power bank.

The final choice will be based on current capability, voltage stability, runtime, weight and compatibility with the Raspberry Pi, motor and servo.

The selected N20 drive motor is rated for 6V. If a higher-voltage battery is used, an appropriate motor-control/power strategy is required; full battery voltage should not simply be applied continuously to the motor.

## Regulation
- MP1584 adjustable 3A buck modules ×2
- TPS565201 5V 5A step-down module

Final rail allocation will follow load and thermal testing.

## MPU6500
The selected IMU is the MPU6500 6-axis gyro/accelerometer. Intended uses include turn measurement, orientation monitoring and heading-change estimation. Earlier MPU6050 work remains engineering history.

## Encoder
The N20 encoder may provide speed, rotation count, approximate travelled distance and feedback for repeatable motion.

## Three Distance Sensors
Three sensors are planned:
- **Left:** side/boundary clearance
- **Front:** forward clearance
- **Right:** side/boundary clearance

The exact sensor model is not yet finalized, so interfaces and pin assignments remain open.

## Vision
A Raspberry Pi is intended to process camera information. Exact Pi model, camera and vision software remain under development.

## Sensor Fusion Direction
The vehicle can combine:
- encoder → drivetrain movement;
- MPU6500 → orientation/rotation;
- left/front/right sensors → surrounding geometry;
- Raspberry Pi → visual perception.
