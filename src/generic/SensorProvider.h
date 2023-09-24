#ifndef SENSORPRIVDER_H
#define SENSORPRIVDER_H

#include "BLEHandler_G.h"
#include "Debug.h"

#include "sensor/SensorTypes.h"
#include "sensor/SensorManagerInterface.h"
#include "sensor/SensorInterface.h"

class SensorProvider: public Debug {
public:
    SensorProvider();
    ~SensorProvider();

    bool begin();
    void update();
    void configureSensor(EdgeSensorConfigurationPacket& config);

    void set_sensorManager(SensorManagerInterface * sensorManager);

    void set_data_callback(void(*)(int, unsigned int, uint8_t*, int));
    void set_config_callback(void(*)(EdgeSensorConfigurationPacket *));
    void set_update_callback(void(*)());

    int get_active();

    String parse_to_string(int sensorID, const byte *data);

    void debug(Stream &stream);

private:
    SensorManagerInterface * _sensorManager;
    EdgeSensor ** _sensor_array;
    int _sensor_count;
    int _active_count;

    uint8_t * _data_buffer = nullptr;

    const int _meta_data_size = 1 + 4; // 2 + 4;

    void update_sensor(EdgeSensor * sensor);
    void check_sensor(EdgeSensor * sensor);
    void send_sensor_data(int ID);

    bool check_valid_id(int ID);
    void (*_data_callback)(int ID, unsigned int timestamp, uint8_t * data, int size) = nullptr;
    void (*_config_callback)(EdgeSensorConfigurationPacket * config) = nullptr;
};

extern SensorProvider sensorProvider;

#endif //SENSORPRIVDER_H
