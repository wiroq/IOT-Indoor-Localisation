/*
 * @file utillities.h
 * @brief Final version with only constants, enums, data structures, and API declarations.
 */

#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <vector>

// =================== Constants ===================
#define SCANS_PER_LOCATION (20)
#define SAMPLES_PER_SCAN (5)
#define SCAN_DELAY_MS (150)
#define ALPHA (0.7f)
#define NUMBER_OF_ANCHORS (6)
#define NUMBER_OF_EXTRA_APS (0)  // For techpublic
#define TOTAL_APS (NUMBER_OF_ANCHORS + NUMBER_OF_EXTRA_APS)
#define NUMBER_OF_LOCATIONS (12)  // 6 main locations + 6 near locations

//Just for KNN use
#define K (3)

// =================== Enums ===================

const char* anchorSSIDs[TOTAL_APS] = {
        "ANCHOR_LOBBY",
        "ANCHOR_PRINTER",
        "ANCHOR_HALL_ENTRANCE",
        "ANCHOR_SECOND_HALL_ENTRY", " ANCHOR_SECOND_HALL_MID ", "ANCHOR_SECOND_HALL_END",
};

enum LOCATIONS {
    ROOM_201 = 0,
    ROOM_231 = 1,
    ROOM_236 = 2,
    LOBBY = 3,
    PRINTER_AREA = 4,
    NEAR_ELEVATOR = 5,
    NEAR_ROOM_201 = 6,
    NEAR_ROOM_231 = 7,
    NEAR_ROOM_236 = 8,
    NEAR_LOBBY = 9,
    NEAR_PRINTER_AREA = 10,
    NEAR_ELEVATOR_AREA = 11
};

// =================== Data Structures ===================

struct Data {
    int RSSIs[TOTAL_APS];
    LOCATIONS location;
};

// =================== Data Set Vector ===================
etl::vector<Data, NUMBER_OF_SCANS> dataSet;

#endif // _UTILITIES_H_
