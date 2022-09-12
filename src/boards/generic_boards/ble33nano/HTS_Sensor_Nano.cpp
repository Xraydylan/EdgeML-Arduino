#include "HTS_Sensor_Nano.h"
#include <Arduino_HTS221.h>

HTS_Sensor_Nano::HTS_Sensor_Nano() {

}

void HTS_Sensor_Nano::start() {
    if (HTS.begin()) {
        available = true;
    }
}

void HTS_Sensor_Nano::end() {
    HTS.end();
    available = false;
}

float HTS_Sensor_Nano::get_temperature() {
    if (!available) {
        return 0.0;
    }

    // -5 correction from original code
    return HTS.readTemperature()-5;
}

float HTS_Sensor_Nano::get_humidity(){
    if (!available) {
        return 0.0;
    }

    return HTS.readHumidity();
}