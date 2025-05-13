#include <Arduino.h>
#include <WiFi.h>
#include <vector>
#include <map>

const int num_of_anchors = 2;
const int k = 3;

struct Data {
  int RSSIs[num_of_anchors] = {-1000, -1000};
  String label;
};

const int scanIterationsForRoom = 14;
const int scanIterationNextToRoom = 8;
const int roomNumber = 3;

std::vector<Data> dataVector;
std::vector<String> rooms = {"Lama's Room", "Hala's Room", "Living Room"};
std::vector<String> locations = {
  "in Lama's Room", "in Hala's Room", "in Living Room",
  "Next To Lama's Room", "Next To Hala's Room", "Next To Living Room"
};
std::vector<String> APs = {"AP1", "AP2"};

void scanRoom(const String& roomName) {
  int n = WiFi.scanNetworks();
  Data currentData;
  currentData.label = roomName;

  if (n == 0) {
    Serial.println("No APs found in " + roomName);
  } else {
    for (int i = 0; i < n; i++) {
      String ssid = WiFi.SSID(i);
      for (int j = 0; j < num_of_anchors; j++) {
        if (ssid == APs[j]) {
          currentData.RSSIs[j] = WiFi.RSSI(i);
          Serial.println(String(j) + String(WiFi.RSSI(i)));
        }
      }
    }
    dataVector.push_back(currentData);
  }

  WiFi.scanDelete();
}

void scan() {
  for (int i = 0; i < roomNumber; i++) {
    Serial.println("Ready to scan room: " + rooms[i]);
    Serial.println("Press Enter when you're in the room...");
    while (true) {
      if (Serial.available()) {
        char c = Serial.read();
        if (c == '\n' || c == '\r') break;
      }
    }

    Serial.println("Try to stay static in the room...");
    for (int j = 0; j < scanIterationsForRoom; j++) {
      if(j%2 == 0 && j!=0) {
        Serial.println("Move a little bit");
      }
      scanRoom(locations[i]);
      delay(200);
    }

    Serial.println("Stand next to the room exit and press enter...");
    while (true) {
      if (Serial.available()) {
        char c = Serial.read();
        if (c == '\n' || c == '\r') break;
      }
    }
    for (int j = 0; j < scanIterationNextToRoom; j++) {
      scanRoom(locations[roomNumber + i]);
      delay(200);
    }
    delay(1000);
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(5000);
  Serial.println("Room scanning will start now...");
  scan();
  Serial.println("Room scanning finished.");
  delay(5000);
}

void loop() {
  Serial.println("Press Enter to locate your location...");
  while (true) {
    if (Serial.available()) {
      char c = Serial.read();
      if (c == '\n' || c == '\r') break;
    }
  }

  Serial.println("Scanning to detect your current location...");
  int n = WiFi.scanNetworks();
  int point[num_of_anchors] = {-1000, -1000};

  for (int i = 0; i < n; i++) {
    String ssid = WiFi.SSID(i);
    for (int j = 0; j < num_of_anchors; j++) {
      if (ssid == APs[j]) {
        point[j] = WiFi.RSSI(i);
      }
    }
  }

  String currentRoom = knn_predict(point);
  Serial.println("You're: " + currentRoom);

  WiFi.scanDelete();
  delay(2000);
}