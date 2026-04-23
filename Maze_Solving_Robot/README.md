🤖 Maze Solving Robot

An autonomous robot designed to navigate and solve simple mazes using three sensor inputs and rule-based decision logic. The system uses an Arduino Uno to process sensor data and control movement through a motor driver, enabling the robot to follow paths and make directional decisions in real time.

⚙️ How It Works

The robot uses three digital sensors (left, center, right) to detect the path or line.

🟢 Center Sensor Active (HIGH):

The robot moves forward.

⬅️ Left Sensor Active (HIGH):

The robot turns left.

➡️ Right Sensor Active (HIGH):

The robot turns right.

🔄 No Sensor Active:

The robot performs a turn back (U-turn) to recover and find the correct path.

This priority-based logic allows the robot to navigate through maze-like paths and intersections.

🔹 Features

Autonomous maze navigation

Three-sensor based path detection

Priority-based decision making

Automatic recovery using U-turn logic

Real-time sensor monitoring via Serial output

🧩 Components Used

Arduino Uno

IR Sensors (3 units)

Motor Driver (L293D)

DC Motors

Chassis & Wheels

Power Supply

🚀 Applications

Maze solving robots

Line-following systems

Robotics competitions

Educational robotics projects

🔮 Future Improvements

Implement optimized algorithms (Left-hand/Right-hand rule)

Add memory for path optimization

Use PID control for smoother movement

Add obstacle detection integration
