[hardware-inventory.md](https://github.com/user-attachments/files/31033541/hardware-inventory.md)
# Hardware Inventory

## Current / Ordered
| Component | Status / role |
|---|---|
| Arduino Uno | Available; candidate main controller |
| Arduino Mega | Candidate main controller; final choice pending |
| Raspberry Pi | Intended vision processor; exact model pending |
| N20 6V 200 RPM encoder motor ×2 | Ordered; **one drive motor, one backup** |
| DRV8833 ×2 | Ordered; intended motor driver plus spare/testing unit |
| MPU6500 ×2 | Ordered; intended IMU plus spare/testing unit |
| MP1584 adjustable 3A buck ×2 | Ordered for power tests |
| TPS565201 5V 5A step-down module | For higher-current regulated 5V testing |
| LEGO Technic | Intended chassis/drivetrain/steering system |
| Steering servo | Final choice/calibration pending |
| Distance sensors ×3 | Left/front/right; exact model pending |

## Intended Mechanical System
- LEGO Technic chassis
- Ackermann front steering
- servo steering
- one N20 drive motor
- mechanical differential gearbox on the driving axle

## Power Under Evaluation
- approximately 11V rechargeable battery, or
- high-quality power bank.

## Earlier / Experimental Hardware
| Component | History |
|---|---|
| ESP32 DevKit V1 | Controller experiments |
| ESP32-CAM | Vision/communication experiments |
| L298N | Early motor driver |
| TB6612FNG | Considered before DRV8833 |
| JGB37-520 encoder motor | Earlier drive candidate |
| BO motors | Bench tests |
| SG90 | Steering tests |
| MPU6050 | Earlier IMU experiments |
| HC-SR04 | Distance-sensor experiments |
