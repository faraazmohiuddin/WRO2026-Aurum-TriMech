# WRO 2026 Future Engineers – Self-Driving Car

> **Status:** Active engineering project for the WRO 2026 Future Engineers category.  
> This repository records the development process, experiments, design decisions, source code, wiring, testing, failures, and current vehicle architecture.

## Repository purpose

This repository is our engineering record for the World Robot Olympiad (WRO) 2026 Future Engineers challenge. The project is an autonomous steering vehicle. Our approach has developed through repeated hardware and software experiments rather than beginning with one fixed final design.

During development we tested Arduino Uno, ESP32 DevKit V1 and ESP32-CAM based ideas; L298N and TB6612FNG motor-control approaches; BO motors, an N20 geared motor and a JGB37-520 geared motor with encoder; SG90 and higher-torque steering-servo options; ultrasonic sensing, IMU sensing and camera-based colour detection.

The current direction is deliberately simpler: use an **Arduino Uno as the main controller**, a **TB6612FNG motor driver**, a **JGB37-520 12 V 111 RPM geared motor with encoder** for propulsion, servo steering, an MPU6050 for orientation experiments, and distance sensing. Vision is treated as a later subsystem to add after basic mobility is reliable.

This repository distinguishes between:
- **current architecture** – the direction presently being developed;
- **tested experiments** – hardware/software we actually tried;
- **considered options** – components or approaches discussed but not necessarily used in the final vehicle.

That distinction is important because the engineering process includes unsuccessful tests and changes of direction.

---

## Contents

