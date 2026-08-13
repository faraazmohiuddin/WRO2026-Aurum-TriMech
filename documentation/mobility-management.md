[mobility-management.md](https://github.com/user-attachments/files/31034106/mobility-management.md)
# Mobility Management

## Current Mechanical Direction

Aurum TriMech is developing a LEGO Technic-based four-wheel vehicle with:

- one N20 6V 200 RPM geared DC motor with encoder;
- a mechanically coupled driving axle;
- a mechanical differential gearbox;
- Ackermann-style front steering;
- servo steering actuation.

A second identical N20 motor has been ordered as a **backup**, not as an independently driven second-wheel motor.

## LEGO Technic Chassis

LEGO Technic was selected because the mechanical system is still being optimized. It allows rapid changes to:

- wheelbase;
- track width;
- axle position;
- steering linkage;
- gearing;
- motor mounting;
- sensor placement;
- electronics placement.

Custom or 3D-printed interfaces may be used where required to connect non-LEGO components such as the N20 motor to the Technic drivetrain.

### Mechanical measurements to record

| Measurement | Final value |
|---|---:|
| Wheelbase | TBD |
| Front track width | TBD |
| Rear track width | TBD |
| Wheel diameter | TBD |
| Vehicle mass | TBD |
| Ground clearance | TBD |
| Minimum turning radius | TBD |

These measurements will be added once the rolling chassis is assembled.

---

## Drive Motor Selection

Current motor:

**N20 6V 200 RPM micro metal gear motor with encoder**

Earlier options included BO motors, an N20 100 RPM option and a JGB37-520 12V 111 RPM encoder motor.

The current N20 direction prioritizes compact packaging and encoder feedback. The final decision must still be validated under the actual vehicle load.

### Tests required
- loaded RPM;
- acceleration;
- motor temperature;
- stall tendency;
- straight-line controllability;
- encoder repeatability.

---

## Speed Reasoning

The motor's nominal output RPM is not equal to the final wheel RPM if additional gearing is used.

```text
Wheel RPM = Motor RPM / Overall Gear Reduction

Wheel Circumference = pi × Wheel Diameter

Vehicle Speed = Wheel RPM × Wheel Circumference / 60
```

### Calculation table

| Parameter | Value |
|---|---:|
| Nominal motor RPM | 200 RPM |
| Motor-to-differential ratio | TBD |
| Differential/output ratio | TBD |
| Overall ratio | TBD |
| Wheel diameter | TBD |
| Calculated wheel RPM | TBD |
| Calculated theoretical speed | TBD |
| Measured speed | TBD |

The difference between theoretical and measured speed will indicate the effect of load, friction, voltage and slip.

---

## Torque Reasoning

There is a trade-off between wheel speed and wheel torque.

Increasing gear reduction:
- reduces wheel RPM;
- increases available wheel torque;
- may improve low-speed control and acceleration.

Reducing gear reduction:
- increases theoretical speed;
- reduces torque multiplication;
- may make the vehicle harder to control around corners.

The final gear ratio will therefore be selected from test evidence rather than maximum speed alone.

---

## Encoder Feedback

The encoder is intended to support:
- rotation counting;
- speed measurement;
- distance estimation;
- repeatable movement;
- detection of drivetrain problems;
- possible closed-loop speed control.

Once the drivetrain is complete:

```text
Distance per Count =
Wheel Circumference / Effective Counts per Wheel Revolution
```

The result must be checked by physically measuring travel over multiple trials.

---

## Mechanical Differential

The single N20 drive motor transfers torque to both wheels of the driving axle through a mechanical differential gearbox.

The differential allows the inner and outer driven wheels to rotate at different speeds during a corner while remaining connected to the same propulsion system.

### Differential tests
- rotate each wheel manually and observe differential action;
- check binding;
- measure backlash;
- run motor with wheels unloaded;
- test under vehicle load;
- observe cornering at different speeds.

---

## Ackermann Steering

The front wheels use Ackermann-style steering. During a turn, the inner front wheel should steer through a greater angle than the outer front wheel.

The design will be evaluated using actual wheel angles and turning radius rather than servo command values alone.

### Steering calibration
1. establish mechanical centre;
2. determine safe left/right servo limits;
3. measure inner and outer wheel angles;
4. check linkage binding;
5. measure turning radius;
6. repeat steering cycles and check return-to-centre error.

Detailed procedure: [Calibration](calibration.md).

---

## Mechanical Iteration Record

| Version | Change | Reason | Measured effect |
|---|---|---|---|
| Early test | BO motors / basic driver tests | Learn motor control | Qualitative bench test |
| Motor exploration | JGB37/N20 options | Compare packaging and feedback | TBD |
| Current | N20 200 RPM + differential + Ackermann | Compact car-like drivetrain | Testing pending |

Measured results will be recorded in [Testing & Results](testing-and-results.md).
