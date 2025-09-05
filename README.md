# 3-DOF Stewart Platform

This project aims to design and implement a functional 3-DOF Stewart Platform, a parallel manipulator capable of motion in pitch, roll, and vertical heave. The platform will be used for real-time ball-balancing control, where a ball placed on the top surface is continuously stabilized at the center.

A 6×6 IR sensor grid is mounted on the top plate to detect the real-time position of the ball in the x–y plane. The measured ball coordinates are continuously compared to the desired center point (0,0). A PID control loop minimizes the error by adjusting the platform’s tilt through coordinated servo movements.

The control system involves inverse kinematics, which computes the required angles for each pair of servo-driven linkages. These angles are then translated into servo PWM signals, tilting the platform to guide the ball back toward the center.
