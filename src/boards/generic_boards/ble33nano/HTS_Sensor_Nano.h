#ifndef HTS_SENSOR_H_NANO
#define HTS_SENSOR_H_NANO


class HTS_Sensor_Nano {
public:
    HTS_Sensor_Nano();
    void start();
    void end();

    float get_temperature();
    float get_humidity();

    const int sensor_count = 2;
private:
    bool available = false;
};

#endif //HTS_SENSOR_H_NANO
