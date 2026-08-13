[obstacle-management.md](https://github.com/user-attachments/files/31034125/obstacle-management.md)
# Obstacle Management

## Strategy Overview

The current obstacle-management architecture uses a Raspberry Pi for vision and an Arduino Uno/Mega for vehicle control.

```text
Camera
  |
  v
Raspberry Pi
Vision / Perception
  |
  v
Perception Message
  |
  v
Arduino Uno / Mega
Navigation State Machine
  |
  +--> Steering Servo
  |
  +--> DRV8833 --> N20 Motor
```

The Raspberry Pi does not need to directly control the motor. Its job is to convert camera images into useful information that the Arduino can combine with distance, encoder and IMU data.

---

## Information Available to the Vehicle

### Vision
Potentially provides:
- traffic-sign/obstacle type;
- relevant colour;
- approximate image position;
- confidence.

### Left / Right Distance Sensors
Potentially provide:
- lateral clearance;
- path alignment;
- recovery information after manoeuvres.

### Front Distance Sensor
Potentially provides:
- forward clearance;
- approach information;
- sanity check for visual information.

### MPU6500
Potentially provides:
- turn progress;
- heading change;
- unexpected rotation.

### Encoder
Potentially provides:
- travelled distance;
- speed;
- progress through a manoeuvre.

---

## Proposed Obstacle Flow

```text
NORMAL DRIVING
      |
      v
VISION RESULT AVAILABLE?
   /        \
 NO          YES
 |            |
 |       VALID / CONFIDENT?
 |          /       \
 |        NO         YES
 |        |           |
 +--------+      CLASSIFY / LOCATE
                     |
                     v
               SELECT RESPONSE
                     |
                     v
               REDUCE SPEED
                     |
                     v
               STEER / PASS
                     |
                     v
                  RECOVER
                     |
                     v
               NORMAL DRIVING
```

The exact passing strategy will be documented after the camera and field tests are performed.

---

## Why Use Multiple Sensors?

A camera result alone can be affected by:
- lighting;
- blur;
- partial visibility;
- false colour classification;
- processing delay.

Distance sensors cannot identify traffic-sign colour, but they can provide direct geometric information.

The IMU and encoder provide movement information.

The intended strategy therefore uses the Raspberry Pi as the primary visual perception system while allowing the Arduino to check the manoeuvre against other sensor information.

---

## Edge Cases

The obstacle strategy should be tested for:
- traffic sign close to a corner;
- partial sign visibility;
- changing lighting;
- temporary false detection;
- no detection;
- Pi communication timeout;
- distance sensor disagreement;
- vehicle too close to a boundary;
- recovery after an over-steer or under-steer.

---

## Validation Metrics

| Metric | Result |
|---|---:|
| Red-sign detection success rate | TBD |
| Green-sign detection success rate | TBD |
| Mean vision latency | TBD |
| Successful obstacle passes / attempts | TBD |
| Boundary contacts | TBD |
| Recovery success rate | TBD |
| Complete Obstacle Challenge runs | TBD |

Results will be stored in [Testing & Results](testing-and-results.md).

---

## Earlier ESP32-CAM Experiments

The team previously explored AI Thinker ESP32-CAM and simple serial communication. An experimental `R`/`G` approach demonstrated controller-to-controller messaging.

These experiments are retained because they influenced the move toward a clearer two-processor architecture, but they are not presented as the final obstacle-management system.
