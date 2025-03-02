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

## 📖 Setup Steps

### 1. Required Components
- ESP32 Board
- DHT22 Sensor
- Docker Desktop
- Arduino IDE
### 2. Setup InfluxDB and Grafana in Docker
#### InfluxDB: 
docker run -d --name=influxdb -p 8086:8086 influxdb/influxdb
- Open InfluxDB at: htt://localhost:8086
- Default login: Username: admin / Password: admin123
#### Grafana: 
docker run -d --name=grafana -p 3000:3000 grafana/grafana
- Open Grafana at: http://localhost:3000
- Default login: Username: admin / Password: admin
### 3. Configure Data Source in Grafana
- Data Source Type: InfluxDB
- URL: http://influxdb:8086
- Organization: your_org
- Bucket: your_bucket
- Token: your_secret_token
### 4. Connect ESP32 to WiFi and InfluxDB
- Create DHT22 monitoring code on ESP32
- Configure *WiFi SSID* and *Password* in ESP32 code.
- Configure InfluxDB settings in ESP32 code, including:
    - *InfluxDB URL* (your Docker host machine IP or `http://your-ip:8086`)
    - *Bucket Name*
    - *Organization Name*
    - *API Token*
- Upload code to ESP32
### 5. Connect InfluxDB and Grafana
- Configure InfluxDB setting in Grafana Data Source (url, bucket, org, token)
- In the dashboard, create a query to display a data graph

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
