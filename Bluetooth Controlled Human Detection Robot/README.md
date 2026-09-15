# Bluetooth Controlled Human Detection Robot

A Bluetooth-controlled robotic vehicle based on **Arduino UNO** that combines wireless movement control with ultrasonic human/object detection. The robot uses an HC-05 Bluetooth module for receiving movement commands, an HC-SR04 ultrasonic sensor for detecting a person or object within a defined distance, and a 16×2 LCD for displaying the robot status.

## 🤖 Project Overview

The robot can be controlled wirelessly through an HC-05 Bluetooth module.

When the robot is commanded to move forward, the HC-SR04 ultrasonic sensor continuously checks the distance in front of the robot. If a person or object is detected within **50 cm**, the robot automatically stops and activates the buzzer.

The 16×2 LCD displays the current operating status, such as Forward, Backward, Left, Right, Stopped, or Human Detected.

## ✨ Features

- Bluetooth-based wireless control
  
- Human/object detection using HC-SR04
  
- Automatic stopping when a person/object is detected within 50 cm
  
- Buzzer alert during detection
  
- 16×2 LCD status display
  
- Forward, backward, left and right movement
  
- Arduino UNO based control
  
- L293D motor driver for DC motor control

## 🧰 Components Required

- Arduino UNO
  
- HC-05 Bluetooth Module
  
- HC-SR04 Ultrasonic Sensor
  
- 16×2 LCD Display
  
- Buzzer
  
- L293D Motor Driver
  
- DC Motors
  
- Robot Chassis
  
- Battery
  
- Connecting Wires

## ⚙️ Working

1. The Arduino UNO receives commands from the HC-05 Bluetooth module.
   
3. The user can send movement commands for:
   - Forward
   - Backward
   - Left
   - Right
   - Stop
4. When the robot is in forward mode, the HC-SR04 continuously measures the distance ahead.
5. If an object/person is detected at a distance of **50 cm or less**, the robot:
   - Stops the motors.
   - Activates the buzzer.
   - Displays **"Human Detected"** on the LCD.
6. When the path becomes clear again, the robot resumes forward movement.
7. The LCD displays the current robot status.

## 📺 LCD Messages

Examples of displayed messages:

```text
SakRobotix
Ready

SakRobotix
Forward

SakRobotix
Backward

SakRobotix
Left

SakRobotix
Right

SakRobotix
Stopped
```

## 💻 Arduino Code

The complete Arduino source code is provided in the .ino file included in this repository.

## 🛠️ Platform

Arduino UNO

## 📌 Project Type

Arduino Robotics | Bluetooth Control | Human/Object Detection
