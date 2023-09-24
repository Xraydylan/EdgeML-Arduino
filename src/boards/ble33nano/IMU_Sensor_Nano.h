#ifndef EDGEML_ARDUINO_IMU_SENSOR_NANO_H
#define EDGEML_ARDUINO_IMU_SENSOR_NANO_H

#include <Arduino_LSM9DS1.h>
#include "sensor/SensorInterface.h"
#include "SensorID_Nano.h"

class IMU_Sensor_Nano: public SensorInterface {
public:
    void start() override;
    void end() override;

    void get_data(int sensorID, byte data[]) override;

    int get_sensor_count() override;

    const int sensor_count = 3;

    void get_acc(float& x, float& y, float& z);
    void get_gyro(float& x, float& y, float& z);
    void get_mag(float& x, float& y, float& z);
private:
    bool available = false;
};

#endif //EDGEML_ARDUINO_IMU_SENSOR_NANO_H
