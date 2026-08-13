[obstacle-management.md](https://github.com/user-attachments/files/31033581/obstacle-management.md)
# Obstacle Management

## Current Direction
A Raspberry Pi is intended to provide vision processing for the Obstacle Challenge.

```text
Camera
  |
Raspberry Pi
Vision / Perception
  |
Arduino Uno / Mega
Vehicle Decision + Real-Time Control
  |
  +--> Steering Servo
  +--> DRV8833 --> N20 Drive Motor
```

## Responsibilities
The Raspberry Pi will focus on camera/image processing. The Arduino Uno/Mega will handle motor control, steering, encoder feedback, MPU6500, three distance sensors, vehicle state and reception of Pi perception data.

## Distance Sensing
Left, front and right distance measurements will complement camera information with direct geometric information.

## Future Decision Logic
The controller may combine Raspberry Pi perception, three distance measurements, MPU6500 orientation, encoder feedback and current vehicle state to choose steering and propulsion actions.

The exact camera, vision algorithm and Pi-to-Arduino protocol remain under development.

## Earlier Experiments
ESP32-CAM and simple `R`/`G` serial communication were explored earlier. These experiments remain documented as engineering history but are not the intended final vision architecture.
