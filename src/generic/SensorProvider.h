#ifndef SENSORPRIVDER_H
#define SENSORPRIVDER_H

#include <boards/generic_boards/SensorTypes.h>
#include <auto_include/board_include.h>
#include "BLEHandler_G.h"

class SensorProvider {
public:
    SensorProvider();

    bool begin();
    void update();
    void configureSensor(SensorConfigurationPacket& config);

    // Add additional methods

    void debug(Stream &stream);

private:
    Sensor sensors[SENSOR_COUNT];
    int ID_type_assignment[SENSOR_COUNT];

    Stream *_debug;
    void init_ID_type_assignment();
    void update_sensor(Sensor &sens);
    void send_sensor_data(int ID);
	
	int _type_int;
	int _type_float;

	int _int_type_count;
	int _float_type_count;

	const int * _return_type_int;
	const int * _return_type_float;
};

extern SensorProvider sensorProvider;

#endif //SENSORPRIVDER_H
