[power-and-sense-management.md](https://github.com/user-attachments/files/31034143/power-and-sense-management.md)
# Power and Sense Management

## Power Architecture

Two power-source approaches are currently being evaluated:

1. approximately **11V rechargeable battery**;
2. **high-quality power bank**.

The final decision will be based on measured/verified current capability, voltage stability, runtime, mass and compatibility with the Raspberry Pi, servo, controller and motor system.

The selected N20 drive motor is rated for 6V. If an approximately 11V source is used, the full battery voltage must not simply be applied continuously to the motor. The motor supply/control strategy must be tested appropriately.

---

## Available Regulation Hardware

### MP1584 adjustable 3A buck converter
Two modules have been ordered for regulated-power experiments.

### TPS565201 5V 5A step-down converter
This module is available for testing where a stronger regulated 5V rail is required.

Final rail allocation will follow load and thermal testing.

---

## Proposed Power Layout

```text
          BATTERY / POWER SOURCE
                   |
          +--------+--------+
          |                 |
          v                 v
     MOTOR POWER       REGULATED POWER
          |                 |
       DRV8833        BUCK CONVERTER(S)
          |                 |
       N20 MOTOR       +-----+-----+------+
                       |           |      |
                    Arduino      Servo   Sensors
                       |
                       +------ Raspberry Pi
                              (final rail TBD)
```

The actual architecture may use separate regulated rails if testing shows that servo/motor load causes unacceptable voltage drops or noise.

---

## Power Budget

Values marked TBD must be filled from final datasheets and preferably verified on the assembled vehicle.

| Load | Voltage | Typical current | Peak current | Supply/rail |
|---|---:|---:|---:|---|
| Raspberry Pi | TBD | TBD | TBD | TBD |
| Camera | TBD | TBD | TBD | Pi / TBD |
| Arduino Uno/Mega | 5V logic | TBD | TBD | regulated rail |
| Steering servo | TBD | TBD | TBD | TBD |
| N20 motor | 6V rated | TBD | TBD | DRV8833 |
| MPU6500 | TBD | TBD | TBD | controller rail |
| Left distance sensor | TBD | TBD | TBD | controller rail |
| Front distance sensor | TBD | TBD | TBD | controller rail |
| Right distance sensor | TBD | TBD | TBD | controller rail |

### Calculations to add

```text
Typical System Current = sum of typical loads

Worst-Case Current ≈ sum of simultaneous peak loads
```

For a battery with known usable capacity:

```text
Approximate Runtime (hours) =
Usable Capacity (Ah) / Average Current (A)
```

Real runtime will be measured because motor and servo loads vary significantly.

---

## Distance-Sensor Selection

Three distance sensors are planned: left, front and right.

The exact sensor type remains open.

### Candidate comparison

| Factor | Ultrasonic | Infrared | Time-of-Flight |
|---|---|---|---|
| Range | To test | To test | To test |
| Accuracy/repeatability | To test | To test | To test |
| Field of view | To test | To test | To test |
| Update rate | To test | To test | To test |
| Multiple-sensor interference | Possible; test required | Test required | Test required |
| Pin/interface demand | Depends on model | Depends on model | Often digital/I2C; model dependent |
| Physical size | Model dependent | Model dependent | Model dependent |
| Field-surface behaviour | Must test | Must test | Must test |

The final selection will be based on actual candidate modules, not the generic technology alone.

---

## Sensor Placement

```text
                 FRONT
                   ^
                   |
             [Front Sensor]

 [Left Sensor]             [Right Sensor]
       <                         >
```

### Intended roles

**Left**
- left-side clearance;
- lateral-position information;
- support wall/boundary alignment.

**Front**
- forward clearance;
- approach detection;
- additional geometric information during navigation.

**Right**
- right-side clearance;
- lateral-position information;
- support wall/boundary alignment.

Once the chassis is built, record:
- sensor height;
- distance from vehicle centreline;
- angle relative to chassis;
- distance from front/rear axle.

This allows another team to reproduce the placement.

---

## MPU6500

The selected IMU is the MPU6500 6-axis gyro/accelerometer.

Intended uses:
- measure rotation;
- estimate heading change;
- support cornering;
- detect unexpected vehicle movement.

Calibration must include stationary bias and repeated known-angle turns.

---

## N20 Encoder

The drive motor encoder can provide:
- rotation count;
- speed;
- approximate travel distance;
- feedback for repeatability;
- detection of a motor command with no corresponding movement.

Encoder calibration is documented in [Calibration](calibration.md).

---

## Sensor Fusion Direction

The controller can eventually compare several sources:

| Source | Main information |
|---|---|
| Encoder | drivetrain movement |
| MPU6500 | vehicle rotation/orientation |
| Left/right distance | lateral geometry |
| Front distance | forward geometry |
| Raspberry Pi | visual perception |

Using multiple sources also makes it possible to detect disagreement, such as wheel slip or an implausible distance-sensor reading.

---

## Failure-Point Considerations

Important power/sensing failures include:
- servo-induced voltage dip;
- Raspberry Pi undervoltage;
- motor electrical noise;
- loose common ground;
- sensor outliers;
- distance-sensor interference;
- IMU drift;
- encoder signal loss.

See [Risk & Failure Analysis](risk-and-failure-analysis.md) and [Testing & Results](testing-and-results.md).
