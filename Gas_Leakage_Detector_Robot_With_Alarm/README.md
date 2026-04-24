🚨 Gas Leakage Detection Robot with Alarm 

An autonomous mobile robot designed to detect gas leakage in real time and respond with immediate safety actions. The system uses a gas sensor to monitor the environment and an Arduino Uno to control a buzzer alarm and robot movement through an L293D motor driver.

⚙️ How It Works

The gas sensor continuously checks for the presence of gas and sends a digital signal to the Arduino.

🚨 If gas is detected (LOW signal):

The buzzer is activated to alert users, and the robot immediately stops to prevent further movement in a hazardous area.

✅ If no gas is detected (HIGH signal):

The buzzer remains off, and the robot moves forward to continue monitoring the surroundings.

The system also displays the gas status on the Serial Monitor for real-time observation.

🔹 Features

Real-time gas leakage detection

Instant buzzer alert system

Automatic robot stop during gas detection

Continuous forward movement for monitoring

Simple and effective safety mechanism

🧩 Components Used

Arduino Uno

Gas Sensor (MQ series)

Buzzer

L293D Motor Driver

DC Motors

Chassis & Wheels

Battery

🚀 Applications
Industrial safety monitoring

Home gas leakage detection

Hazardous environment inspection

Educational robotics projects

## 🎥 Demo Video

▶️ Watch Demo: (https://drive.google.com/file/d/1_QW29AR_9huz7mJ6zd7UtN7j2I1gIabh/view?usp=drive_link)

🔮 Future Improvements

Add LCD/LED display for gas level indication

Integrate IoT for remote alerts

Add obstacle avoidance

Implement autonomous navigation

