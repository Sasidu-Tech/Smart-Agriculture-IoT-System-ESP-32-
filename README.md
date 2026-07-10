# 🌱 Smart Agriculture IoT System using ESP32

An IoT-based Smart Agriculture System developed using ESP32 to automate irrigation and monitor environmental conditions in real time. This project monitors soil moisture, temperature, humidity, and water tank level while providing both automatic and manual irrigation control through the Blynk IoT platform.

---

# 📌 Project Overview

This Smart Agriculture IoT System helps maintain healthy plant growth by automatically watering plants when the soil becomes dry. The system continuously monitors environmental conditions and displays live information on both an LCD display and the Blynk mobile application.

The water tank level is measured using an ultrasonic sensor and displayed as a percentage. If the tank water level becomes low, a buzzer generates a **beep-beep** warning sound to alert the user to refill the tank.

Users can also manually control the water pump from the Blynk application at any time.

---

# ✨ Features

- 🌱 Real-Time Soil Moisture Monitoring
- 🌡 Temperature Monitoring using DHT11
- 💧 Humidity Monitoring
- 🚰 Water Tank Level Monitoring
- 📊 Water Level Displayed as Percentage
- 🤖 Automatic Irrigation when Soil is Dry
- 🎮 Manual Pump Control using Blynk
- 📱 Real-Time IoT Monitoring
- 📟 LCD Live Display
- 🔔 Low Water Level Buzzer Alert (Beep-Beep Sound)
- ⚡ Automatic Pump ON/OFF
- ☁ Wi-Fi Based IoT System

---

# 🛠 Hardware Components

- ESP32 Development Board
- 16×2 I2C LCD Display
- DHT11 Temperature & Humidity Sensor
- Soil Moisture Sensor
- HC-SR04 Ultrasonic Sensor
- 1 Channel Relay Module
- Water Pump
- Active Buzzer
- Breadboard Power Supply Module
- Flower Pot
- Water Tank
- Jumper Wires

---

# ⚙ System Working

## 🌱 Soil Moisture Monitoring

The soil moisture sensor continuously measures the moisture level of the flower pot.

If the soil becomes dry and the moisture value exceeds the predefined threshold, the ESP32 automatically turns ON the water pump through the relay module.

When sufficient moisture is detected, the pump automatically turns OFF.

---

## 💧 Manual Irrigation

The water pump can also be controlled manually using the Blynk mobile application.

Users simply press the ON/OFF button on the dashboard to control irrigation whenever required.

---

## 🌡 Temperature & Humidity Monitoring

The DHT11 sensor continuously measures

- Temperature
- Humidity

These values are displayed on the LCD screen and updated in real time on the Blynk dashboard.

---

## 🚰 Water Tank Monitoring

The HC-SR04 ultrasonic sensor measures the water level inside the storage tank.

The measured distance is converted into a water level percentage.

The percentage is displayed on

- LCD Display
- Blynk Dashboard

---

## 🔔 Low Water Level Alert

When the water level drops below the predefined limit,

- The buzzer automatically produces a **Beep-Beep** warning sound.
- The user is notified that the water tank needs to be refilled.

---

# 📱 Blynk Dashboard

The Blynk IoT Dashboard displays real-time data including

- 🌱 Soil Moisture
- 🌡 Temperature
- 💧 Humidity
- 🚰 Water Tank Level (%)
- ⚙ Water Pump Status
- 🎮 Manual Pump ON/OFF Button
- 🔔 Low Water Level Warning

---

# 📟 LCD Display

The LCD displays

- Temperature
- Humidity
- Soil Moisture Value
- Water Pump Status (ON/OFF)

---

# 📊 Monitored Parameters

| Parameter | Sensor |
|-----------|--------|
| Soil Moisture | Soil Moisture Sensor |
| Temperature | DHT11 |
| Humidity | DHT11 |
| Water Tank Level | HC-SR04 Ultrasonic Sensor |
| Pump Status | Relay Module |
| Low Water Alert | Active Buzzer |

---

# 🚀 Technologies Used

- ESP32
- Arduino IDE
- Embedded C++
- Blynk IoT Platform
- Wi-Fi
- I2C LCD Library
- DHT Library
- NewPing / HC-SR04 Library

---

# 🌾 Applications

- Smart Agriculture
- Smart Irrigation
- Home Gardening
- Greenhouse Automation
- Automatic Plant Watering
- IoT Based Farming

---

# 📸 Project Features

✅ Automatic Irrigation

✅ Manual Irrigation via Blynk

✅ Real-Time Sensor Monitoring

✅ LCD Live Display

✅ Water Tank Level Percentage

✅ Low Water Level Buzzer Alert

✅ Wi-Fi Based IoT Dashboard

---

# 🔮 Future Improvements

- Rain Sensor Integration
- Weather Forecast API
- Fertilizer Recommendation
- Water Usage Statistics
- Email Notifications
- Telegram Alerts
- Firebase Data Logging
- Solar Power Support

---

# 👨‍💻 Author

**Sasidu Wishshanka**

GitHub: https://github.com/Sasidu-Tech

---

# ⭐ If you like this project

Please give this repository a ⭐ on GitHub.

---

# 📄 License

This project is developed for educational and learning purposes.
