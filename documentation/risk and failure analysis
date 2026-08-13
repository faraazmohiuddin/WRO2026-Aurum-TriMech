# Risk and Failure Analysis

This document identifies likely technical failure modes and how the team plans to detect, reduce or recover from them.

| Failure mode | Likely effect | Detection / evidence | Mitigation / response | Status |
|---|---|---|---|---|
| Steering linkage loosens | vehicle drifts or cannot turn accurately | centre changes between tests | lock/inspect joints; recalibrate | Open |
| Excess drivetrain backlash | inconsistent stopping/turning | encoder movement without expected wheel response | improve gear support/alignment | Open |
| N20 stalls under load | vehicle stops; driver heats | encoder pulses stop while motor commanded | review gearing, mass, friction | Open |
| Encoder signal lost | distance/speed estimate fails | motor command active but no pulses | wiring check; timeout/fallback | Open |
| MPU6500 drift | turn-angle error grows | disagreement with distance sensors/known turns | bias calibration; periodic correction | Open |
| Distance-sensor outlier | sudden wrong steering correction | impossible jump / disagreement | filtering, range checks, ignore outlier | Open |
| Side sensors interfere | unstable distance readings | errors appear only when sensors run together | stagger measurements or change technology | Open |
| Raspberry Pi message stops | vision information becomes stale | communication timeout | safe fallback/stop or sensor-only recovery | Open |
| Camera misclassification | wrong obstacle response | low confidence/repeated inconsistent result | threshold/model tuning; combine sensors | Open |
| Raspberry Pi brownout | reboot / vision loss | undervoltage/reboot symptoms | stronger regulated rail; power test | Open |
| Servo current causes voltage dip | steering reset/controller instability | voltage drop during steering | separate/adequate rail, capacitor/regulator test | Open |
| Motor noise affects sensors | false readings/controller instability | errors correlate with motor operation | grounding, decoupling, wiring separation | Open |
| Battery voltage falls | speed/control changes | voltage measurement during run | regulation, battery monitoring, recharge threshold | Open |
| Power bank auto-shuts off | vehicle loses electronics power | shutdown at low/variable load | verify model behaviour before selection | Open |
| Wheel slip | encoder overestimates distance | encoder and IMU/wall data disagree | reduce speed; sensor fusion; tyre/grip changes | Open |
| LEGO structure flexes | geometry changes during run | steering/gear alignment changes under load | brace chassis and mounts | Open |

## Recovery Philosophy

Not every sensor error should immediately produce a steering correction. Where possible, the controller should check whether new information is physically plausible.

Examples:
- reject impossible distance jumps;
- use communication timeouts so old Pi messages are not treated as current;
- detect missing encoder pulses while the motor is commanded;
- compare IMU turn information with distance-sensor geometry;
- enter a safe STOP or RECOVER state when required information is unavailable.

## Test Priority

The highest-priority failures to test early are:
1. power stability with Raspberry Pi + servo + motor system;
2. steering repeatability;
3. drivetrain stall/backlash;
4. distance-sensor reliability;
5. Pi-Arduino communication loss;
6. vision behaviour under changing lighting.

Results should be linked back to `testing-and-results.md`.
