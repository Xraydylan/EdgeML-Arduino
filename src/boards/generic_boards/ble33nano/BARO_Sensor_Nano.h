#ifndef BARO_SENSOR_H_NANO
#define BARO_SENSOR_H_NANO


class BARO_Sensor_Nano {
public:
    BARO_Sensor_Nano();
    void start();
    void end();

    float get_pressure();

    const int sensor_count = 1;
private:
    bool available = false;
};

#endif //BARO_SENSOR_H_NANO
