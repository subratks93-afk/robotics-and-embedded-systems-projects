# 🔥 Smart Flame Detection and Alert Robot

A mobile fire-detection robot based on **Arduino UNO** that detects flames using a flame sensor and provides an immediate visual and audible alert.

## 🔥 Project Overview

The robot continuously monitors its surroundings using a flame sensor.

When a flame is detected, the Arduino UNO stops the robot, activates the buzzer, and displays an alert message on the 16×2 LCD.

When no flame is detected, the buzzer remains OFF and the robot moves forward.

## ✨ Features

- Flame detection
- Automatic robot stopping during flame detection
- Audible alert using buzzer
- 16×2 LCD status display
- Automatic forward movement when no flame is detected

## 🧰 Components Required

- Arduino UNO × 1
- Flame Sensor × 1
- 16×2 LCD Display × 1
- Buzzer × 1
- L293D Motor Driver × 1
- DC Gear Motors × 2
- Robot Chassis × 1
- Battery × 1

## 📺 LCD Messages

The 16×2 LCD displays the following status messages:

| Condition | LCD Display |
|---|---|
| System startup | `FIRE DETECTOR` / `SYSTEM READY` |
| Flame detected | `ALERT! FLAME` / `DETECTED` |
| No flame detected | `NO FIRE` / `MOVING FORWARD` |

## ⚙️ Working

1. The flame sensor continuously monitors for a flame.
2. If a flame is detected, the robot stops.
3. The buzzer turns ON.
4. The LCD displays the flame detection alert.
5. When no flame is detected, the buzzer remains OFF.
6. The robot moves forward.

## Demo Video

[▶️ Watch Demo Video](https://drive.google.com/drive/u/0/folders/1RrT1dFiKXLl6gCCoFAbCKo7-rh9qPY-y)

## 💻 Arduino Code

The complete Arduino source code is provided in the `.ino` file included in this repository.

## 🛠️ Platform

**Arduino UNO**

## 📌 Project Type

Arduino Robotics | Flame Detection | Safety & Alert System
