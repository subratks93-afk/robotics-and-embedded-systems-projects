
# Smart Flame Detection and Alert Robot

```markdown
# Smart Flame Detection and Alert Robot

A mobile fire-detection robot based on **Arduino UNO** that detects flames using a flame sensor and provides an immediate visual and audible alert through a 16×2 LCD and buzzer.

```
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
- L293D motor driver
- Arduino UNO based control
- Battery-powered mobile platform

## 🧰 Components Required

- Arduino UNO
- Flame Sensor
- 16×2 LCD Display
- Buzzer
- L293D Motor Driver
- DC Motors
- Robot Chassis
- Battery
- Connecting Wires

## ⚙️ Working

1. The Arduino UNO continuously reads the flame sensor.
2. The flame sensor output is monitored digitally.
3. When a flame is detected:
   - The robot stops.
   - The buzzer turns ON.
   - The LCD displays a flame warning.
4. When no flame is detected:
   - The buzzer turns OFF.
   - The robot moves forward.
   - The LCD displays the normal operating condition.
```
## 📺 LCD Messages

### System Startup

```text
FIRE DETECTOR
SYSTEM READY

ALERT! FLAME
DETECTED

NO FIRE
MOVING FORWARD
```

💻 Arduino Code

The complete Arduino source code is provided in the .ino file included in this repository.

🛠️ Platform

Arduino UNO

📌 Project Type

Arduino Robotics | Flame Detection | Alert System
