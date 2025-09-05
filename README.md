# 3-DOF Stewart Platform

##  Overview
** Aims to design and implement a functional 3-DOF Stewart Platform, a parallel manipulator capable of motion in pitch, roll, and vertical heave. The platform will be used for real-time ball-balancing control, where a ball placed on the top surface is continuously stabilized at the center using a 6x6 grid of IR Sensors connected to serial registers for each row.

A 6×6 IR sensor grid is mounted on the top plate to detect the real-time position of the ball in the x–y plane. The measured ball coordinates are continuously compared to the desired center point (0,0). A PID control loop minimizes the error by adjusting the platform’s tilt through coordinated servo movements.

The control system involves inverse kinematics, which computes the required angles for each pair of servo-driven linkages. These angles are then translated into servo PWM signals, tilting the platform to guide the ball back toward the center.

## Domains
Mechanical Design: CAD modeling of the platform base, top plate, and servo linkages.
Embedded Systems: Using ESP32 microcontroller for IR sensor reading and servo control.
Control Theory: PID tuning, inverse kinematics for 3-DOF.
Assembly: Integration of IR sensors, servos, and platform joints.

##  Features
