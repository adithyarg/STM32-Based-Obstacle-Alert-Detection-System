# 🔔 STM32 Smart Alert Detection System

A real-time embedded alert system built on STM32 that detects obstacles using an IR sensor and provides audio-visual alerts through buzzer, LED, and OLED display with controlled access for authorized users.

---

## 🎯 Project Overview

This project implements a complete embedded alarm system using the STM32 microcontroller.
The system monitors surroundings through an IR proximity sensor and immediately triggers alerts when an object is detected. An OLED display provides real-time status, while an inbuilt button enables restricted control only for authorized operation.

### Key Features

✅ Real-time obstacle detection
✅ Audio alert using buzzer
✅ Visual alert using external LED
✅ OLED status display via I2C
✅ Controlled inbuilt button access
✅ Reliable GPIO-based logic
✅ Fast response embedded design

---

## 📸 Project Images

### System Setup

![Block Diagram](https://github.com/adithyarg/STM32-Based-Obstacle-Alert-Detection-System/blob/b6991d3b871a2d5cc2b933ee3ff25a07ece76aa7/Block_Diagram.png?raw=true)

### Hardware Implementation

![Working Setup](https://github.com/adithyarg/STM32-Based-Obstacle-Alert-Detection-System/blob/f1516f27a066c82cc0be532a0e97b5f2d989a0d3/working_setup.jpeg?raw=true)

---

## 🔧 Hardware Requirements

* STM32 Development Board (Nucleo/Bluepill)
* IR Proximity Sensor
* Buzzer Module
* External LED
* OLED Display (I2C)
* Inbuilt Push Button
* Jumper Wires & Power Supply

---

## 📋 Pin Configuration

```
STM32 Pin → Component
GPIOx  → IR Sensor Output
GPIOy  → Buzzer
GPIOz  → External LED
SDA    → OLED SDA
SCL    → OLED SCL
BTN    → Inbuilt Button
GND    → Common Ground
VCC    → 3.3V / 5V
```

---

## ⚙️ Working Logic

1. IR sensor continuously monitors for obstacles

2. STM32 reads input through GPIO

3. When object detected:

   * Buzzer → ON
   * External LED → ON
   * OLED → “Object Detected”
   * Inbuilt button → ENABLED

4. When no object:

   * Buzzer → OFF
   * LED → OFF
   * OLED → “No Object”
   * Button → DISABLED

This ensures controlled and secure operation.

---

## 🧠 Core Concepts Used

* GPIO Input/Output
* I2C Communication
* Polling Logic
* Conditional Control
* Peripheral Integration
* Real-time Processing

---

## 🧩 System Architecture

```
IR Sensor → STM32 → Decision Logic → Outputs
                 ↓
              OLED Display
                 ↓
          Authorized Button
```

---

## 🛠 Challenges & Solutions

### OLED Communication Issues

* Problem: Display not initializing
* Fix: Correct I2C address & clock config

### Multi-output Sync

* Problem: Wrong message timing
* Fix: Improved logic sequencing

### False Triggering

* Problem: Noise on IR sensor
* Fix: Debounce and condition checks

---

## 📚 Learning Outcomes

* Hands-on STM32 peripheral control
* Sensor–actuator integration
* Embedded debugging skills
* Real-time decision making
* Hardware–software co-design

---

## 🚀 Future Improvements

* Add GSM/WiFi alert
* Interrupt-based detection
* Battery-powered version
* Mobile monitoring app
* Multi-sensor support

---

## 📄 License

Open source for educational purposes.

---

Built with dedication to learn real embedded systems
