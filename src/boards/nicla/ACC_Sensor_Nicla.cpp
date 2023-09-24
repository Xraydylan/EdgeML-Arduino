#if defined(ARDUINO_NICLA)
#include "ACC_Sensor_Nicla.h"

SensorXYZ accelerometer(SENSOR_ID_ACC);

void ACC_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (accelerometer.begin()) {
        available = true;
    }
}

void ACC_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    accelerometer.end();
    available = false;
}

void ACC_Sensor_Nicla::get_data(int sensorID, byte *data) {
    short x, y, z;
    switch (sensorID) {
        case IMU_ACC_NICLA:
            get_acc(x,y,z);
            break;
        default:
            break;
    }

    short * floatArray = (short*)data;
    floatArray[0] = x;
    floatArray[1] = y;
    floatArray[2] = z;
}

void ACC_Sensor_Nicla::get_acc(short &x, short &y, short &z) {
    if (!available) {
        return;
    }

    x = accelerometer.x();
    y = accelerometer.y();
    z = accelerometer.z();
}

int ACC_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
