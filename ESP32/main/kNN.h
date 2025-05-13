/*
    * kNN.h
    *
    * Created on: 2023.10.01
    * @author: Ward Iraqi
    * @brief: Header file for kNN algorithm implementation.
    * This file contains the function declarations and constants used in the kNN algorithm.
    * The kNN algorithm is used for predicting the location based on RSSI values.
*/

#include "utillities.h"
#include "etl/vector.h"
#include <math.h>

/*
    * @param input: sample array of RSSI values
    * @return: predicted location
*/
LOCATIONS knnPredict(const int input[num_of_anchors]);
