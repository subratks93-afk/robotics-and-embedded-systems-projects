# 🕷️ Hexapod Robot – USB 32CH Servo Controller

A six-legged robotic platform designed and controlled using an **Arduino UNO**, **USC-32 servo controller**, and **MG995 high-torque servo motors**. The robot uses a **tripod gait mechanism** to achieve stable and coordinated walking.

The system integrates **Bluetooth wireless control**, external multi-servo control, and battery voltage monitoring for reliable robotic operation.

## 📌 Project Overview

This project focuses on the design and implementation of a **six-legged (hexapod) robot** using servo motors and embedded control systems.

The robot uses a **tripod gait mechanism**, where the six legs are divided into two groups. Each group alternately moves while the other supports the robot body, providing stable locomotion.

An **USC-32 servo controller** is used to control the multiple servo motors, while an **HC-05 Bluetooth module** provides wireless command input.

A 3-digit voltage display is used to monitor the robot's battery voltage.

## 🚀 Features

- Six-legged hexapod robotic structure
- Tripod gait mechanism for stable locomotion
- Coordinated multi-servo movement
- Forward and backward movement
- Left and right turning
- Wireless control using HC-05 Bluetooth
- External USC-32 servo controller
- MG995 high-torque servo motors
- Real-time battery voltage monitoring
- Battery-powered operation
- Arduino UNO based control system

## 🧠 Technologies Used

- Arduino UNO
- Embedded C / Arduino Programming
- Arduino IDE
- Servo Motor Control
- Tripod Gait Algorithm
- Robotics Motion Control
- Bluetooth Communication
- Multi-Actuator Coordination

## 🔧 Hardware Components

| Component | Quantity |
|---|---:|
| Arduino UNO | 1 |
| USC-32 Servo Controller | 1 |
| MG995 High-Torque Servo Motors | 18 |
| HC-05 Bluetooth Module | 1 |
| 3-Digit 7-Segment Voltage Display | 1 |
| Two-Way 3-Pin ON/OFF Toggle Switch | 1 |
| LiPo Battery | 1 |

### Battery

- Voltage: **7.4V – 12V**
- Capacity: **≥ 6000mAh**

## ⚙️ Working Principle

The robot uses a **tripod gait algorithm** to maintain balance while walking.

The 18 servo motors control the three joints of each of the six legs.

### 🦿 Tripod Gait

The six legs are divided into two groups:

- **Tripod A**
- **Tripod B**

At any given time:

1. One tripod moves the legs into the next position.
2. The other tripod supports the robot body.
3. The supporting tripod then moves.
4. The cycle repeats to create continuous walking motion.

This alternating movement provides stability and coordinated locomotion.

## 🎮 Control Flow

The robot is controlled wirelessly using the HC-05 Bluetooth module.

```text
        Bluetooth Command
               │
               ▼
        HC-05 Bluetooth
               │
               ▼
          Arduino UNO
               │
               ▼
       USC-32 Servo Controller
               │
               ▼
        18 Servo Motors
               │
               ▼
        Hexapod Movement
```

The Arduino receives movement commands through Bluetooth and sends the corresponding servo commands to the USC-32 controller.

The servo controller then generates the required signals for coordinated movement of the 18 servos.

## 🎮 Bluetooth Commands

The robot supports wireless movement commands through the HC-05 Bluetooth module.

| Command | Function |
|---|---|
| `F` | Forward |
| `B` | Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `S` | Home / Stand Position |
| `U` | Move Up |
| `D` | Move Down |
| `T` | Twist Movement |
| `W` | Hello Movement |

## 🔋 Power Monitoring

A **3-digit 7-segment voltage display** is used to monitor the battery voltage during operation.

The voltage display allows the user to observe the battery status while controlling the robot.

The robot uses a **LiPo battery** as its primary power source.



## ▶️ How to Run

1. Connect all 18 MG995 servo motors to the **USC-32 servo controller**.
2. Connect the USC-32 servo controller to the **Arduino UNO**.
3. Connect the **HC-05 Bluetooth module** to the Arduino.
4. Connect the battery and power management system.
5. Verify all servo connections and power connections.
6. Upload `hexapod.ino` using the **Arduino IDE**.
7. Pair a Bluetooth-enabled device with the HC-05 module.
8. Send the required movement commands.
9. The Arduino processes the commands and controls the robot through the USC-32 controller.

## 🎥 Demo Video

[▶️ Watch Demo Video](https://drive.google.com/file/d/1DVtB2vYeuB8lYCJvjYk0YoT848yuNnEt/view?usp=drive_link)

## 🔮 Future Improvements

- Autonomous navigation using sensors
- Camera integration for vision-based control
- AI-based gait optimization
- Mobile application for wireless control
- Terrain-adaptive walking
- Obstacle detection and avoidance
- ROS/ROS 2 integration
- Advanced gait planning
- IMU-based balance control

## 👨‍💻 Author

**Subrat**

AI & Robotics Enthusiast

## ⭐ About This Project

This project demonstrates the practical implementation of a **multi-legged robotic system** using real-world hardware and coordinated servo control.

It highlights key robotics concepts including **servo synchronization, tripod gait algorithms, wireless communication, multi-actuator coordination, and embedded control systems**.

The project provides a strong foundation for developing more advanced **autonomous and intelligent robotic systems**.
