🎮 Joystick Controlled Robot 

A manually operated robotic system controlled using a joystick module for real-time directional movement. The system uses an Arduino Uno to read analog inputs from the joystick and control the robot’s movement through a motor driver, enabling intuitive and precise navigation.

⚙️ How It Works

The joystick module provides two analog signals (X-axis and Y-axis) based on its position. These values are read by the Arduino and mapped to movement directions:

⬆️ Forward

⬇️ Backward

⬅️ Left

➡️ Right

⏹️ Center → Stop

The Arduino processes these inputs and sends signals to the motor driver to control the motors accordingly, allowing smooth and responsive movement.

🔹 Features

Real-time manual control using joystick

Analog input-based smooth movement

Simple and intuitive operation

Low-cost and easy to build

Immediate response to user input

🧩 Components Used

Arduino Uno

Joystick Module (XY axis)

Motor Driver (L293D)

DC Motors

Chassis & Wheels

Power Supply

🚀 Applications

Remote-controlled robots

Robotics learning and prototyping

Manual navigation systems

Gaming or control interface projects

🔮 Future Improvements

Wireless joystick control (Bluetooth/WiFi)

Speed control using PWM

Add camera for FPV control

Combine with autonomous mode
