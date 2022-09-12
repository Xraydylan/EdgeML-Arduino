#include "IMU_Sensor_Nano.h"
#include <Arduino_LSM9DS1.h>

IMU_Sensor_Nano::IMU_Sensor_Nano() {
}

void IMU_Sensor_Nano::start() {
    if (available) {
        return;
    }
    if (IMU.begin()) {
        available = true;
    }
}

void IMU_Sensor_Nano::end() {
    if (!available) {
        return;
    }
    IMU.end();
    available = false;
}

void IMU_Sensor_Nano::get_acc(float& x, float& y, float& z) {
    // [-4, +4]g -/+0.122 mg
    if (!available) {
        return;
    }

    IMU.readAcceleration(x, y, z);
}

void IMU_Sensor_Nano::get_gyro(float& x, float& y, float& z) {
    // [-2000, +2000] dps +/-70 mdps
    if (!available) {
        return;
    }
    IMU.readGyroscope(x, y, z);
}

void IMU_Sensor_Nano::get_mag(float& x, float& y, float& z) {
    // [-400, +400] uT +/-0.014 uT
    if (!available) {
        return;
    }
    IMU.readMagneticField(x, y, z);
}
