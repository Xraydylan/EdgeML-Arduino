#if defined(ARDUINO_NICLA)
#include "HUMI_Sensor_Nicla.h"

Sensor hygrometer(SENSOR_ID_HUM);

void HUMI_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (hygrometer.begin()) {
        available = true;
    }
}

void HUMI_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    hygrometer.end();
    available = false;
}

void HUMI_Sensor_Nicla::get_data(int sensorID, byte *data) {
    float val;
    switch (sensorID) {
        case HUMI_NICLA:
            val = hygrometer.value();
            break;
        default:
            break;
    }

    float * floatArray = (float*)data;
    floatArray[0] = val;
}

int HUMI_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
