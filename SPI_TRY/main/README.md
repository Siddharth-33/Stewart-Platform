# SHIFT REGISTERS FOR IR SENSORS READ

## Overview
This project demonstrates how to interface **36 IR sensors** with an **ESP32** using **74HC165 parallel-in serial-out shift registers**.  
The shift registers capture the sensor states (HIGH/LOW) in parallel and then shift them out serially to the ESP32 via SPI.  

This reduces GPIO usage on the ESP32 while allowing multiple digital inputs to be read efficiently.

---

## Demonstration

https://github.com/user-attachments/assets/283f2df7-b4b4-4fb8-b4f1-d4f5bfe44b0a


## Hardware Setup

- **ESP32 
- **IR Sensors** × 36  
- **74HC165 Shift Registers** × 6 (each handles one row)  

### 🔗 Connections
- **74HC165 Pins**
  - `QH` → ESP32 `MISO` (GPIO 27 in code)  
  - `CLK` → ESP32 `SCLK` (GPIO 33 in code)  
  - `SH/LD` → ESP32 `GPIO 32` (controls load/shift)  
  - `CE` (Clock Enable) → GND (always enabled)  
  - `SER` (Serial input) → not used  
  - `VCC` → 3.3V  
  - `GND` → GND  

## Software

### `main.c`
The provided code
   - Loads parallel data from sensors  
   - Shifts out sensor states via SPI  
   - Prints sensor readings
