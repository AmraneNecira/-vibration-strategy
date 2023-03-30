//
// Created by Amrane Necira on 3/30/2023.
//

#ifndef DEFAULT_STRATEGY_V2_VIB_H
#define DEFAULT_STRATEGY_V2_VIB_H

#include <iostream>
#include <unistd.h>
#include <chrono>

// Variables
//main levels
const float MAX_VIBRATION = 100;
float level_100 = MAX_VIBRATION;
float level_75 = 75*MAX_VIBRATION/100;
float level_50 = 50*MAX_VIBRATION/100;
float level_25 = 25*MAX_VIBRATION/100;

const int VIB_SIZE = 800*1000;// 8ms
const int SEG_SIZE = 200*1000;// 2ms
const int TOTAL_SEG = (int) VIB_SIZE/SEG_SIZE;// 4 Segments
float nbr_vib_segments;

//Functions
/**Number of Vib Segments*/
float NbrVibSeg(float level){
    level = level/MAX_VIBRATION;
    nbr_vib_segments = VIB_SIZE*level/SEG_SIZE;
    return nbr_vib_segments;
}

/** Adjust Level to 100% 75% 50% 25% */
float adjustLevel(float level){
    if (level > level_75){
        // 100%
        printf("vib with 100\n");
        return level_100;
    }
    else if (level > level_50){
        // 75%
        printf("vib with 75\n");
        return level_75;
    }
    else if (level > level_25){
        // 50%
        printf("vib with 50\n");
        return level_50;
    }
    else if (level > 0){
        // 25%
        printf("vib with 25\n");
        return level_25;
    }
    else{
        return 0;}
}

#endif //DEFAULT_STRATEGY_V2_VIB_H
