🕷️ Hexapod Robot

📌 Overview

This project focuses on designing and controlling a six-legged (hexapod) robot using servo motors and embedded systems. The robot uses a tripod gait mechanism for stable walking and demonstrates real-world implementation of motion control and multi-actuator coordination.


The system integrates an external servo controller, wireless communication, and power monitoring to achieve efficient and reliable operation.


🚀 Features


* Six-legged walking robot (hexapod structure)
  
* Tripod gait mechanism for stable locomotion
  
* Forward and turning movements
  
* Wireless control using Bluetooth
  
* External servo controller for smooth multi-servo operation
  
* Real-time battery voltage monitoring
  
* Stable power management system
  



🧠 Technologies Used


* Arduino UNO
  
* Embedded C (Arduino IDE)
  
* Servo Motor Control
  
* Robotics Motion Algorithms
  



🔧 Hardware Components


* Microcontroller: Arduino UNO
  
* Servo Controller: USC-32 Servo Controller

* Servo Motors: MG995 High Torque Servos
  
* Communication: HC-05 Bluetooth Module
  
* Display: 3-digit 7-segment voltage display
  
* Switch: Two-way three pin ON/OFF toggle switch
  
* Battery: LiPo Battery (7.4V – 12V, ≥ 6000mAh)
  

⚙️ Working Principle


The robot operates using a **tripod gait algorithm**, which ensures balance and smooth movement.


Movement Logic:


* The six legs are divided into two groups (Tripod A & Tripod B)
  
* At any time, one tripod moves while the other supports the body
  
* This alternating motion creates stable walking
  

Control Flow:


1. Commands are sent via Bluetooth (HC-05)
2. Arduino processes the command
3. Signals are sent to USC-32 servo controller
4. Servo motors execute coordinated movement
5. Voltage display monitors battery status



📂 Project Structure



hexapod_robot/

│

├── hexapod.ino # Main Arduino code



▶️ How to Run


1. Connect all servo motors to USC-32 controller
2. Interface USC-32 with Arduino UNO
3. Connect HC-05 Bluetooth module
4. Power system using LiPo battery
5. Upload code using Arduino IDE
6. Control robot via Bluetooth commands

## 🎥 Demo Video

▶️ Watch Demo: https://drive.google.com/file/d/1DVtB2vYeuB8lYCJvjYk0YoT848yuNnEt/view?usp=drive_link


🔮 Future Improvements

* Autonomous navigation using sensors
  
* Camera integration for vision-based control
  
* AI-based gait optimization
  
* Mobile app control instead of basic Bluetooth
  
* Terrain-adaptive walking
  


👨‍💻 Author


Subrat

AI & Robotics Enthusiast 🚀



⭐ About This Project


This project demonstrates practical implementation of a multi-legged robotic system with real hardware integration. It highlights concepts like servo synchronization, gait algorithms, and embedded control systems, forming a strong foundation for advanced robotics development.

