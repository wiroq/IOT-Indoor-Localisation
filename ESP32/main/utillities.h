/*
    * @file utillities.h
    * @brief Header file containing constants and structures for the localization system.
    * 
    * This file defines the number of anchors, locations, and a structure to hold RSSI values
    * and their corresponding labels. It is used in the localization system to manage data.
    *
    * @date 2025-5-13
    * @author Ward Iraqi
*/

#ifndef _UTIILITIES_H_
#define _UTIILITIES_H_

#define SCANS_PER_LOCATION (20)
#define NUMBER_OF_SCANS (SCANS_PER_LOCATION * NUMBER_OF_LOCATIONS)

enum ANCHORS
{
    ANCHOR_1 = 0,
    ANCHOR_2 = 1,
    ANCHOR_3 = 2,
    NUMBER_OF_ANCHORS = 3
};

enum LOCATIONS
{
    ROOM_1 = 0,
    ROOM_2 = 1,
    ROOM_3 = 2,
    NEXT_TO_ROOM_1 = 3,
    NEXT_TO_ROOM_2 = 4,
    NEXT_TO_ROOM_3 = 5,
    NUMBER_OF_LOCATIONS = 6
};

struct Data
{
    int RSSIs[NUMBER_OF_ANCHORS];
    LOCATIONS location;
};

#endif // _UTIILITIES_H_
