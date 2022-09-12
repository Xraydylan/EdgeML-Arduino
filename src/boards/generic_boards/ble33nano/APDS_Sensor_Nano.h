#ifndef APDS_Sensor_H_NANO
#define APDS_Sensor_H_NANO


class APDS_Sensor_Nano {
public:
    APDS_Sensor_Nano();
    void start();
    void end();

    void get_color(int& r, int& g, int& b);
    int get_light();
    int get_proximity();
    int get_gesture();

    const int sensor_count = 4;

private:
    bool available = false;
};


#endif //APDS_Sensor_H_NANO
