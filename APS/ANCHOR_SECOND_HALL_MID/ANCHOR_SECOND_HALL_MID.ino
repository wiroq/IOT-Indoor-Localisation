#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  //WiFi.softAP("ANCHOR_LOBBY", "password123");  // Set SSID and password
  //WiFi.softAP("ANCHOR_PRINTER", "password123");  // Set SSID and password
  //WiFi.softAP("ANCHOR_HALL_ENTRANCE", "password123");  // Set SSID and password
  WiFi.softAP("ANCHOR_SECOND_HALL_MID", "password123");  // Set SSID and password
  //  WiFi.softAP("ANCHOR_HALL_END", "password123");  // Set SSID and password

  Serial.println("Room 231 AP started");
}

void loop() {
  // AP runs continuously
}