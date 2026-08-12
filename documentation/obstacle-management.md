# Obstacle Management

The Obstacle Challenge requires perception plus controlled path planning.

## Experimental concept
Camera detects a traffic-sign colour and sends a compact command to the main controller.

Example experimental protocol:
- `R` = red detected
- `G` = green detected

A serial test successfully alternated these characters at 9600 baud, proving basic controller-to-controller communication.

Earlier demonstrations mapped these letters directly to simple motor actions. Those mappings were only bench tests and are not the final obstacle strategy.

## Final strategy still to validate
The competition algorithm should combine:
- traffic-sign colour;
- sign position in the camera image;
- vehicle heading;
- wall/track distance;
- steering geometry;
- safe clearance.

## Development rule
First achieve reliable Open Challenge mobility. Then add obstacle perception without destabilising the base vehicle.
