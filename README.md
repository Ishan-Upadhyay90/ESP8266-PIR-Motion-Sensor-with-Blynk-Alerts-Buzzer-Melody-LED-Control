# 🔔 ESP8266 PIR Motion Sensor with Blynk Alerts, Buzzer Melody & LED Control  

## 📝 Description  
This project is a **smart home security system** built with an ESP8266, PIR motion sensor, buzzer, and LED. When motion is detected, the system:  
- Plays a **pleasant buzzer melody** instead of a harsh alarm  
- Sends **real-time intruder alerts** to the **Blynk app**  
- Allows **remote LED control** via the Blynk mobile app  

It’s an **affordable IoT-based solution** for home security and automation, perfect for beginners learning ESP8266 and Blynk.  

---

## ⚡ Features  
- Motion detection using PIR sensor  
- Melody buzzer for alerts  
- Real-time Blynk notifications  
- Remote LED control from anywhere  
- Simple, low-cost, and beginner-friendly  

---

## 🛠 Hardware Required  
- ESP8266 (NodeMCU / Wemos D1 Mini)  
- PIR Motion Sensor (HC-SR501)  
- Active Buzzer  
- LED + 220Ω Resistor  
- Breadboard & Jumper Wires  

---

## ⚙️ Circuit Connections  

| Component       | ESP8266 Pin | GPIO   |  
|-----------------|-------------|--------|  
| PIR Sensor OUT  | D5          | GPIO14 |  
| Buzzer (+)      | D6          | GPIO12 |  
| LED (+)         | D7          | GPIO13 |  
| GND             | GND         | —      |  
| VCC (PIR/LED)   | 3.3V/5V     | —      |  

---

## 💻 Setup & Installation  

1. **Clone Repository**  
   ```bash
     git clone https://github.com/Ishan-Upadhyay90/ESP8266-PIR-Motion-Sensor-with-Blynk-Alerts-Buzzer-Melody-LED-Control.git
     cd ESP8266-PIR-Motion-Sensor-with-Blynk-Alerts-Buzzer-Melody-LED-Control
### Setup Instructions

2. **Install Arduino IDE Libraries**
   - Go to **File > Preferences** in Arduino IDE
   - Add the ESP8266 board package URL:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```

3. **Install ESP8266 Board Package**
   - Open **Tools > Board > Board Manager**
   - Search for `ESP8266` and install the latest package

4. **Install Blynk Library**
   - Open **Sketch > Include Library > Manage Libraries**
   - Search for `Blynk` and install it

5. **Update Code**
   - Open the provided `.ino` sketch
   - Enter your WiFi credentials and Blynk authentication token:
     ```cpp
     char auth[] = "YourAuthToken";
     char ssid[] = "YourWiFiSSID";
     char pass[] = "YourWiFiPassword";
     ```

6. **Select Your Board**
   - Go to **Tools > Board** and select:
     - `NodeMCU 1.0 (ESP-12E Module)` or  
     - `LOLIN(WEMOS) D1 mini`

7. **Upload Code**
   - Connect your board via USB
   - Select the correct **Port** under Tools
   - Click **Upload** to flash the code

## 🚀 How to Use

1. Open the `pir_motion.ino` file in **Arduino IDE**.

2. Replace the following placeholders with your own details:
   ```cpp
   #define BLYNK_TEMPLATE_ID   "YourTemplateID"
   #define BLYNK_TEMPLATE_NAME "YourTemplateName"
   #define BLYNK_AUTH_TOKEN    "YourAuthToken"

   const char *ssid = "YourWiFiSSID";     // Enter your Wi-Fi Name
   const char *pass = "YourWiFiPassword"; // Enter your Wi-Fi Password
