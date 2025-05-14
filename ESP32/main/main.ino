
#include <Arduino.h>
#include <vector>
#include <WiFi.h>

#include "utillities.h"
#include "scanning.h"
#include "kNN.h"

void confirmLocation(LOCATIONS predictedLocation) {
    Serial.print("Predicted Location: ");
    Serial.println(predictedLocation);
    Serial.println("Is this correct? (y/n)");

    while (true) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c == 'y' || c == 'Y') {
                Serial.println("Location confirmed.");
                break;
            }
            if (c == 'n' || c == 'N') {
                Serial.println("Please check scanning process or environment.");
                break;
            }
        }
    }
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(1000);

    Serial.println("1 - Prediction Data Collection");

    for (int i = 0; i < NUMBER_OF_LOCATIONS; ++i) {
        LOCATIONS selectedLocation = promptLocationSelection();
        Serial.println("Press Enter to start scanning...");

        while (true) {
            if (Serial.available()) {
                char c = Serial.read();
                if (c == '\n' || c == '\r') break;
            }
        }

        performScan(selectedLocation);
    }

    Serial.println("Data Collection Complete.");
    delay(1000);
}

void loop() {
    Serial.println("Stand still to predict location. When you're ready, press Enter...");
    while (true) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c == '\n' || c == '\r') break;
        }
    }

    int point[NUMBER_OF_ANCHORS] = {-1000, -1000, -1000, -1000, -1000, -1000}; 
    int n = WiFi.scanNetworks();
    for (int j = 0; j < n; ++j) {
         String ssid = WiFi.SSID(j);
         int rssi = WiFi.RSSI(j);

        for (int k = 0; k < TOTAL_APS; ++k) {
            if (ssid.equals(anchorSSIDs[k])) {
                point[k] = rssi;
            }
         }
    }

    // Predict location and confirm with user
    LOCATIONS predictedLoc = static_cast<LOCATIONS>(KNNPredict(point));
    confirmLocation(predictedLoc);
}
