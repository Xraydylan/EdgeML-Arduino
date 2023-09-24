#ifndef EDGEML_ARDUINO_SENSORMANAGERINTERFACE_H
#define EDGEML_ARDUINO_SENSORMANAGERINTERFACE_H

#include "Arduino.h"

#include "SensorInterface.h"
#include "SensorTypes.h"

#include "generic/Debug.h"

class SensorManagerInterface : public Debug {
public:
    SensorManagerInterface();
    virtual ~SensorManagerInterface();

    virtual void begin() {};
    virtual void update() {};

    void init();

    int get_sensor_count();
    EdgeSensor ** get_sensors();
    int get_max_data_size();

    void start_sensor(int ID);
    void end_sensor(int ID);

    // data arrays must be 4 elements long (or longer)
    void get_data(int sensorID, byte *data);

    byte * get_parse_scheme(int &length);

    bool check_special_sensor(int ID);

    EdgeSensorConfig * get_config(int ID);

protected:
    virtual void setup() {};

    void set_modules(SensorInterface ** modules);
    void set_sensor_counts(int sensor_count, int module_count);
    void set_sensor_configs(const EdgeSensorConfig * configurations);
    void set_special_sensors(const int * special_ids, int special_count);

private:
    int _sensor_count = -1;
    int _module_count = -1;

    const int * _special_ids;
    int _special_count = 0;

    const EdgeSensorConfig * _configs;
    EdgeSensor ** _sensors;  // ID -> EdgeSensor
    SensorInterface ** _sensor_modules; // Module ID -> SensorInterface (Pointer to array of pointers)

    int * _sensor_module_pos;  // ID -> Module Position
    const EdgeSensorConfig ** _config_id_index; // Index (ID) -> EdgeSensorConfig pointer (ID ascending)

    int _scheme_length = 0;
    byte * _scheme_buffer = nullptr;

    int _max_data_size = 0;

    void setup_ID_arrays();
    void setup_sensors();
    void setup_scheme_buffer();

    int calculate_size(int ID);

    SensorInterface * get_module(int ID);
    bool all_inactive(SensorInterface * sensor);
};

#endif //EDGEML_ARDUINO_SENSORMANAGERINTERFACE_H
