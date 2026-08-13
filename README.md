# WRO 2026 Future Engineers – Aurum TriMech

## Team
**School:** Dawn High School  
**Category:** WRO 2026 Future Engineers  
**Coach:** Faraaz Mohiuddin

**Team members**
- Syed Umar
- Muhammed Adil Akhtar
- Abdul Rahman uddin

### About Aurum TriMech
Aurum TriMech is a team of three enthusiastic young engineers—Umar, Adil, and Abdul Rahman—who share a passion for robotics, engineering, and innovation. Their experience spans school- and district-level science fairs, technology exhibitions, college robotics events such as Robo Wars, and WRO. Through these experiences, the team has developed practical skills in LEGO robotics, chassis design, mechanical mechanisms, Arduino programming, and engineering problem-solving.

## Current Vehicle Direction
Our current design is a LEGO Technic-based autonomous vehicle with Ackermann-style front steering and a mechanical differential gearbox on the driving axle.

| Subsystem | Current direction |
|---|---|
| Main vehicle controller | Arduino Uno or Arduino Mega – under evaluation |
| Vision processor | Raspberry Pi |
| Chassis | LEGO Technic |
| Drive motor | 1 × N20 6V 200 RPM geared motor with encoder |
| Backup motor | 1 × identical N20 |
| Motor driver | DRV8833 |
| Drivetrain | Mechanical differential gearbox |
| Steering | Ackermann-style front steering + servo |
| IMU | MPU6500 |
| Distance sensing | 3 sensors: left, front, right |
| Power | ~11V rechargeable battery or high-quality power bank – under evaluation |
| Regulation | MP1584 3A / TPS565201 5V 5A modules for testing |
| Vision | Raspberry Pi + camera; final configuration under development |

## Architecture

```text
                    RASPBERRY PI
                  Vision Processing
                         |
                  perception data
                         |
                         v
                ARDUINO UNO / MEGA
                Main Vehicle Control
                         |
          +--------------+--------------+
          |              |              |
       DRV8833      Steering Servo    MPU6500
          |        Ackermann Steering    |
       N20 Motor                         |
      + Encoder                          |
          |                              |
 Mechanical Differential                |
       /       \                         |
 Rear Wheel  Rear Wheel                 |
                                         |
              Left / Front / Right Distance Sensors
```

## Engineering Evolution
The project has evolved through testing:
- Arduino Uno and ESP32 experiments → Uno/Mega vehicle controller with Raspberry Pi vision direction.
- BO motors and JGB37 experiments → N20 6V 200 RPM encoder motor selected.
- L298N → TB6612FNG considered → DRV8833 selected.
- MPU6050 experiments → MPU6500 selected.
- ESP32-CAM experiments → Raspberry Pi intended for vision.
- Mechanical direction → LEGO Technic chassis, Ackermann steering and mechanical differential.

Experimental code and troubleshooting records are retained because they explain why our architecture changed.

## Documentation
- [Engineering Journal](documentation/engineering-journal.md)
- [Hardware Inventory](documentation/hardware-inventory.md)
- [Mobility Management](documentation/mobility-management.md)
- [Power and Sense Management](documentation/power-and-sense-management.md)
- [Obstacle Management](documentation/obstacle-management.md)
- [Software Architecture](documentation/software-architecture.md)
- [Troubleshooting Log](documentation/troubleshooting-log.md)

## Still To Finalize
- Arduino Uno vs Mega
- Raspberry Pi model and camera
- exact three distance-sensor models
- final steering servo
- final battery vs power-bank choice
- Pi-to-Arduino communication protocol
- encoder and steering calibration
- final wiring schematic
- final Open and Obstacle Challenge code
- final vehicle photographs and videos
