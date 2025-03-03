#include <WiFiMulti.h>
#include <DHT.h>
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>

// Device and sensor configuration
#define DEVICE "ESP32"
#define PinDht 33
#define DHTTYPE DHT22
DHT dht(PinDht, DHTTYPE);

// WiFi credentials
#define WIFI_SSID "Osiiiii"
#define WIFI_PASSWORD "12032343"

// InfluxDB configuration
#define INFLUXDB_URL "http://192.168.0.188:8086"
#define INFLUXDB_TOKEN "ygA8DeC27UCRDnXGFFrZCHoUMoGwBx0FxtqQUaUXgA9hhFi25gqAIqtU0NsNCLx4T8dXcnsv0muOmAuZozXzCA=="
#define INFLUXDB_ORG "eebc22de2d2bc7e6"
#define INFLUXDB_BUCKET "monitoring-dht22"

// Timezone information for NTP
#define TZ_INFO "WIB-7"

WiFiMulti wifiMulti;
InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert);

void setup() {
  Serial.begin(115200);
  delay(100);

  // Configure WiFi in station mode and add access point
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to WiFi...");
  // Wait until connected to WiFi
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected!");

  // Synchronize time via NTP
  timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");
  Serial.println("Time synchronized");

  // Validate connection to InfluxDB
  if (client.validateConnection()) {
    Serial.println("Connected to InfluxDB");
  } else {
    Serial.print("InfluxDB connection failed: ");
    Serial.println(client.getLastErrorMessage());
  }

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Reconnect WiFi if disconnected
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();
  }

  // Reconnect InfluxDB if connection is lost
  if (!client.validateConnection()) {
    reconnectInfluxDB();
  }

  // Read temperature and humidity from DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check for sensor read errors
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22 sensor!");
    delay(2000);
    return;
  }

  // Create a new point for InfluxDB with updated timestamp
  Point sensor("dht22_data");
  sensor.addTag("device", DEVICE);
  sensor.addTag("location", "greenhouse");
  sensor.addField("temperature", temperature);
  sensor.addField("humidity", humidity);

  // Send the data point to InfluxDB
  if (client.writePoint(sensor)) {
    Serial.printf("Data sent: Temp=%.2f°C, Humidity=%.2f%%\n", temperature, humidity);
  } else {
    Serial.printf("Failed to send data: %s\n", client.getLastErrorMessage().c_str());
  }
  delay(5000);
}

void reconnectWiFi() {
  Serial.println("Reconnecting WiFi...");
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Reconnected!");
}

void reconnectInfluxDB() {
  Serial.println("Reconnecting InfluxDB...");
  if (client.validateConnection()) {
    Serial.println("Reconnected to InfluxDB");
  } else {
    Serial.print("InfluxDB reconnect failed: ");
    Serial.println(client.getLastErrorMessage());
  }
}
