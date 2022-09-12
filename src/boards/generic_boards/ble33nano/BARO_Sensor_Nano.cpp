#include "BARO_Sensor_Nano.h"
#include <Arduino_LPS22HB.h>

BARO_Sensor_Nano::BARO_Sensor_Nano() {

}

void BARO_Sensor_Nano::start() {
    if (BARO.begin()) {
        available = true;
    }
}

void BARO_Sensor_Nano::end() {
    BARO.end();
    available = false;
}

float BARO_Sensor_Nano::get_pressure() {
    if (!available) {
        return 0.0;
    }

    return BARO.readPressure();
}