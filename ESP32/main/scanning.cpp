#include "scanning.h"

// Apply Exponential Moving Average for RSSI smoothing
int applyEMA(int prevRSSI, int newRSSI) {
    if (prevRSSI == -100) return newRSSI;
    return (int)(ALPHA * prevRSSI + (1 - ALPHA) * newRSSI);
}

void performScan(LOCATIONS locationLabel) {
    for (int i = 0; i < scansPerLocation; ++i) {
        int accumulatedRSSIs[TOTAL_APS];
        for (int j = 0; j < TOTAL_APS; ++j) accumulatedRSSIs[j] = -100;

        for (int sample = 0; sample < SAMPLES_PER_SCAN; ++sample) {
            int n = WiFi.scanNetworks();

            for (int j = 0; j < n; ++j) {
                String ssid = WiFi.SSID(j);
                int rssi = WiFi.RSSI(j);

                for (int k = 0; k < TOTAL_APS; ++k) {
                    if (ssid.equals(anchorSSIDs[k])) {
                        accumulatedRSSIs[k] = applyEMA(accumulatedRSSIs[k], rssi);
                    }
                }
            }
            WiFi.scanDelete();
            delay(SCAN_DELAY_MS);
        }

        Data scanData;
        scanData.location = locationLabel;
        for (int j = 0; j < TOTAL_APS; ++j) {
            scanData.RSSIs[j] = accumulatedRSSIs[j];
        }

        dataSet.push_back(scanData);
    }
}

LOCATIONS promptLocationSelection() {
    Serial.println("Select Location:");
    for (int i = 0; i < NUMBER_OF_LOCATIONS; ++i) {
        Serial.print(i);
        Serial.print(" - ");
        Serial.println(i); // Ideally replace with meaningful labels
    }

    int loc = -1;
    while (loc < 0 || loc >= NUMBER_OF_LOCATIONS) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c >= '0' && c <= '9') loc = c - '0';
            if (c == '1' && Serial.peek() == '0') {
                Serial.read();
                loc = 10;
            }
            if (c == '1' && Serial.peek() == '1') {
                Serial.read();
                loc = 11;
            }
        }
    }
    return (LOCATIONS)loc;
}