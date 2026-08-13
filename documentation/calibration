# Calibration Procedures

Calibration converts raw sensor and actuator behaviour into values that can be used consistently by the navigation software.

## 1. Steering Calibration

Record:

| Parameter | Value |
|---|---:|
| Servo model | TBD |
| Mechanical centre command | TBD |
| Safe left command | TBD |
| Safe right command | TBD |
| Inner wheel angle at full left | TBD |
| Outer wheel angle at full left | TBD |
| Inner wheel angle at full right | TBD |
| Outer wheel angle at full right | TBD |
| Minimum measured turning radius | TBD |

### Procedure
1. Mechanically centre the steering linkage before attaching the servo horn.
2. Set a software centre.
3. Increase left/right commands gradually.
4. Stop before linkage binding or tyre/chassis interference.
5. Measure actual wheel angles.
6. Run repeated left-centre-right-centre cycles.
7. Adjust centre/limits if the wheels do not return consistently.

---

## 2. Encoder Calibration

Required measurements:
- encoder pulses/counts per motor revolution;
- total drivetrain gear ratio;
- wheel diameter;
- effective counts per wheel revolution.

```text
Wheel Circumference = pi × Wheel Diameter

Distance per Count =
Wheel Circumference / Counts per Wheel Revolution
```

Validate by commanding a known encoder count and measuring actual travel distance.

| Trial | Commanded counts | Predicted distance | Actual distance | Error |
|---:|---:|---:|---:|---:|
| 1 | TBD | TBD | TBD | TBD |
| 2 | TBD | TBD | TBD | TBD |
| 3 | TBD | TBD | TBD | TBD |

---

## 3. MPU6500 Calibration

### Stationary bias
1. Keep vehicle stationary on a level surface.
2. Collect gyro samples for a fixed period.
3. Calculate average zero-rate offset.
4. Subtract offset from subsequent readings.

### Turn calibration
Perform repeated measured turns.

| Trial | Physical turn | MPU estimate | Error |
|---:|---:|---:|---:|
| 1 | 90° | TBD | TBD |
| 2 | 90° | TBD | TBD |
| 3 | 90° | TBD | TBD |
| 4 | 90° | TBD | TBD |
| 5 | 90° | TBD | TBD |

Document drift and decide whether the IMU should be corrected using other sensors.

---

## 4. Distance-Sensor Calibration

Calibrate each sensor separately in its final mounting position.

Suggested distances:
- 10 cm;
- 20 cm;
- 30 cm;
- 50 cm;
- 75 cm.

Record multiple readings at each distance and calculate mean error and variation.

Also test:
- angled surfaces;
- different field colours/materials;
- nearby second sensor operating;
- moving vehicle.

---

## 5. Vision Calibration

Once the Raspberry Pi camera is selected, record:
- camera model;
- resolution;
- frame rate;
- exposure settings;
- white balance;
- colour space;
- crop/region of interest;
- detection thresholds/model version.

Test using representative red/green signs and field lighting.

Do not describe thresholds as final until they have been tested under more than one lighting condition.

---

## 6. Motor Speed Calibration

Measure actual speed at several motor commands rather than assuming PWM is proportional to vehicle speed.

| Motor command | Measured RPM | Vehicle speed | Notes |
|---:|---:|---:|---|
| TBD | TBD | TBD | |
| TBD | TBD | TBD | |
| TBD | TBD | TBD | |
| TBD | TBD | TBD | |

This table can later be used to choose a controllable straight-line and cornering speed.

---

## Calibration Versioning

Whenever a mechanical change affects steering, wheel diameter, gearing, sensor mounting or camera position, the relevant calibration should be repeated and the change recorded in the engineering journal.
