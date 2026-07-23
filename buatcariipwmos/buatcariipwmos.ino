#include <WiFi.h>

// Ganti dengan nama WiFi dan password kamu
const char* ssid     = "NAMA_WIFI_KAMU";
const char* password = "PASSWORD_WIFI_KAMU";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.print("Menghubungkan ke WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Tunggu sampai berhasil connect
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi terhubung!");

  // Tampilkan info IP
  Serial.print("IP Address  : ");
  Serial.println(WiFi.localIP());

  Serial.print("Gateway     : ");
  Serial.println(WiFi.gatewayIP());

  Serial.print("Subnet Mask : ");
  Serial.println(WiFi.subnetMask());

  Serial.print("MAC Address : ");
  Serial.println(WiFi.macAddress());

  Serial.print("Signal (RSSI): ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
}

void loop() {
  // Bisa dipakai untuk cek ulang tiap beberapa detik
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("IP saat ini: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi terputus, mencoba reconnect...");
    WiFi.reconnect();
  }
  delay(5000); // cek tiap 5 detik
}