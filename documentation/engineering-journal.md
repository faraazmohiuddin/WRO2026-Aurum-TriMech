[engineering-journal.md](https://github.com/user-attachments/files/31033478/engineering-journal.md)
# Engineering Journal

## Current Architecture
The present direction is a LEGO Technic vehicle using Ackermann steering, a mechanical differential, one N20 6V 200 RPM encoder motor, DRV8833, MPU6500, three distance sensors, an Arduino Uno or Mega for vehicle control, and Raspberry Pi for vision.

## Controllers
Early work explored Arduino Uno, ESP32 DevKit and ESP32-CAM. The current direction separates responsibilities:
- Arduino Uno or Mega for real-time vehicle control;
- Raspberry Pi for vision processing.

The Uno/Mega decision remains open until I/O and communication requirements are tested.

## Drivetrain
BO motors, N20 variants and JGB37-520 were explored. The current selected drive motor is an N20 6V 200 RPM geared motor with encoder. Two were ordered, but **one is intended for drive and the second is a backup**.

A mechanical differential gearbox will connect the drive motor to the driving axle.

## Chassis and Steering
The current chassis direction uses LEGO Technic for rapid mechanical iteration. Front steering uses Ackermann geometry with servo actuation.

## Motor Drivers
Development path:
1. L298N experiments;
2. TB6612FNG considered;
3. DRV8833 selected for the current N20 drivetrain.

## Orientation
MPU6050 was used in earlier experiments. MPU6500 is the current selected IMU.

## Distance Sensing
Three distance sensors are planned at left, front and right. Exact models remain to be finalized.

## Vision
ESP32-CAM was explored for colour detection and simple serial communication. The current intended vision system uses Raspberry Pi plus camera, with perception results passed to the Arduino controller.

## Power
The current decision remains open between an approximately 11V rechargeable battery and a high-quality power bank. MP1584 3A and TPS565201 5V 5A modules are available/ordered for regulation testing.

The final choice will be based on measured stability, current capability, weight and runtime.

## Next Tests
- build LEGO Technic rolling chassis;
- construct/test Ackermann steering;
- integrate mechanical differential;
- test N20 + DRV8833;
- read and calibrate encoder;
- test MPU6500;
- select/test three distance sensors;
- compare Uno vs Mega I/O requirements;
- test power options under load;
- start Raspberry Pi camera pipeline;
- define Pi-to-Arduino communication;
- add measured results, photographs and videos.
