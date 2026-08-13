# Engineering Decisions

This document records the major design decisions for Aurum TriMech. A decision is marked **provisional** until testing provides enough evidence to freeze it.

## Decision Summary

| Area | Options considered | Current direction | Status |
|---|---|---|---|
| Chassis | custom fabricated chassis, LEGO Technic | LEGO Technic | Selected |
| Steering | differential/skid concepts, automotive steering | Ackermann-style steering | Selected |
| Drive motor | BO, N20 variants, JGB37-520 | N20 6V 200 RPM encoder motor | Selected |
| Number of drive motors | two independent motors, single motor | one drive motor + mechanical differential | Selected |
| Motor driver | L298N, TB6612FNG, DRV8833 | DRV8833 | Selected |
| IMU | MPU6050, MPU6500 | MPU6500 | Selected |
| Main controller | Arduino Uno, Mega, ESP32 | Uno or Mega | Provisional |
| Vision processor | ESP32-CAM, Raspberry Pi | Raspberry Pi | Provisional |
| Distance sensing | ultrasonic, IR, ToF | 3 sensors; technology TBD | Open |
| Power source | ~11V battery, quality power bank | test both | Open |

---

## D01 – LEGO Technic Chassis

**Decision:** Use LEGO Technic as the primary chassis construction system.

### Why
The chassis is still changing. LEGO Technic allows fast changes to wheelbase, track width, gearing, steering linkage and sensor placement without rebuilding the complete vehicle.

### Trade-off
A fabricated chassis could be more rigid and compact, but would make frequent mechanical changes slower.

### Validation required
- check chassis rigidity under steering load;
- check drivetrain alignment;
- check that component mounting does not flex;
- measure final dimensions and mass.

---

## D02 – Ackermann-Style Steering

**Decision:** Use front-wheel Ackermann-style steering with a servo.

### Why
The intended vehicle architecture is car-like: propulsion is separated from steering. Ackermann geometry should reduce tyre scrub compared with forcing both front wheels to the same steering angle.

### Trade-off
Ackermann linkages require careful geometry and introduce mechanical play. A simpler parallel steering linkage would be easier to build but may be less mechanically correct during tight turns.

### Validation required
- measure inner and outer wheel angles;
- measure turning radius;
- check servo load;
- test repeatability after multiple turns.

---

## D03 – One N20 Drive Motor

**Decision:** Use one N20 6V 200 RPM encoder motor for propulsion. Keep the second identical motor as a backup.

### Why
A single motor keeps the propulsion system mechanically simple and allows both driven wheels to be coupled through a mechanical differential.

### Why the encoder matters
It provides measurable drivetrain feedback for speed, distance and repeatability.

### Earlier alternatives
BO motors and JGB37-520 were explored before the N20 direction.

### Validation required
- loaded speed;
- starting torque on the complete vehicle;
- motor temperature;
- encoder repeatability;
- ability to complete turns without stalling.

---

## D04 – Mechanical Differential

**Decision:** Transfer motor power to the two driven wheels through a mechanical differential gearbox.

### Why
The two driven wheels travel different distances in a turn. The differential permits different wheel speeds while retaining a single mechanical drivetrain.

### Trade-off
A differential adds gears, backlash and mechanical complexity.

### Validation required
- free rotation;
- backlash;
- torque transfer;
- cornering behaviour;
- LEGO axle/adapter reliability.

---

## D05 – DRV8833 Motor Driver

**Decision:** Use DRV8833 as the current motor-driver choice.

### Earlier alternatives
- L298N was used in early testing.
- TB6612FNG was considered.
- DRV8833 was selected for the compact N20 drivetrain.

### Why
The current direction prioritizes a smaller, more appropriate driver for the compact motor system.

### Evidence still required
The selection must be validated with the real N20 under vehicle load. Record current, temperature and voltage behaviour before calling the driver final.

---

## D06 – MPU6500

**Decision:** Use MPU6500 as the current IMU.

### Earlier work
MPU6050 was used in earlier IMU experiments.

### Intended role
- measure turn/rotation behaviour;
- detect orientation changes;
- support repeatable cornering;
- complement encoder and distance-sensor information.

### Validation required
- stationary gyro bias;
- drift over time;
- measured 90-degree turn error;
- repeatability after multiple turns.

---

## D07 – Arduino Uno vs Mega

**Decision:** Not yet frozen.

### Uno advantages
- already familiar to the team;
- compact;
- sufficient for simple control tasks.

### Mega advantages
- more I/O;
- more hardware serial resources;
- easier integration if three distance sensors, encoder, IMU, servo and Raspberry Pi communication require many pins.

### Decision test
Create a final pin/interrupt/serial allocation table. Select the Uno only if it can support the required interfaces cleanly without making debugging unnecessarily difficult.

---

## D08 – Raspberry Pi for Vision

**Current direction:** Raspberry Pi + camera for vision.

### Earlier work
ESP32-CAM was explored for colour detection and serial communication.

### Why change direction
The current architecture separates computationally heavier image processing from low-level motor and sensor control.

### Trade-off
Raspberry Pi adds power demand, boot time, size and software complexity.

### Validation required
- camera frame rate;
- detection accuracy;
- processing latency;
- communication latency;
- power stability.

---

## D09 – Three Distance Sensors

**Decision:** Use left, front and right distance measurements. Exact technology remains open.

### Candidate technologies
- ultrasonic;
- infrared;
- time-of-flight.

### Selection criteria
- usable range;
- repeatability;
- field of view;
- update rate;
- physical size;
- pin/interface requirements;
- interference;
- behaviour on actual field surfaces.

The final decision should be supported by a comparison test rather than preference alone.

---

## D10 – Power Source

**Decision:** Compare an approximately 11V rechargeable battery with a high-quality power bank.

### Battery questions
- capacity;
- peak current;
- regulator requirements;
- mass;
- motor compatibility.

### Power-bank questions
- Raspberry Pi stability;
- current limit;
- auto-shutoff behaviour;
- motor/servo suitability;
- mass and runtime.

### Decision evidence
Record voltage under load, peak current capability, runtime and total system mass before freezing the choice.
