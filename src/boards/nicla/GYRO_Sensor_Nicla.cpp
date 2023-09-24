#if defined(ARDUINO_NICLA)
#include "GYRO_Sensor_Nicla.h"

SensorXYZ gyroscope(SENSOR_ID_GYRO);

void GYRO_Sensor_Nicla::start() {
    if (available) {
        return;
    }
    if (gyroscope.begin()) {
        available = true;
    }
}

void GYRO_Sensor_Nicla::end() {
    if (!available) {
        return;
    }
    gyroscope.end();
    available = false;
}

void GYRO_Sensor_Nicla::get_data(int sensorID, byte *data) {
    short x, y, z;
    switch (sensorID) {
        case IMU_GYRO_NICLA:
            get_gyro(x,y,z);
            break;
        default:
            break;
    }

    short * floatArray = (short*)data;
    floatArray[0] = x;
    floatArray[1] = y;
    floatArray[2] = z;
}

void GYRO_Sensor_Nicla::get_gyro(short &x, short &y, short &z) {
    if (!available) {
        return;
    }

    x = gyroscope.x();
    y = gyroscope.y();
    z = gyroscope.z();
}

int GYRO_Sensor_Nicla::get_sensor_count() {
    return sensor_count;
}
#endif
