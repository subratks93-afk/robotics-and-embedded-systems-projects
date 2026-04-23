🔊 Sound Activated Robot 

A simple autonomous robot that responds to sound input using a sound sensor. The system detects sound signals (such as a clap) and triggers the robot to move forward for a short duration. An Arduino Uno processes the sensor input and controls motor movement through a motor driver.

⚙️ How It Works

The sound sensor continuously monitors the environment for sound signals.

🔊 Sound Detected (HIGH signal):

The robot moves forward for a short duration (1 second).

⏸️ After Movement:

The robot automatically stops and waits for the next sound input.

The system also prints status messages to the Serial Monitor for debugging.

🔹 Features

Sound-based robot activation

Simple clap/control interaction

Automatic forward movement on detection

Built-in stop delay for controlled motion

Serial monitoring for debugging

🧩 Components Used

Arduino Uno

Sound Sensor Module

Motor Driver (L293D)

DC Motors

Chassis & Wheels

Power Supply

🚀 Applications

Clap-controlled robots

Assistive automation systems

Interactive robotics projects

Educational demonstrations

🔮 Future Improvements

Add multiple command recognition (clap patterns)

Integrate voice recognition module

Add obstacle avoidance system

Implement continuous movement control
