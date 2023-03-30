#include <iostream>
#include <unistd.h>
#include <chrono>
#include "vib.h"

using namespace std::chrono;

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
