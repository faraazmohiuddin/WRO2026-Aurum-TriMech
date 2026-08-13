# Testing and Results

This file is the team's quantitative test record. **TBD means the test has not yet been completed or the result has not yet been recorded.** Values should only be replaced when measured.

## Test Method

For every important test, record:

1. date;
2. hardware/software version;
3. test setup;
4. expected result;
5. measured result;
6. failure or deviation;
7. change made;
8. retest result;
9. engineering decision.

---

## Master Test Matrix

| ID | Test | Metric | Target / question | Result | Status |
|---|---|---|---|---|---|
| M01 | N20 no-load encoder test | RPM, counts/rev | Establish encoder baseline | TBD | Pending |
| M02 | Loaded drivetrain speed | cm/s | Is 200 RPM gearing controllable? | TBD | Pending |
| M03 | Straight-line run | lateral error over fixed distance | Repeatability | TBD | Pending |
| M04 | Turning radius | cm | Can chassis negotiate required corners? | TBD | Pending |
| M05 | Steering repeatability | angle/error | Repeat same steering command | TBD | Pending |
| M06 | Differential test | wheel freedom/backlash | Smooth cornering | TBD | Pending |
| S01 | MPU6500 stationary test | gyro bias | Determine offset | TBD | Pending |
| S02 | MPU6500 90° turn | angle error | Repeatable turn measurement | TBD | Pending |
| S03 | Left distance sensor | error vs known distance | Sensor suitability | TBD | Pending |
| S04 | Front distance sensor | error vs known distance | Sensor suitability | TBD | Pending |
| S05 | Right distance sensor | error vs known distance | Sensor suitability | TBD | Pending |
| P01 | 5V rail load test | V, A, temperature | Stable electronics supply | TBD | Pending |
| P02 | Battery runtime | minutes | Compare power options | TBD | Pending |
| P03 | Power-bank runtime | minutes | Compare power options | TBD | Pending |
| V01 | Vision detection | success % | Detection reliability | TBD | Pending |
| V02 | Vision latency | ms | Is response fast enough? | TBD | Pending |
| C01 | Pi-Arduino communication | lost/invalid messages | Communication reliability | TBD | Pending |
| R01 | Full Open Challenge run | laps/time/errors | Integrated performance | TBD | Pending |
| R02 | Full Obstacle Challenge run | completion/errors | Integrated performance | TBD | Pending |

---

## Mobility Test Template

### M01 – Encoder Baseline

**Date:** TBD  
**Motor:** N20 6V 200 RPM with encoder  
**Supply voltage:** TBD  
**Driver:** DRV8833  

**Procedure**
1. Run motor for a measured interval.
2. Count encoder pulses.
3. Repeat at least five times.
4. Calculate mean and variation.

| Trial | Time (s) | Encoder counts | Calculated RPM |
|---:|---:|---:|---:|
| 1 | TBD | TBD | TBD |
| 2 | TBD | TBD | TBD |
| 3 | TBD | TBD | TBD |
| 4 | TBD | TBD | TBD |
| 5 | TBD | TBD | TBD |

**Decision:** TBD

---

### M03 – Straight-Line Repeatability

**Test distance:** TBD  
**Commanded speed:** TBD  

| Trial | Travel distance | Left/right final error | Heading error | Notes |
|---:|---:|---:|---:|---|
| 1 | TBD | TBD | TBD | |
| 2 | TBD | TBD | TBD | |
| 3 | TBD | TBD | TBD | |
| 4 | TBD | TBD | TBD | |
| 5 | TBD | TBD | TBD | |

Possible changes after testing:
- steering centre;
- mechanical alignment;
- encoder correction;
- speed;
- sensor-based wall correction.

---

## Sensor Calibration Test

For each distance-sensor candidate:

| Actual distance (cm) | Reading 1 | Reading 2 | Reading 3 | Mean | Error |
|---:|---:|---:|---:|---:|---:|
| 10 | TBD | TBD | TBD | TBD | TBD |
| 20 | TBD | TBD | TBD | TBD | TBD |
| 30 | TBD | TBD | TBD | TBD | TBD |
| 50 | TBD | TBD | TBD | TBD | TBD |
| 75 | TBD | TBD | TBD | TBD | TBD |

Repeat under representative field conditions before selecting the final sensor.

---

## Power Comparison

| Measurement | ~11V battery | Power bank |
|---|---:|---:|
| Total mass | TBD | TBD |
| Idle voltage | TBD | TBD |
| Voltage under load | TBD | TBD |
| Peak current available | TBD | TBD |
| Raspberry Pi stable? | TBD | TBD |
| Servo stable? | TBD | TBD |
| Runtime | TBD | TBD |
| Regulator temperature | TBD | TBD |
| Final assessment | TBD | TBD |

---

## Vision Test

Record the exact camera, resolution, lighting and software version.

| Test condition | Attempts | Correct detections | Success rate | Mean latency |
|---|---:|---:|---:|---:|
| Red traffic sign | TBD | TBD | TBD | TBD |
| Green traffic sign | TBD | TBD | TBD | TBD |
| Near obstacle | TBD | TBD | TBD | TBD |
| Far obstacle | TBD | TBD | TBD | TBD |
| Different lighting | TBD | TBD | TBD | TBD |

---

## Integrated Run Log

| Date | Version | Challenge | Result | Main failure | Change for next run |
|---|---|---|---|---|---|
| TBD | TBD | Open | TBD | TBD | TBD |
| TBD | TBD | Obstacle | TBD | TBD | TBD |

The purpose of this file is to turn observations such as “it worked better” into measurable engineering evidence.
