#if defined(ARDUINO_NICLA)
#ifndef NICLA_TEST_HUMI_SENSOR_NICLA_H
#define NICLA_TEST_HUMI_SENSOR_NICLA_H

#include "Arduino_BHY2.h"
#include "sensor/SensorInterface.h"
#include "SensorID_Nicla.h"

extern Sensor hygrometer;

class HUMI_Sensor_Nicla: public SensorInterface {
public:
    void start() override;
    void end() override;

    void get_data(int sensorID, byte *data) override;

    int get_sensor_count() override;

    const int sensor_count = 1;
private:
    bool available = false;
};

#endif //NICLA_TEST_HUMI_SENSOR_NICLA_H
#endif
