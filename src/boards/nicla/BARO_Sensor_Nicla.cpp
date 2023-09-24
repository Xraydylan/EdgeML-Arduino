#if defined(ARDUINO_NICLA)
#include "BARO_Sensor_Nicla.h"

Sensor barometer(SENSOR_ID_BARO);

void BARO_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (barometer.begin()) {
        available = true;
    }
}

void BARO_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    barometer.end();
    available = false;
}

void BARO_Sensor_Nicla::get_data(int sensorID, byte *data) {
    float val;
    switch (sensorID) {
        case BARO_NICLA:
            val = barometer.value();
            break;
        default:
            break;
    }

    float * floatArray = (float*)data;
    floatArray[0] = val;
}

int BARO_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
