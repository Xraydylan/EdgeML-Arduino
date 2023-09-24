#if defined(ARDUINO_NICLA)
#include "ORI_Sensor_Nicla.h"

SensorOrientation orientation(SENSOR_ID_ORI);

void ORI_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (orientation.begin()) {
        available = true;
    }
}

void ORI_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    orientation.end();
    available = false;
}

void ORI_Sensor_Nicla::get_data(int sensorID, byte *data) {
    float heading, pitch, roll;
    switch (sensorID) {
        case IMU_ORI_NICLA:
            get_orientation(heading,pitch,roll);
            break;
        default:
            break;
    }

    float * floatArray = (float*)data;
    floatArray[0] = heading;
    floatArray[1] = pitch;
    floatArray[2] = roll;
}

void ORI_Sensor_Nicla::get_orientation(float &heading, float &pitch, float &roll) {
    if (!available) {
        return;
    }

    heading = orientation.heading();
    pitch = orientation.pitch();
    roll = orientation.roll();
}

int ORI_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
