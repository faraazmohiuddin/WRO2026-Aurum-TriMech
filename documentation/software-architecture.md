[software-architecture.md](https://github.com/user-attachments/files/31033616/software-architecture.md)
# Software Architecture

## Current Two-Processor Direction

### Raspberry Pi
Intended responsibilities:
- camera acquisition;
- image processing;
- traffic-sign/obstacle perception;
- sending compact perception results to the Arduino.

### Arduino Uno or Mega
Intended responsibilities:
- DRV8833 motor control;
- steering servo;
- N20 encoder;
- MPU6500;
- three distance sensors;
- Raspberry Pi communication;
- vehicle state machine and real-time movement decisions.

## Uno vs Mega
The Uno is familiar and compact. The Mega provides more I/O and hardware serial resources. Final selection will follow integration testing of the three distance sensors, encoder, MPU6500, motor driver, servo, Pi communication and debugging requirements.

## Proposed Software Layers

**Raspberry Pi**
1. camera driver
2. image processing
3. perception
4. navigation/perception message generation
5. communication

**Arduino**
1. hardware drivers
2. sensor acquisition
3. calibrated values
4. motor/steering primitives
5. state machine
6. navigation decisions

Possible states include START, DRIVE_STRAIGHT, APPROACH_CORNER, TURN, ALIGN, OBSTACLE_RESPONSE, RECOVER and STOP. These remain architectural placeholders until tested.

## Historical Architecture
Earlier development explored ESP32 DevKit and ESP32-CAM controller communication. Those files are retained as engineering history.
