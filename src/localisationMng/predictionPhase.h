/*
    * kNN.h
    *
    * Created on: 2023.10.01
    * @author: Ward Iraqi
    * @brief: Header file for kNN algorithm implementation.
    * This file contains the function declarations and constants used in the kNN algorithm.
    * The kNN algorithm is used for predicting the location based on RSSI values.
*/

#ifndef IOT_INDOOR_LOCALISATION_kNN_H
#define IOT_INDOOR_LOCALISATION_kNN_H

#include <Arduino.h>
#include <math.h>
#include <WiFi.h>
#include "utillities.h"

/*
    * @param input: sample array of RSSI values
    * @return: predicted location
*/
LOCATIONS knnPredict(const int input[NUMBER_OF_ANCHORS]);

#endif