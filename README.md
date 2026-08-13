[README-Aurum-TriMech-Corrected.md](https://github.com/user-attachments/files/31034423/README-Aurum-TriMech-Corrected.md)
# WRO 2026 Future Engineers – Aurum TriMech

> **Status:** Active engineering project for the WRO 2026 Future Engineers category.

## Team

**Team:** Aurum TriMech  
**Category:** WRO 2026 Future Engineers  
**Coach:** Faraaz Mohiuddin

**Team members**
- Syed Umar
- Muhammed Adil Akhtar
- Abdul Rahman uddin

### About Aurum TriMech

Aurum TriMech is a team of three enthusiastic young engineers—Umar, Adil, and Abdul Rahman—who share a passion for robotics, engineering, and innovation. Their experience spans school- and district-level science fairs, technology exhibitions, college robotics events such as Robo Wars, and the World Robot Olympiad (WRO). Through these experiences, the team has developed practical skills in LEGO robotics, chassis design, mechanical mechanisms, Arduino programming, and engineering problem-solving.

---

## Project Goal

Our goal is to design, build, test and progressively improve an autonomous four-wheel vehicle for WRO Future Engineers.

Rather than treating the robot as one large system, we are developing it as a set of testable subsystems:

1. **Mechanical mobility** – chassis, drive motor, differential and Ackermann steering.
2. **Low-level control** – motor, servo, encoder, IMU and distance sensors.
3. **Vision** – camera processing on a Raspberry Pi.
4. **Power** – stable regulated supplies for the motor, controller, servo, sensors and Raspberry Pi.
5. **Navigation software** – a state-based strategy combining sensor and vision information.

Our current design is still being tested. Where a component has not yet been selected or a measurement has not yet been made, the documentation marks it as **TBD** rather than presenting an assumption as a measured result.

---

## Current Vehicle Direction

| Subsystem | Current direction |
|---|---|
| Main vehicle controller | Arduino Uno or Arduino Mega – under evaluation |
| Vision processor | Raspberry Pi |
| Chassis | LEGO Technic-based custom chassis |
| Drive motor | 1 × N20 6V 200 RPM geared motor with encoder |
| Backup motor | 1 × identical N20 motor |
| Motor driver | DRV8833 |
| Driving axle | Mechanical differential gearbox |
| Steering | Ackermann-style front steering |
| Steering actuator | Servo motor – final model pending |
| IMU | MPU6500 6-axis gyro/accelerometer |
| Distance sensing | 3 sensors: left, front and right – exact model pending |
| Power source | ~11V rechargeable battery or high-quality power bank – under evaluation |
| Regulation | MP1584 3A and TPS565201 5V 5A modules available for testing |
| Vision | Raspberry Pi + camera – exact configuration under development |

---

## System Architecture

```text
                         CAMERA
                           |
                           v
                    +---------------+
                    | RASPBERRY PI  |
                    | Vision / CV   |
                    +-------+-------+
                            |
                    perception message
                            |
                            v
                    +---------------+
                    | ARDUINO       |
                    | UNO / MEGA    |
                    | Vehicle Ctrl  |
                    +---+---+---+---+
                        |   |   |
              +---------+   |   +---------+
              |             |             |
              v             v             v
          +--------+   +-----------+   +--------+
          |DRV8833 |   | Steering  |   |MPU6500 |
          +---+----+   | Servo     |   +--------+
              |        +-----------+
              v
       N20 6V 200 RPM
          + Encoder
              |
              v
     Mechanical Differential
          /             \
         v               v
    Rear Wheel       Rear Wheel

       LEFT       FRONT       RIGHT
        SENSOR     SENSOR      SENSOR
           \         |         /
            \        |        /
             +-------+-------+
                     |
                     v
               UNO / MEGA
```

---

## Mechanical Concept

### LEGO Technic chassis

LEGO Technic is being used as the primary chassis system because it allows us to change wheelbase, track width, motor position, gear placement, steering geometry and sensor mounts quickly during testing.

The intention is not simply to assemble a fixed kit. The chassis is being used as a rapid mechanical prototyping platform. Where a non-LEGO component such as the N20 motor needs an interface, a custom or 3D-printed adapter can be developed.

### Single drive motor

The selected drive motor is an **N20 6V 200 RPM geared DC motor with encoder**. Two identical motors were ordered, but the present design intends to use **one motor for propulsion and keep the second as a backup**.

The encoder gives us a way to measure drivetrain movement rather than relying only on timed motor commands.

### Mechanical differential

The N20 motor will drive the two wheels of the driving axle through a **mechanical differential gearbox**. The two wheels therefore remain part of one mechanical drivetrain while being able to rotate at different speeds during a turn.

### Ackermann steering

The front wheels will use **Ackermann-style steering** operated by a servo. The steering linkage will be calibrated so that the inner front wheel turns more sharply than the outer front wheel during a corner.

The final geometry will be determined by testing rather than by servo-angle assumptions alone.

---

## Drive Speed and Torque Reasoning

The motor's nominal gearbox output is 200 RPM, but motor RPM alone does not determine vehicle speed. Final speed also depends on:

- motor operating voltage;
- load;
- gear ratio between the motor and differential;
- differential/output gearing;
- wheel diameter;
- tyre deformation and slip.

Once the final wheel diameter and gear ratio are known, theoretical wheel speed will be calculated using:

```text
Wheel RPM = Motor RPM / Overall Gear Reduction

Wheel Circumference = pi × Wheel Diameter

Theoretical Speed = Wheel RPM × Wheel Circumference / 60
```

Theoretical speed will then be compared with measured vehicle speed. This comparison will help us decide whether gearing needs to be changed for better acceleration, corner control or straight-line speed.

Torque will be considered in the opposite direction: additional gear reduction lowers wheel speed but increases available wheel torque. The final choice therefore requires a compromise between speed and controllability.

Measured values are intentionally left as **TBD** until the assembled drivetrain is tested.

See [Mobility Management](documentation/mobility-management.md) and [Testing & Results](documentation/testing-and-results.md).

---

## Control and Vision Architecture

We are currently evaluating **Arduino Uno vs Arduino Mega** for the main vehicle controller.

The Arduino will be responsible for time-sensitive vehicle tasks such as:

- drive-motor commands;
- steering-servo commands;
- reading the motor encoder;
- reading the MPU6500;
- reading three distance sensors;
- receiving perception information from the Raspberry Pi;
- executing the vehicle state machine.

The **Raspberry Pi** is intended to handle the computationally heavier camera-processing work. Instead of directly controlling the motor, it will send useful perception information to the Arduino.

This separation lets us test vision and mobility independently and prevents a camera-processing problem from being mixed unnecessarily with basic motor-control debugging.

---

## Three-Sensor Layout

The intended distance-sensor arrangement is:

```text
                 FRONT
                   ^
                   |
             [Front Sensor]

 [Left Sensor]             [Right Sensor]
       <                         >
```

The proposed roles are:

- **Left sensor:** measure left-side clearance and help estimate lateral position.
- **Front sensor:** measure forward clearance and help identify approach conditions.
- **Right sensor:** measure right-side clearance and help estimate lateral position.

The exact sensor technology has not yet been selected. Ultrasonic, infrared and time-of-flight approaches will be compared using range, repeatability, field of view, update rate, pin requirements, physical size and behaviour on the actual field.

See [Power & Sense Management](documentation/power-and-sense-management.md).

---

## Power Architecture

Two power approaches are currently being evaluated:

1. an approximately **11V rechargeable battery**;
2. a **high-quality power bank**.

The final choice will be made after measuring or verifying:

- available current;
- voltage stability;
- peak-load behaviour;
- runtime;
- mass;
- Raspberry Pi compatibility;
- servo requirements;
- motor requirements.

The N20 motor is rated for 6V, so an approximately 11V source cannot simply be connected directly to the motor continuously. The DRV8833 and the final motor-supply strategy must be tested appropriately.

Available regulation hardware includes:

- 2 × MP1584 adjustable 3A buck modules;
- TPS565201 5V 5A step-down module.

A quantitative power budget is being prepared and will be updated with datasheet and measured values as the final hardware is selected.

---

## Proposed Navigation State Machine

```text
START
  |
  v
INITIALIZE / CALIBRATE
  |
  v
DRIVE_STRAIGHT <----------------------+
  |                                   |
  | corner / navigation condition     |
  v                                   |
APPROACH_CORNER                        |
  |                                   |
  v                                   |
TURN                                  |
  |                                   |
  v                                   |
ALIGN --------------------------------+

Vision obstacle / traffic-sign information
  |
  v
OBSTACLE_RESPONSE
  |
  v
RECOVER
  |
  +--------------------> DRIVE_STRAIGHT

Fault / finish condition
  |
  v
STOP
```

These state names are currently architectural placeholders. Each transition will be tied to measured sensor or vision conditions as testing progresses.

See [Software Architecture](documentation/software-architecture.md) and [Obstacle Management](documentation/obstacle-management.md).

---

## Engineering Evolution

The project has changed as the team learned more about the hardware.

| Area | Earlier exploration | Current direction |
|---|---|---|
| Controller | Arduino Uno, ESP32 DevKit | Uno or Mega for vehicle control |
| Vision | ESP32-CAM | Raspberry Pi + camera |
| Drive motor | BO motors, N20 100 RPM, JGB37-520 | N20 6V 200 RPM encoder motor |
| Motor driver | L298N, TB6612FNG considered | DRV8833 |
| IMU | MPU6050 | MPU6500 |
| Mechanical system | early test chassis | LEGO Technic + Ackermann + mechanical differential |
| Power | USB/18650 experiments | ~11V battery vs quality power bank evaluation |

We retain experimental code and troubleshooting information because the design history explains why the current architecture exists.

---

## Testing Philosophy

A subsystem is not considered final simply because it works once.

For each major subsystem we intend to record:

- what was tested;
- test conditions;
- expected behaviour;
- measured result;
- failure or deviation;
- change made;
- retest result;
- final decision.

Examples include:

- measured encoder counts per wheel revolution;
- straight-line deviation over a fixed distance;
- measured turning radius;
- IMU turn error;
- distance-sensor error at known distances;
- Raspberry Pi detection success rate;
- battery/power-bank runtime;
- regulator voltage under load.

The current test matrix is in [Testing & Results](documentation/testing-and-results.md).

---

## Engineering Decisions and Risks

Major component decisions are recorded separately so that the repository shows **why** the design changed, not just what the latest design contains.

See:

- [Engineering Decisions](documentation/engineering-decisions.md)
- [Risk & Failure Analysis](documentation/risk-and-failure-analysis.md)
- [Calibration](documentation/calibration.md)
- [Engineering Journal](documentation/engineering-journal.md)

---

## Documentation

### Engineering
- [Engineering Journal](documentation/engineering-journal.md)
- [Engineering Decisions](documentation/engineering-decisions.md)
- [Testing & Results](documentation/testing-and-results.md)
- [Calibration](documentation/calibration.md)
- [Risk & Failure Analysis](documentation/risk-and-failure-analysis.md)

### Vehicle subsystems
- [Hardware Inventory](documentation/hardware-inventory.md)
- [Mobility Management](documentation/mobility-management.md)
- [Power & Sense Management](documentation/power-and-sense-management.md)
- [Obstacle Management](documentation/obstacle-management.md)
- [Software Architecture](documentation/software-architecture.md)
- [Troubleshooting Log](documentation/troubleshooting-log.md)

### Project history
- [CHANGELOG](CHANGELOG.md)

---

## Repository Structure

```text
WRO2026-Aurum-TriMech/
├── README.md
├── CHANGELOG.md
├── documentation/
│   ├── engineering-journal.md
│   ├── engineering-decisions.md
│   ├── testing-and-results.md
│   ├── calibration.md
│   ├── risk-and-failure-analysis.md
│   ├── hardware-inventory.md
│   ├── mobility-management.md
│   ├── power-and-sense-management.md
│   ├── obstacle-management.md
│   ├── software-architecture.md
│   └── troubleshooting-log.md
├── models/
├── schemes/
├── src/
├── t-photos/
├── v-photos/
└── video/
```

---

## Current Open Decisions

The following are deliberately not presented as final:

- Arduino Uno vs Mega;
- exact Raspberry Pi model;
- camera model;
- exact three distance-sensor models;
- final steering servo;
- final power source;
- final regulator allocation;
- final gear ratio;
- final wheel diameter;
- final Pi-to-Arduino protocol;
- final navigation thresholds.

These will be closed through testing and recorded in the decision log.

---

## Next Development Milestones

1. Build the LEGO Technic rolling chassis.
2. Build and measure Ackermann steering.
3. Integrate the mechanical differential.
4. Install N20 motor and DRV8833.
5. Calibrate encoder counts and drivetrain distance.
6. Test MPU6500.
7. Select and calibrate three distance sensors.
8. Compare Uno and Mega integration requirements.
9. Measure power consumption under realistic loads.
10. Compare battery and power-bank approaches.
11. Build Raspberry Pi camera pipeline.
12. Define Pi-to-Arduino messages.
13. Implement and tune the state machine.
14. Record photographs, diagrams, measurements and videos.
15. Update this repository after every meaningful design iteration.

The aim of this repository is not only to show the final robot, but to make the team's engineering process understandable and reproducible.
