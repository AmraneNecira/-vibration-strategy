#include <iostream>
#include <unistd.h>
#include <chrono>
#include "vib.h"
#include "matrix_hal/gpio_control.h"
#include "matrix_hal/matrixio_bus.h"

using namespace std::chrono;

/**GPIO setup*/
const uint16_t GPIOOutputMode = 1;
matrix_hal::GPIOControl gpio;
uint16_t pin_out ;

/**Vibrator Selector*/
//TODO: Which Vibrator Vibs!

/**Vib Function */
void vib(uint16_t pin_out, float level){
    int limit = (int) NbrVibSeg(level)-1;
    auto start = high_resolution_clock::now();
    gpio.SetMode(pin_out, GPIOOutputMode);// set pin_out mode to 1 

    for (int i = 0; i < TOTAL_SEG; ++i) {
        if (i <= limit ){
            gpio.SetGPIOValue(pin_out,1);
            printf("ON for itr %d with level %f vibrator %d\n", i, level, pin_out);
            usleep(SEG_SIZE);
        }
        else {
            gpio.SetGPIOValue(pin_out,0);
            printf("OFF for itr %d \n", i);
            usleep(SEG_SIZE);
        }
    }
    gpio.SetGPIOValue(pin_out,0);// to make sure the vibrator is off
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
}

int main() {
    // Hardware Communication through the matrix GPIO
    matrix_hal::MatrixIOBus bus;
    if (!bus.Init()) return false;
    gpio.Setup(&bus);
    
    // Pin out number
    std::cout << "Select pin_out from [0-15]: ";
    std::cin >> pin_out;

    // input the level
    float niv;
    
    while (true) {
        std::cout << "Select Level of vibration: ";
        std::cin >> niv;
        std::cout << "total segments " << TOTAL_SEG << std::endl;
        std::cout << "Nbr of Vib. segments : " << NbrVibSeg(niv) << std::endl;
        vib(pin_out, adjustLevel(niv));
    }
}
