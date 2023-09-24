#if defined(ARDUINO_NICLA)
#include "TEMP_Sensor_Nicla.h"

Sensor temperature(SENSOR_ID_TEMP);

void TEMP_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (temperature.begin()) {
        available = true;
    }
}

void TEMP_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    temperature.end();
    available = false;
}

void TEMP_Sensor_Nicla::get_data(int sensorID, byte *data) {
    float val;
    switch (sensorID) {
        case TEMP_NICLA:
            val = temperature.value();
            break;
        default:
            break;
    }

    float * floatArray = (float*)data;
    floatArray[0] = val;
}

int TEMP_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif