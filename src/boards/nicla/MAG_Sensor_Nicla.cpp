#if defined(ARDUINO_NICLA)
#include "MAG_Sensor_Nicla.h"

SensorXYZ magnetometer(SENSOR_ID_MAG);

void MAG_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (magnetometer.begin()) {
        available = true;
    }
}

void MAG_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    magnetometer.end();
    available = false;
}

void MAG_Sensor_Nicla::get_data(int sensorID, byte *data) {
    short x, y, z;
    switch (sensorID) {
        case IMU_MAG_NICLA:
            get_mag(x,y,z);
            break;
        default:
            break;
    }

    short * floatArray = (short*)data;
    floatArray[0] = x;
    floatArray[1] = y;
    floatArray[2] = z;
}

void MAG_Sensor_Nicla::get_mag(short &x, short &y, short &z) {
    if (!available) {
        return;
    }

    x = magnetometer.x();
    y = magnetometer.y();
    z = magnetometer.z();
}

int MAG_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
