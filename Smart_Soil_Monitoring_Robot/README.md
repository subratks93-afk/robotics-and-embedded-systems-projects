# 🌱 Smart Soil Monitoring Robot

A soil-monitoring robotic system based on **Arduino UNO** that measures soil conditions using a soil moisture sensor and displays the sensor value on a **4-digit 7-segment display**. The robot automatically changes its movement and buzzer status according to the detected soil condition.

## 🌱 Project Overview

The robot continuously reads the analog value from a soil moisture sensor.

The measured sensor value is displayed in real time on a **5461BS-1 4-digit common-anode 7-segment display**.

When the sensor value is above the defined threshold, the soil is considered **dry** and the robot moves forward.

When the sensor value is at or below the threshold, the soil is considered **wet**. The robot stops and the buzzer is activated.

## ✨ Features

- Soil condition monitoring
- Real-time soil sensor value display
- Automatic soil condition detection
- Automatic forward movement in dry soil
- Automatic stopping in wet soil
- Buzzer indication
- 4-digit 7-segment display
- Arduino UNO based control
- L293D motor driver
- Battery-powered mobile platform

## 🧰 Components Required

- Arduino UNO × 1
- Soil Moisture Sensor × 1
- 5461BS-1 4-Digit Common-Anode 7-Segment Display × 1
- Buzzer × 1
- L293D Motor Driver × 1
- DC Gear Motors × 2
- Robot Chassis × 1
- Battery × 1

## 📺 Display

The 4-digit 7-segment display shows the **soil moisture sensor reading**.

| Soil Condition | Sensor Value | Robot Action | Display |
|---|---:|---|---|
| Dry Soil | `> 600` | Moves Forward | Sensor Value |
| Wet Soil | `≤ 600` | Stops | Sensor Value |

### Example

If the sensor reading is:

`0750`

The display shows:

**0750**

If the sensor reading is:

`0450`

The display shows:

**0450**

## ⚙️ Working

1. The soil moisture sensor continuously measures the soil condition.
2. The Arduino UNO reads the analog sensor value through **A0**.
3. The sensor value is displayed on the 4-digit 7-segment display.
4. If the sensor value is **greater than 600**, the soil is considered dry.
5. When dry soil is detected, the robot moves forward and the buzzer remains OFF.
6. If the sensor value is **600 or below**, the soil is considered wet.
7. When wet soil is detected, the robot stops and the buzzer is activated.
8. The display continuously updates with the current sensor reading.

## 🔢 Soil Detection Threshold

The robot uses a sensor threshold value of:

**600**

| Sensor Reading | Condition | Action |
|---:|---|---|
| `> 600` | Dry Soil | Move Forward |
| `≤ 600` | Wet Soil | Stop + Buzzer ON |

> **Note:** Soil moisture sensor readings can vary depending on the sensor, soil type, moisture level, and calibration.

## 💻 Arduino Code

The complete Arduino source code is provided in the `.ino` file included in this repository.

**Arduino File:**

`Soil_Monitoring_Using__4__digit.ino`

## 🎥 Demo Video

[▶️ Watch Demo Video](https://drive.google.com/file/d/1HB3mnjJyW6idw7h3gFzMjWKeb-9BJc-V/view?usp=sharing)

## 🛠️ Platform

**Arduino UNO**

## 📌 Project Type

**Arduino Robotics | Soil Monitoring | Smart Agriculture**

## 🚀 Applications

- Soil condition monitoring
- Smart agriculture prototypes
- Agricultural robotics
- Educational robotics projects
- Automated soil monitoring systems
