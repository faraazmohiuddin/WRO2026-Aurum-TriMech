# Mobility Management

## Current direction
The vehicle is intended to use one geared DC drive motor and servo-based front steering.

### Drive motor
Current candidate: JGB37-520, 12 V, 111 RPM, with encoder.

Earlier options:
- N20 6 V 100 RPM geared motor;
- N20 12 V 600 RPM;
- two BO motors for test rigs.

### Transmission
We explored a one-motor/two-wheel mechanism using a shared axle, gears, gearbox or differential. A custom 3D-printable mechanism was also considered. Final geometry must be documented once the chassis is fixed.

### Steering
Initial tests used SG90. Higher torque DS3218/DS3225 options were considered. Test positions included 90° centre and wide left/right ranges, but the final safe angles must be measured on the real linkage.

### Control objective
The mobility controller must produce:
1. repeatable straight motion;
2. controlled cornering while moving;
3. predictable stop distance;
4. minimal steering oscillation;
5. sufficient traction without excessive speed.

### Planned feedback
The JGB37 encoder and MPU6050 can provide feedback for more repeatable movement. These features must be calibrated and validated before being treated as competition-ready.
