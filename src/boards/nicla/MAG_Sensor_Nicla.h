#if defined(ARDUINO_NICLA)
#ifndef NICLA_TEST_MAG_SENSOR_NICLA_H
#define NICLA_TEST_MAG_SENSOR_NICLA_H

#include "Arduino_BHY2.h"
#include "sensor/SensorInterface.h"
#include "SensorID_Nicla.h"

extern SensorXYZ magnetometer;

class MAG_Sensor_Nicla: public SensorInterface {
public:
    void start() override;
    void end() override;

    void get_data(int sensorID, byte *data) override;

    int get_sensor_count() override;

    void get_mag(short& x, short& y, short& z);

    const int sensor_count = 1;
private:
    bool available = false;
};


#endif //NICLA_TEST_MAG_SENSOR_NICLA_H
#endif
