# Troubleshooting Log

## ESP32 / ESP32-CAM upload
Observed errors included:
- Failed to connect to ESP32: No serial data received.
- Download mode detected but no sync reply.
- Serial TX path suspected.
- COM port busy.
- Link/compile errors involving missing camera-server functions in incomplete sketches.

Checks learned:
1. correct board selected;
2. correct COM port;
3. GPIO0 to GND during ESP32-CAM flashing;
4. reset/boot timing;
5. stable 5 V power;
6. common ground;
7. TX/RX crossed;
8. correct USB/serial driver;
9. data-capable USB cable.

## USB cable
A cable that charges successfully may be power-only or have damaged data lines. This became a key diagnostic after boards powered normally but would not upload.

## Motor system
At one stage one motor ran while the second did not. We isolated driver channels, wiring, power and pin assignments instead of assuming a software-only problem.

## ESP32 PWM
ESP32 Arduino core/library API differences affected LEDC examples. Code must match the installed ESP32 core version.

## Design response
Repeated integration problems motivated a simpler Arduino Uno core architecture for the next build.
