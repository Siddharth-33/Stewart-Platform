# 3-DOF Stewart Platform

##  Demo / Visualization

https://github.com/user-attachments/assets/998ffcb7-0a2c-45e5-982b-bb6aab626a49

##  Overview
** Aims to design and implement a functional 3-DOF Stewart Platform, a parallel manipulator capable of motion in pitch, roll, and vertical heave. The platform will be used for real-time ball-balancing control, where a ball placed on the top surface is continuously stabilized at the center using a 6x6 grid of IR Sensors connected to serial registers for each row.

A 6×6 IR sensor grid is mounted on the top plate to detect the real-time position of the ball in the x–y plane. The measured ball coordinates are continuously compared to the desired center point (0,0). A PID control loop minimizes the error by adjusting the platform’s tilt through coordinated servo movements.

The control system involves inverse kinematics, which computes the required angles for each pair of servo-driven linkages. These angles are then translated into servo PWM signals, tilting the platform to guide the ball back toward the center.

## Domains
1. Mechanical Design: CAD modeling of the platform base, top plate, and servo linkages.
2. Embedded Systems: Using ESP32 microcontroller for IR sensor reading and servo control.
3. Control Theory: PID tuning, inverse kinematics for 3-DOF.
4. Assembly: Integration of IR sensors, servos, and platform joints.
5. PCB Design


### Working 
1. The 6×6 IR sensor grid detects the position of the ball (x, y). The IR sensors act as a light curtain: when the ball blocks IR beams, the corresponding sensor is triggered. This gives a discrete grid coordinate for the ball.
- [IR_Array](IR_Array/README.md)

2. The ESP32 microcontroller receives these readings, computes the ball’s position, and calculates the error relative to the center point.
3. A PID controller computes the required corrective tilt in 3 axes (pitch, roll, vertical translation).
4. Using inverse kinematics, the corrective tilt is mapped to servo rotation angles. For 3-DOF, pairs of servos are assigned to each motion direction.
5. The ESP32 outputs PWM signals to the six servo motors (MG996R). Each pair moves in opposite directions to tilt or lift the platform smoothly.
6. The ball moves on the tilted surface, its new position is sensed by the IR grid, and the control loop repeats, stabilizing the ball at the center.


### PCB Design
The PCB has been designed on KiCad. Schematic:



## Installation
1. Clone the repository:
   
   git clone https://github.com/Siddharth-33/Stewart-Platform.git
   
   cd Stewart-Platform
