🤖 Advanced Obstacle Avoidance Robot

An autonomous robotic system designed to detect and avoid obstacles intelligently using an ultrasonic sensor mounted on a servo motor. The robot scans its surroundings in multiple directions and makes decisions based on distance measurements to navigate safely.

⚙️ How It Works

The robot continuously measures the distance in front using an ultrasonic sensor.

🚗 If no obstacle is detected (distance ≥ 15 cm):

The robot moves forward continuously.

🚧 If an obstacle is detected (distance < 15 cm):

The robot stops and performs environmental scanning:

Rotates the sensor to the left (150°) and measures distance

Rotates to the right (30°) and measures distance

🧠 Decision Making:

Turns left if left side has more space

Turns right if right side has more space

Defaults to right turn if both sides are similar

This scanning-based logic allows smarter navigation compared to basic obstacle avoidance robots.

🔹 Features

Intelligent obstacle detection using ultrasonic sensor

Servo-based directional scanning (left & right)

Decision-based movement (not random turning)

Smooth autonomous navigation

Real-time distance monitoring via Serial output

🧩 Components Used

Arduino Uno

Ultrasonic Sensor (HC-SR04)

Servo Motor

Motor Driver (L293D)

DC Motors

Chassis & Wheels

Power Supply

🚀 Applications

Autonomous navigation robots

Indoor delivery robots

Smart mobility systems

Robotics learning and prototyping

🔮 Future Improvements

Add PID control for smoother turning

Integrate mapping (SLAM basics)

Add camera for vision-based navigation

Combine with line-following or GPS
