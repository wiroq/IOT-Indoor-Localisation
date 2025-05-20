/*
    * kNN.h
    *
    * Created on: 2023.10.01
    * @author: Ward Iraqi
    * @brief: Header file for kNN algorithm implementation.
    * This file contains the function declarations and constants used in the kNN algorithm.
    * The kNN algorithm is used for predicting the location based on RSSI values.
*/

#ifndef _IOT_INDOOR_LOCALISATION_kNN_H_
#define _IOT_INDOOR_LOCALISATION_kNN_H_

#include <Arduino.h>
#include <math.h>
#include <WiFi.h>
#include "utillities.h"

/*
    * @brief Predicts the location using the kNN algorithm based on input RSSI values.
    * @param input: sample array of RSSI values
    * @return: predicted location
*/
LOCATIONS knnPredict(const double input[NUMBER_OF_ANCHORS]);

/*
    * @brief Prepares the RSSI data for prediction.
    * @param RSSIs: Array of RSSI values to be prepared.
*/
void preparePoint(double RSSIs[NUMBER_OF_ANCHORS]);

#endif // _IOT_INDOOR_LOCALISATION_kNN_H_