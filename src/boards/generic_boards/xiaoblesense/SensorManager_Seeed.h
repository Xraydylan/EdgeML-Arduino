#ifndef SENSORMANAGER_SEEED_H
#define SENSORMANAGER_SEEED_H

#include "Arduino.h"

#include <boards/generic_boards/SensorTypes.h>
#include "SensorID_Seeed.h"
#include "IMU_Sensor_Seeed.h"

class SensorManager_Seeed {
public:
    SensorManager_Seeed();

    void start_sensor(int ID);
    void end_sensor(int ID);

    int * get_int_data(int ID);
    float * get_float_data(int ID);
	
	int get_int_type();
	int get_float_type();
	int get_int_type_count();
	int get_float_type_count();
	const int * get_return_type_int();
	const int * get_return_type_float();

    // Add additional methods

    void debug(Stream &stream);

private:
    Stream *_debug{};
    ModuleActive active[MODULE_COUNT_PHYSICAL_SEEED]{};
    int module_assignment[SENSOR_COUNT]{};
    int sensor_module_pos[SENSOR_COUNT]{};

    void init_act_map(ModuleActive& act, const int *MAP);
    void init_assignment(const int ID, int MODULE);
    void init_sensor_module_pos(int length, const int *MAP);
    void activate_pos(int module, int pos);
    void deactivate_pos(int module, int pos);
    bool all_inactive(int module, int pos);
};

#endif //SENSORMANAGER_SEEED_H
