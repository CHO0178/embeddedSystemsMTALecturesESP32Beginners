#include <Arduino.h>
#include <WiFi.h>

void setupWifi(const char* ssid, const char* password) {
    Serial.print("Připojuji se k WiFi: ");
    Serial.println(ssid);
    delay(100);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
    }
    Serial.println("\nWiFi připojeno!");
    Serial.print("IP adresa ESP32: ");
    Serial.println(WiFi.localIP());
}