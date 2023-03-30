#include <iostream>
#include <unistd.h>
#include <chrono>

using namespace std::chrono;
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
}

/**Vib Function */
void vib(float level){
    int limit = (int) NbrVibSeg(level)-1;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < TOTAL_SEG; ++i) {
        if (i <= limit ){
            printf("ON for itr %d with level %f\n", i, level);
            usleep(SEG_SIZE);
        }
        else {
            printf("OFF for itr %d \n", i);
            usleep(SEG_SIZE);
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
}

int main() {
    float niv;
    // input the level
    while (true) {
        std::cout << "Select Level of vibration: ";
        std::cin >> niv;

        std::cout << "total segments " << TOTAL_SEG << std::endl;
        std::cout << "Nbr of Vib. segments : " << NbrVibSeg(niv) << std::endl;
        vib(adjustLevel(niv));
    }
}
