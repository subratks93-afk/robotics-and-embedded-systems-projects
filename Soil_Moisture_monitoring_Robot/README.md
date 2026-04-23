🌱 Soil Moisture Monitoring Robot

A real-time soil moisture monitoring system that measures soil water content using an analog sensor and displays the readings on a 16×2 LCD. The system uses a calibrated threshold value to accurately determine whether the soil is wet or dry, ensuring reliable results based on actual conditions.

⚙️ How It Works

The soil moisture sensor continuously reads analog values from the soil and sends them to the microcontroller.

📊 The raw moisture value is displayed on the LCD and Serial Monitor

🌊 If value < 280: Soil is considered WET

🌵 If value ≥ 280: Soil is considered DRY

The threshold value (280) is experimentally calibrated based on real sensor readings for improved accuracy.

🔹 Features

Real-time soil moisture monitoring

Analog sensor-based measurement

LCD display for instant feedback

Calibrated threshold for accurate detection

Serial output for debugging and analysis

🧩 Components Used

NodeMCU(ESP8266)

Soil Moisture Sensor (Analog Output)

16×2 LCD Display

Connecting Wires

Power Supply

🚀 Applications

Smart agriculture systems

Home gardening

Greenhouse monitoring

Automated irrigation systems

🔮 Future Improvements

Display moisture percentage instead of raw value

Automatic water pump control

IoT-based remote monitoring

Data logging for analysis
