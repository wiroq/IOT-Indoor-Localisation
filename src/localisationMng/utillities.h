/*
 * @file utillities.h
 * @brief Final version with only constants, enums, data structures, and API declarations.
 */

#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <vector>

// =================== Constants ===================
#define SCANS_PER_LOCATION (20)
#define SAMPLES_PER_SCAN (3)
#define SCAN_DELAY_MS (100)
#define ALPHA (0.7f)
#define NUMBER_OF_ANCHORS (10)
#define NUMBER_OF_EXTRA_APS (0)  // For techpublic
#define TOTAL_APS (NUMBER_OF_ANCHORS + NUMBER_OF_EXTRA_APS)
#define NUMBER_OF_LOCATIONS (17)  
#define NUMBER_OF_SCANS (SCANS_PER_LOCATION * NUMBER_OF_LOCATIONS)

//Just for KNN use
#define K (4)

extern const char* anchorSSIDs[TOTAL_APS];
#define SCAN_RESULTS_FILE     "/scan_results.csv"

// =================== Enums ===================


typedef enum LOCATIONS {
    NOT_ACCURATE          = 0,
    NEAR_ROOM_232         = 1,
    NEAR_ROOM_234         = 2,
    BETWEEN_ROOMS_234_236 = 3,
    ROOM_236              = 4,
    ROOM_231              = 5,
    BETWEEN_ROOMS_231_236 = 6,
    NEAR_BATHROOM         = 7,
    NEAR_KITCHEN          = 8,
    KITCHEN               = 9,
    MAIN_ENTRANCE         = 10,
    NEAR_ROOM_230         = 11,
    LOBBY                 = 12,
    ROOM_201              = 13,
    PRINTER               = 14,
    MAIN_EXIT             = 15,
    BALCONY_ENTRANCE      = 16,
    OFFICES_HALL          = 17
} LOCATIONS ;
 

// =================== Data Structures ===================

struct Data {
    int RSSIs[TOTAL_APS];
    LOCATIONS location;
    int timestamp;

};

// =================== Data Set Vector ===================
extern std::vector<Data> dataSet;

#endif // _UTILITIES_H_
