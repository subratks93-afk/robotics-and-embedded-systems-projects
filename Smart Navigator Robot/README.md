# 🧭 Smart Navigator Robot

An autonomous obstacle-avoiding robot based on **Arduino UNO** that uses an **HC-SR04 ultrasonic sensor** mounted on an **SG90 servo motor** to scan its surroundings and select a suitable direction for navigation.

A **5461BS-1 4-digit common-anode 7-segment display** is used to display the measured distance values.

## 🧭 Project Overview

The Smart Navigator Robot continuously measures the distance in front of the robot.

When the path is clear, the robot moves forward.

When an obstacle is detected within **50 cm**, the robot stops and uses the SG90 servo motor to scan the left and right sides.

The Arduino compares the measured distances and turns the robot toward the side with more available space.

## ✨ Features

- Autonomous obstacle avoidance
- HC-SR04 ultrasonic distance sensing
- SG90 servo-based sensor scanning
- Automatic left/right direction selection
- Real-time distance display
- 4-digit 7-segment display
- Forward movement
- In-place left and right turning
- Arduino UNO based control
- L293D motor driver

## 🧰 Components Required

- Arduino UNO × 1
- HC-SR04 Ultrasonic Sensor × 1
- SG90 Servo Motor × 1
- 5461BS-1 4-Digit Common-Anode 7-Segment Display × 1
- L293D Motor Driver × 1
- DC Gear Motors × 2
- Robot Chassis × 1
- Battery × 1
- Connecting Wires

## ⚙️ Working

1. The HC-SR04 ultrasonic sensor measures the distance in front of the robot.
2. The measured distance is displayed on the 4-digit 7-segment display.
3. If the front distance is **50 cm or greater**, the robot moves forward.
4. If an obstacle is detected within **50 cm**, the robot stops.
5. The SG90 servo rotates the ultrasonic sensor toward the left side.
6. The left-side distance is measured.
7. The servo then rotates the ultrasonic sensor toward the right side.
8. The right-side distance is measured.
9. The Arduino compares the left and right distances.
10. The robot turns toward the side with greater available space.
11. If both sides have approximately similar distances, the robot performs a default right turn.
12. The robot continues navigating.

## 🧠 Navigation Logic

```text
              START
                │
                ▼
       Measure Front Distance
                │
                ▼
       Is Distance < 50 cm?
          /             \
        NO               YES
        │                 │
        ▼                 ▼
  Move Forward           STOP
                          │
                          ▼
                    Scan Left Side
                          │
                          ▼
                   Measure Distance
                          │
                          ▼
                   Scan Right Side
                          │
                          ▼
                   Measure Distance
                          │
                          ▼
                  Compare Distances
                    /          \
                   /            \
              Left Greater   Right Greater
                  │                │
                  ▼                ▼
             Turn Left        Turn Right
                   \              /
                    \            /
                     ▼          ▼
                      Navigate
                         │
                         ▼
                       Repeat
```

## 📟 Distance Display

The **5461BS-1 4-digit common-anode 7-segment display** shows the measured distance value in centimeters.

The display provides real-time distance information during navigation.

### Example

If the measured distance is **50 cm**, the display shows:

```text
0050
```

The program supports displaying distance values from **0 to 9999**.

## 🔢 Obstacle Detection Threshold

The robot uses a front obstacle detection threshold of:

**50 cm**

| Front Distance | Robot Action |
|---|---|
| `≥ 50 cm` | Move Forward |
| `< 50 cm` | Stop and Scan |

## 🔄 Direction Selection

After detecting an obstacle, the robot measures the available space on both sides.

| Condition | Robot Action |
|---|---|
| Left distance > Right distance + 5 cm | Turn Left |
| Right distance > Left distance + 5 cm | Turn Right |
| Both distances approximately equal | Default Right Turn |

## 💻 Arduino Code

The complete Arduino source code is provided in the `.ino` file included in this repository.

**Arduino File:** `Smart_Navigator_Robot.ino`

## 🛠️ Platform

**Arduino UNO**

## 📌 Project Type

**Arduino Robotics | Autonomous Navigation | Obstacle Avoidance**

## 🚀 Applications

- Autonomous robotic navigation
- Obstacle avoidance systems
- Educational robotics
- Indoor mobile robots
- Arduino-based navigation projects
- Robotics learning and prototyping
