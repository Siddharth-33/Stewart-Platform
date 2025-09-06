# Servo Control

This project demonstrates basic servo motor control for the three legs of a Stewart Platform prototype. Using the ESP32’s LEDC PWM driver, the code sweeps three servo motors back and forth from 0° to 180°, simulating the motion required to tilt and stabilize the platform.

## Demonstration

## Features
Controls 3 servo motors (legs of the 3-dof Stewart platform).
Uses PWM.
Sweeps all servos simultaneously between 0° and 180°.
Duty cycle calculation handled by a helper function angle_to_DutyCycle().

## Hardware Requirements
ESP32 development board
3× MG 996R Servo motos
External 5V power supply for servos 

## Expected Behavior

All three servos will sweep from 0° → 180° → 0° in 10° increments.
Each step pauses for 500 ms before moving to the next angle.
The current servo angle gets printed in the serial monitor.

## This code is the foundation for Stewart Platform actuation, showcasing how to sweep and control multiple servo motors on the ESP32 using PWM.
