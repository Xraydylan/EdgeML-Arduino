#if defined(ARDUINO_NICLA)
#include "GAS_Sensor_Nicla.h"

Sensor gas_detector(SENSOR_ID_GAS);

void GAS_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (gas_detector.begin()) {
        available = true;
    }
}

void GAS_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    gas_detector.end();
    available = false;
}

void GAS_Sensor_Nicla::get_data(int sensorID, byte *data) {
    float val;
    switch (sensorID) {
        case GAS_NICLA:
            val = gas_detector.value();
            break;
        default:
            break;
    }

    float * floatArray = (float*)data;
    floatArray[0] = val;
}

int GAS_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