- [Team](#team)
- [Challenge](#challenge)
- [Current vehicle concept](#current-vehicle-concept)
- [Engineering evolution](#engineering-evolution)
- [Mobility management](#mobility-management)
- [Power and sense management](#power-and-sense-management)
- [Software architecture](#software-architecture)
- [Obstacle management](#obstacle-management)
- [Testing and iteration](#testing-and-iteration)
- [Repository structure](#repository-structure)
- [Build and upload](#build-and-upload)
- [Items still to add](#items-still-to-add)

---

## Team

### Aurum TriMech

**School / organisation:** Dawn High School  
**Category:** WRO 2026 Future Engineers  
**Coach:** Faraaz Mohiuddin

**Team members:**
- Syed Umar
- Muhammed Adil Akhtar
- Abdul Rahman uddin

### About the Team

Aurum TriMech is a team of three enthusiastic young engineers—Umar, Adil, and Abdul Rahman—who share a passion for robotics, engineering, and innovation. Their experience spans school- and district-level science fairs, technology exhibitions, college robotics events such as Robo Wars, and the World Robot Olympiad (WRO).

Through these experiences, the team has developed practical skills in LEGO robotics, chassis design, mechanical mechanisms, Arduino programming, and engineering problem-solving. For WRO 2026 Future Engineers, they are bringing these skills together to design, build, test, and continuously improve an autonomous self-driving vehicle.

---

## Challenge

Future Engineers is an autonomous-driving engineering challenge. The vehicle must use steering and autonomous control to navigate the competition track. Our development therefore focuses on four connected problems:

1. reliable propulsion;
2. repeatable steering;
3. sensing the vehicle's environment and orientation;
4. autonomous decision-making for the Open and Obstacle challenges.

Our engineering priority is reliability. We first want a vehicle that can drive straight, steer predictably and complete controlled turns. More complex perception is added only after the mobility platform is dependable.

---

## Current vehicle concept

### Main controller
**Arduino Uno R3 / Uno-compatible ATmega328P board**

We moved toward the Uno because it is familiar, easy to program and sufficient for the first version of the low-level vehicle controller.

### Drive motor
**JGB37-520, 12 V, 111 RPM geared DC motor with encoder**

This motor is currently the strongest candidate for the drive system. The encoder gives us a path toward measuring wheel rotation and travelled distance.

Earlier development also considered and tested:
- N20 6 V 100 RPM geared motor, including an encoder variant;
- N20 12 V 600 RPM as an option;
- two BO motors for bench/testing work.

### Motor driver
**TB6612FNG – current preferred driver**

Earlier experiments used an L298N. It was useful for testing and is well understood by the team, but the TB6612FNG is the preferred direction for the compact Uno build.

### Steering
Servo steering is used at the front. We began with an **SG90** for tests. A **DS3218 high-torque servo** has been considered for a stronger final steering mechanism. The final servo choice must match the completed chassis and steering load.

### Orientation
**MPU6050** is used for IMU experiments. The goal is to use orientation/turn information to improve repeatability rather than relying only on timed turns.

### Distance sensing
**HC-SR04 ultrasonic sensing** has been used/considered for simple distance measurement. Time-of-Flight sensors have also been discussed as a possible upgrade.

### Vision
Camera-based red/green traffic-sign detection has been an important experimental branch. We worked with an **AI Thinker ESP32-CAM** and also considered **OpenMV** and **Pixy2** style vision approaches. Vision is not presented here as a finished subsystem. The present strategy is to make the basic Uno mobility system reliable first, then integrate the most dependable vision method.

---

## Engineering evolution

### Phase 1 – Basic motor and steering experiments

Early tests focused on understanding:
- DC motor direction and speed control;
- L298N wiring;
- servo centring and left/right positions;
- powering the controller, driver and actuators;
- common-ground requirements.

SG90 steering tests used approximately:
- centre: 90°;
- left/right extremes were explored experimentally, including 0° and 180°.

These values are test values, not guaranteed final steering angles. Mechanical steering limits must be calibrated to avoid stressing the linkage.

### Phase 2 – ESP32 DevKit vehicle control

An ESP32 DevKit V1 was tested as the main controller. One working/test pin map used:

| Function | ESP32 GPIO |
|---|---:|
| L298N ENA | 26 |
| L298N IN1 | 27 |
| L298N IN2 | 14 |
| L298N ENB | 33 |
| L298N IN3 | 32 |
| L298N IN4 | 13 |

Other experiments used GPIO25 for the steering-servo signal.

We encountered ESP32 PWM/library-version differences and adjusted code while learning the LEDC API.

### Phase 3 – ESP32-CAM experiments

The ESP32-CAM was explored for colour detection. The intended logic was deliberately simple:

- detect **green** → send a command to the vehicle controller;
- detect **red** → send a different command;
- vehicle controller decides which motor/steering action to perform.

A serial test successfully produced alternating `G` and `R` characters at 9600 baud, demonstrating the basic concept of one controller sending simple commands to another.

A tested ESP32-side concept used `Serial2` to receive these commands.

We also spent significant time troubleshooting ESP32-CAM programming. Errors included:
- `Failed to connect to ESP32: No serial data received`;
- download mode detected but no sync reply;
- serial TX path suspected;
- busy COM ports;
- upload/boot-mode confusion.

Programming approaches explored included:
- ESP32-CAM MB programmer board;
- Arduino Uno as USB-to-serial programmer;
- ESP32 DevKit as a programmer.

Important lessons:
- GPIO0 must be held LOW/GND for flashing on the AI Thinker ESP32-CAM;
- GPIO0 is released after upload for normal boot;
- stable 5 V power is important;
- TX/RX must be crossed correctly;
- all communicating boards require common ground;
- a charging-only USB cable can power a board while still being unable to upload code.

### Phase 4 – Simplification toward Arduino Uno

After experimenting with multiple ESP boards, we deliberately returned to a simpler architecture for the core vehicle.

The current philosophy is:

**Make mobility work first. Add complexity only when it solves a demonstrated problem.**

Current core path:

`Arduino Uno → TB6612FNG → JGB37-520 motor`

with

`Arduino Uno → steering servo`

and sensor inputs from the MPU6050, distance sensor and later the encoder/vision subsystem.

---

## Mobility management

### Propulsion

The present plan uses one geared drive motor. A major mechanical question has been how to transfer torque from one motor to both driven wheels.

Approaches discussed include:
- a common rear axle;
- gears;
- a compact gearbox;
- a differential;
- a custom/3D-printed mechanism.

We specifically explored the idea of a double-output mechanism for a single N20 motor before moving toward the larger JGB37 motor. The final drivetrain geometry is still dependent on the chassis.

### Steering

The vehicle uses car-like front steering rather than skid steering. Servo steering is preferred because WRO Future Engineers requires a steering-drive vehicle.

Important calibration tasks:
- determine true mechanical centre;
- find safe maximum left angle;
- find safe maximum right angle;
- reduce steering speed/jitter where necessary;
- verify that steering remains repeatable while the vehicle is moving.

### Encoder

The JGB37-520 motor includes an encoder. Planned uses:
- count wheel/motor rotations;
- estimate travelled distance;
- compare commanded movement with actual movement;
- improve repeatability of straight sections and stopping.

Encoder integration is still a development item and should be validated experimentally before it is relied upon in competition code.

---

## Power and sense management

### Power experiments

Power arrangements explored during development included:
- 2 × 18650 Li-ion cells (nominal 7.4 V pack);
- L298N onboard 5 V regulator during early tests;
- USB power for controller/programming;
- 5 V power to ESP32-CAM;
- buck-converter based regulation as an option.

A recurring lesson was that motors, servos and cameras can create power instability. The final vehicle should use a carefully regulated supply appropriate to each component.

**Never assume the Uno 5 V pin should directly power a high-current steering servo.**

All subsystems that exchange electrical signals must share a common ground.

### MPU6050

Typical Arduino Uno I2C connection:
- VCC → module-appropriate supply;
- GND → GND;
- SDA → A4;
- SCL → A5.

The IMU is intended to support turn/orientation measurement. Calibration and drift testing are required.

### Ultrasonic sensor

Typical HC-SR04 Uno connection in our simple test:
- TRIG → D10;
- ECHO → D11;
- VCC → 5 V;
- GND → GND.

The sensor can provide basic obstacle/wall distance information. Mounting angle and vibration can strongly affect readings.

---

## Software architecture

The current code is being developed as small testable modules rather than one large sketch.

### Layer 1 – Actuation
Functions for:
- drive forward;
- stop;
- reverse if required during testing;
- set motor PWM;
- steering centre/left/right.

### Layer 2 – Sensors
Functions for:
- ultrasonic distance;
- IMU orientation;
- encoder counts;
- later, vision command input.

### Layer 3 – Vehicle behaviour
Higher-level states can include:
- START;
- DRIVE_STRAIGHT;
- APPROACH_CORNER;
- TURN;
- RECOVER;
- STOP.

For the Obstacle challenge, perception adds states/decisions based on traffic-sign colour and position.

### Why modular code?

We repeatedly encountered situations where one subsystem worked while another failed. Small test sketches make it possible to isolate:
- wiring problems;
- power problems;
- bad pin assignments;
- sensor calibration errors;
- communication errors;
- algorithm errors.

---

## Obstacle management

Our obstacle strategy is still under development.

The camera experiments focused on detecting the red and green traffic signs. Rather than putting all motor logic on the camera, one proposed architecture was:

`Camera controller → simple R/G serial message → main vehicle controller → steering/motor decision`

This keeps perception separate from low-level actuation.

We tested serial command ideas where:
- `G` represented a green detection;
- `R` represented a red detection.

Earlier test logic included variants such as green commanding both test motors and red commanding one motor. Those were communication demonstrations, **not the final competition obstacle algorithm**.

For the final vehicle, colour, apparent position, distance, track geometry and steering response must be combined into a safe path around the traffic signs.

---

## Testing and iteration

Our development included several failures that directly changed our design.

### Motor tests
- one motor worked while a second motor did not in an early ESP32/L298N setup;
- BO motors were used as convenient test motors;
- N20 and JGB37 geared motors were evaluated for the final drivetrain;
- encoder availability and integration affected motor choices.

### Servo tests
- SG90 was used for initial steering experiments;
- stronger DS3218/DS3225 class servos were discussed because the final vehicle may require more steering torque;
- servo centre/left/right values require mechanical calibration.

### ESP32 upload problems
Repeated ESP32 and ESP32-CAM upload errors led us to investigate:
- board selection;
- COM port;
- BOOT/GPIO0;
- reset timing;
- USB drivers;
- USB cable data capability;
- stable power;
- programmer wiring.

A particularly useful hardware lesson was that a USB-A to Micro-USB cable can charge successfully but still lack functioning data lines.

### Camera power/programming
The ESP32-CAM was most reliable when powered/programmed using the ESP32-CAM MB board. Other power/programming arrangements were explored but were less consistent.

### Design lesson
Complexity does not automatically improve the robot. The project moved from a multi-controller ESP32/ESP32-CAM concept toward an Arduino Uno core because the immediate engineering need is dependable motion and steering.

---

## Repository structure

```text
WRO2026-FutureEngineers/
├── README.md
├── LICENSE
├── t-photos/
├── v-photos/
├── video/
├── schemes/
├── models/
├── src/
│   ├── arduino-uno/
│   │   ├── current/
│   │   └── tests/
│   ├── esp32-experiments/
│   └── esp32-cam-experiments/
├── documentation/
│   ├── engineering-journal.md
│   ├── mobility-management.md
│   ├── power-and-sense-management.md
│   ├── obstacle-management.md
│   ├── software-architecture.md
│   ├── hardware-inventory.md
│   └── troubleshooting-log.md
└── other/
```

---

## Build and upload

### Current Arduino Uno test build

1. Install Arduino IDE.
2. Select **Arduino Uno**.
3. Connect the Uno using a known data-capable USB cable.
4. Select the correct COM port.
5. Open the required `.ino` file from `src/arduino-uno/`.
6. Install any library required by that sketch.
7. Compile before connecting the full drivetrain.
8. Confirm wiring and common ground.
9. Upload.
10. Test one subsystem at a time.

The current basic integrated test sketch is in:

`src/arduino-uno/current/uno_basic_vehicle_test.ino`

It is intentionally a development sketch, not claimed as the final Open/Obstacle challenge program.

---

## Items still to add

Before final judging, this repository should be updated with:

- [ ] official team photo;
- [ ] funny/informal team photo if required;
- [ ] six final vehicle photos: front, rear, left, right, top, bottom;
- [ ] final electrical schematic;
- [ ] final mechanical drawings / CAD / STL files;
- [ ] final bill of materials;
- [ ] final Open Challenge code;
- [ ] final Obstacle Challenge code;
- [ ] encoder calibration results;
- [ ] steering calibration values;
- [ ] IMU calibration/test results;
- [ ] final vision approach and thresholds;
- [ ] autonomous driving video link(s);
- [ ] measured test results and iteration evidence.

---

## Engineering principle

The repository is intentionally honest about the state of development. Experiments that did not become part of the final vehicle are retained because they explain **why** the architecture changed. Our goal is not only to show a finished robot, but to make the engineering decisions, testing process and eventual solution understandable and reproducible.
