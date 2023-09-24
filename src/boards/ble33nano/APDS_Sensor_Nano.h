#ifndef APDS_Sensor_H_NANO
#define APDS_Sensor_H_NANO

#include <Arduino_APDS9960.h>
#include "sensor/SensorInterface.h"
#include "SensorID_Nano.h"

class APDS_Sensor_Nano: public SensorInterface {
public:
    void start() override;
    void end() override;

    void get_data(int sensorID, byte *data) override;

    int get_sensor_count() override;

    void get_color(int& r, int& g, int& b);
    int get_light();
    int get_proximity();
    int get_gesture();

    const int sensor_count = 4;

private:
    bool available = false;
};


#endif //APDS_Sensor_H_NANO
