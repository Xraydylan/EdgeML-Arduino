#ifndef IMU_SENSOR_H_NANO
#define IMU_SENSOR_H_NANO

class IMU_Sensor_Nano {
public:
    IMU_Sensor_Nano();
    void start();
    void end();

    void get_acc(float& x, float& y, float& z);
    void get_gyro(float& x, float& y, float& z);
    void get_mag(float& x, float& y, float& z);

    const int sensor_count = 3;

private:
    bool available = false;
};

#endif //IMU_SENSOR_H_NANO
