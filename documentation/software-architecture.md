[software-architecture.md](https://github.com/user-attachments/files/31034156/software-architecture.md)
# Software Architecture

## Two-Processor Direction

The current architecture separates perception from real-time vehicle control.

### Raspberry Pi – Vision / Perception
Intended responsibilities:
- camera acquisition;
- image processing;
- traffic-sign/obstacle perception;
- producing compact perception information;
- communicating results to the Arduino.

### Arduino Uno or Mega – Vehicle Control
Intended responsibilities:
- DRV8833 motor control;
- steering-servo control;
- N20 encoder input;
- MPU6500 input;
- three distance sensors;
- Raspberry Pi communication;
- state machine;
- real-time movement decisions.

---

## Uno vs Mega Decision

The Uno is familiar and compact.

The Mega offers:
- more I/O;
- more hardware serial resources;
- more flexibility for debugging and integration.

The final selection will be based on a pin/resource table covering:
- encoder interrupt input;
- servo;
- DRV8833 control;
- I2C IMU;
- three distance sensors;
- Pi serial communication;
- debugging serial.

The decision will be recorded in `engineering-decisions.md`.

---

## Proposed Software Layers

### Raspberry Pi

```text
Camera Driver
     |
     v
Image Pre-processing
     |
     v
Traffic Sign / Obstacle Perception
     |
     v
Confidence / Validation
     |
     v
Compact Perception Message
     |
     v
Communication to Arduino
```

### Arduino

```text
Hardware Drivers
     |
     v
Sensor Acquisition
     |
     v
Calibration / Filtering
     |
     v
Vehicle State Estimation
     |
     v
Navigation State Machine
     |
     v
Motor + Steering Commands
```

---

## Proposed State Machine

```text
START
  |
  v
INITIALIZE
  |
  v
DRIVE_STRAIGHT <----------------------+
  |                                   |
  | corner condition                  |
  v                                   |
APPROACH_CORNER                        |
  |                                   |
  v                                   |
TURN                                  |
  |                                   |
  v                                   |
ALIGN --------------------------------+

Traffic sign / obstacle
  |
  v
OBSTACLE_RESPONSE
  |
  v
RECOVER
  |
  +--------------------> DRIVE_STRAIGHT

Finish or unrecoverable fault
  |
  v
STOP
```

The exact transitions are not yet frozen.

---

## Transition Rationale

### DRIVE_STRAIGHT
Possible inputs:
- left/right distance error;
- encoder speed/distance;
- IMU heading change.

Possible control:
- steering correction to maintain desired path;
- regulated drive speed.

### APPROACH_CORNER
Triggered when the sensor/field strategy indicates a corner is approaching.

Possible actions:
- reduce speed;
- prepare steering target;
- capture starting IMU/encoder reference.

### TURN
Possible inputs:
- IMU rotation;
- encoder movement;
- side/front distance.

The final turn algorithm may use one or more of these depending on measured reliability.

### ALIGN
After a turn, side sensors can help re-establish a stable straight path.

### OBSTACLE_RESPONSE
Raspberry Pi perception identifies relevant traffic-sign/obstacle information. Arduino executes the corresponding vehicle manoeuvre.

### RECOVER
Used when the vehicle needs to return to normal lane/path control after an obstacle manoeuvre or correct a recoverable error.

### STOP
Used at finish or for a condition where continuing is unsafe/unreliable.

---

## Edge Cases to Handle

The software should explicitly test:
- stale Raspberry Pi messages;
- no Pi communication;
- impossible distance jump;
- one side sensor temporarily invalid;
- encoder pulses missing while motor is commanded;
- IMU drift;
- obstacle detected near a corner;
- conflicting sensor and vision information;
- vehicle not completing expected turn;
- finish/stop condition.

The response to each edge case will be updated after integrated testing.

---

## Communication Protocol – Proposed

The final protocol is not selected yet.

A compact message should include only information needed by the Arduino, for example:
- object/sign type;
- position or side;
- confidence;
- timestamp/sequence number.

A sequence number or timeout can prevent an old vision result from being treated as current.

Earlier ESP32-CAM experiments used simple `R` and `G` messages. Those experiments demonstrated the basic concept but are not presented as the final protocol.

---

## Algorithm Tuning

Thresholds must come from testing.

Examples:
- desired wall distance;
- maximum valid distance jump;
- corner-detection threshold;
- target turn angle;
- steering gain;
- motor speed for straight sections;
- motor speed for turns;
- Pi detection confidence threshold.

Each important threshold should be linked to a test result where possible.

See [Testing & Results](testing-and-results.md) and [Calibration](calibration.md).

---

## Performance Metrics

The software will eventually be evaluated using:
- straight-line lateral error;
- heading error;
- turn-angle error;
- turning repeatability;
- obstacle/traffic-sign detection success rate;
- perception latency;
- communication reliability;
- complete-run success rate;
- lap/run time.

This makes tuning evidence-based rather than subjective.
