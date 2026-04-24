# 🎨 Color Controlled Robot 

## 📌 Overview

This project demonstrates a **color-based control robot** using the TCS3200 color sensor and L293D motor driver.

The robot responds to specific colors:

* 🔵 **Blue Color → Move Forward**
  
* 🔴 **Red Color → Move Backward**
  
* ⚪ **Other Colors (including ambient light) → Stop**

The system is designed to avoid false detection caused by environmental lighting (like yellow room light).


## 🚀 Features

* Real-time color detection using TCS3200 sensor
  
* Stable detection with threshold-based filtering
  
* Noise reduction to avoid ambient light interference
  
* Simple motor control using L293D
  
* Default safety: robot stays **STOPPED unless valid color detected**
  


## 🧰 Components Used

* Arduino (Uno / Nano)
  
* TCS3200 Color Sensor
  
* L293D Motor Driver
  
* DC Motors (2)
  
* Jumper Wires
  
* Power Supply


## 🔌 Circuit Connections

### 🔹 Color Sensor (TCS3200 → Arduino)

* S0 → D4
  
* S1 → D5
  
* S2 → D6
  
* S3 → D7
  
* OUT → D8
  
* VCC → 5V
  
* GND → GND
  
* OE → GND
  

### 🔹 Motor Driver (L293D → Arduino)

* IN1 → D9
  
* IN2 → D10
  
* IN3 → D11
  
* IN4 → D12
  
* EN1, EN2 → 5V
  

## ⚙️ Working Principle

The TCS3200 sensor detects color by measuring frequency corresponding to RGB values.

* Lower value = stronger color intensity
  
* The system compares RGB values with thresholds
  
* Strict conditions are used to avoid false detection

### Logic:

* If **Blue is dominant** → Robot moves forward
  
* If **Red is dominant** → Robot moves backward
  
* Otherwise → Robot stops

---

## 🧠 Algorithm

1. Read RGB values from sensor
   
2. Apply threshold filtering
   
3. Compare dominant color
   
4. Control motors accordingly


## 🛠️ Code

The Arduino code reads RGB values and controls motors using digital outputs.

> Note: Calibration may be required depending on lighting conditions.


## ⚠️ Calibration Tips

* Keep sensor 2–5 cm from object
  
* Avoid strong ambient light
  
* Adjust threshold values in code:


blueValue < 80

redValue < 80

## 🎥 Demo Video

▶️ Watch Demo: https://drive.google.com/file/d/1831c97YwwYt94V4btDdL54r_nPCLlU93/view?usp=drive_link


## 🔥 Applications

* Color-controlled robots
  
* Sorting systems
  
* Industrial automation
  
* Smart robotics projects
  



## 🚀 Future Improvements

* Add LCD display for color values
  
* Implement auto-calibration
  
* Integrate obstacle detection
  
* Add line-following capability


## 👨‍💻 Author

**Subrat**


## ⭐ If you like this project

Give it a ⭐ on GitHub and share it!

