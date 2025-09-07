# 3-DOF Stewart Platform

## Demo
https://github.com/user-attachments/assets/998ffcb7-0a2c-45e5-982b-bb6aab626a49

---

## Overview
This project aims to design and implement a **3-DOF Stewart Platform** — a parallel manipulator capable of motion in **pitch**, **roll**, and **vertical heave**.  
It is used for a **ball-balancing control system**, where a ball placed on the platform is continuously stabilized at the center using a **6×6 IR sensor grid** connected via shift registers.

The control system:
- Detects the ball’s real-time position using IR sensors  
- Computes error relative to the center point (0,0)  
- Uses a **PID control loop** to minimize error 
- Sends PWM signals to **3 servo motors (MG996R)** to tilt the platform  

---

## Domains
1. **Mechanical Design**: CAD modeling of platform base, top plate, and servo linkages  
2. **Embedded Systems**: ESP32 for IR sensor interfacing and servo control  
3. **Control Systems**: PID tuning for 3-DOF motion  
4. **Assembly**: Integration of IR sensors, servos, and mechanical joints  
5. **PCB Design**: Custom PCB design in KiCad  

---

## Working Principle

1. **Ball Detection**  
   - A **6×6 IR sensor grid** detects the ball’s position (x, y).  
   - IR sensors act as a light curtain: when the ball blocks a beam, the sensor triggers, giving a discrete grid coordinate.
   - [IR Grid README](IR_Array/README.md)  

2. **Signal Processing**  
   - Sensor outputs pass through an **Op-Amp comparator circuit**.  
   - Signals are fed into **74HC165 shift registers**, reducing GPIO usage.  
   - Shift register outputs are read by the **ESP32** via SPI.  
   - [Shift Register README](SPI_TRY/README.md)  

3. **Ball Positioning**  
   - ESP32 decodes sensor readings to compute the ball’s current (x, y) position.  
   - This position is compared to the target center point (0,0).  

4. **Control System**  
   - **PID tuning** to control the platform movement.

5. **Actuation**  
   - ESP32 generates **PWM signals** for 3 MG996R servos.  
   - Each pair of servos works in opposition to tilt or lift the platform.  
   - The ball moves accordingly, and the control loop repeats.  

---

## PCB Design
- PCB design is in progress using **KiCad**  
- Includes IR sensor interfacing, shift register chain, and LM358 IC.
- [PCB Design schematic](PCB_design/PCB_WORK)

---

## Structure
- [CAD_design](CAD_design)  
- [IR_Analog](IR_Analog)  
- [IR_Array](IR_Array)  
- [IR_Read](IR_Read)  
- [IR_Servo](IR_Servo)  
- [Multi_IR](Multi_IR)  
- [Multi_IrServo](Multi_IrServo)  
- [Multiple_Servos](Multiple_Servos)  
- [new_servo](new_servo)  
- [PCB_design](PCB_design)  
- [platform_circle](platform_circle)  
- [README.md](README.md)  
- [Servos_final](Servos_final)  
- [Servo_Simple](Servo_Simple)  
- [SPI_TRY](SPI_TRY)  

## Installation

```bash
git clone https://github.com/Siddharth-33/Stewart-Platform.git
cd Stewart-Platform

