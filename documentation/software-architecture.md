# Software Architecture

## Current Arduino Uno architecture

Inputs:
- MPU6050 over I2C
- distance sensor
- JGB37 encoder (planned integration)
- optional external vision command later

Outputs:
- TB6612FNG motor-control pins
- steering-servo PWM

Recommended software layers:
1. hardware drivers;
2. calibrated sensor readings;
3. motion primitives;
4. vehicle state machine;
5. Open/Obstacle challenge logic.

## Historical ESP32 architecture
An ESP32 DevKit V1 was tested with L298N and servo control. One pin map used ENA=26, IN1=27, IN2=14, ENB=33, IN3=32, IN4=13. GPIO25 was used in a servo experiment.

An ESP32-CAM concept sent `R`/`G` commands to an ESP32 over UART/Serial2.

These files are retained as engineering history and should not be mistaken for the final Uno program.
