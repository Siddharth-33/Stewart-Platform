# 6x6 IR Grid

## A 6×6 IR sensor grid is mounted on the top plate to detect the real-time position of the ball in the x–y plane. 
<img width="672" height="896" alt="image" src="https://github.com/user-attachments/assets/70c87d75-65ab-438e-ba99-7b8d3bfe11d3" />


## Working

### Signal Conditioning (LM358 Comparator):
Each IR receiver outputs an analog voltage that varies with the amount of IR light received.
The signal is fed into an LM358 comparator in non-inverting mode.
The inverting input is connected to a potentiometer that sets a threshold level.
This ensures clean digital HIGH/LOW outputs, where 1 means the ball blocks the IR beam and 0 means no obstruction.

### Data Collection (Shift Registers):
The digital outputs from the comparators are connected to parallel-in, serial-out shift registers.
This allows the ESP32 to read all 36 sensor states efficiently using just a few GPIO pins.
The sensor matrix is scanned row by row, and the active row/column pair gives the ball’s current coordinate.

### Coordinate Mapping:
Once the triggered sensor location is detected, the ball’s (x, y) position is mapped to a 2D grid coordinate system.
This coordinate is compared with the target center (0,0) and used in the PID control loop to compute corrections.
