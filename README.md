# 🌡️ IoT Monitoring System: ESP32 + DHT22 to InfluxDB and Grafana (Docker)

🚀 This project demonstrates how to build a **real-time environmental monitoring system** using **ESP32** and **DHT22** sensor, sending temperature and humidity data to **InfluxDB** and visualized using **Grafana** running inside **Docker Desktop**.

---

## 💻 System Architecture

---

## 🛠️ Technologies Used

| Component        | Technology |
|------------------|-------------|
| Microcontroller  | ESP32 |
| Sensor           | DHT22 |
| Language         | C++ (Arduino) |
| Data Protocol    | HTTP |
| Database         | InfluxDB 2.x (Docker) |
| Visualization    | Grafana (Docker) |
| Containerization | Docker Desktop |

---

## 📡 Hardware Requirements

- ESP32 development board
- DHT22 sensor
- Breadboard & jumper wires
- Power supply for ESP32

---

## 📦 Software Requirements

| Software       | Version |
|----------------|---------|
| Arduino IDE    | Latest |
| Docker Desktop | Latest |
| InfluxDB       | 2.x (Docker) |
| Grafana        | Latest (Docker) |

---

## 📊 Data Flow

1. ESP32 reads **temperature** and **humidity** from DHT22.
2. ESP32 sends data to **InfluxDB** via **HTTP API**.
3. InfluxDB stores data inside a time-series bucket.
4. Grafana reads data from InfluxDB.
5. Grafana visualizes temperature and humidity data in real-time.

---

## 📊 Simple Dashboard Preview
### 1️⃣ InfluxDB Chart Preview

### 2️⃣ Grafana Chart Preview

---

<div align="center">

## 📬 Need a Similar Project? Let's Collaborate!
If you need a **custom IoT project** for **smart home, agriculture, industrial monitoring**, or other use cases,  
I’m ready to assist you!  

📧 **Reach out at:**  
### andreas.sebayang9999@gmail.com  

Let’s create something amazing together! 🚀

</div>
