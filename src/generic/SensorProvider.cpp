#include "SensorProvider.h"

#include <auto_include/board_manager_include.h>

SensorProvider::SensorProvider() {
	_type_int = sensorManager.get_int_type();
	_type_float = sensorManager.get_float_type();
	
	_int_type_count = sensorManager.get_int_type_count();
	_float_type_count = sensorManager.get_float_type_count();

	_return_type_int = sensorManager.get_return_type_int();
	_return_type_float = sensorManager.get_return_type_float();
	
    init_ID_type_assignment();
}

bool SensorProvider::begin() {
    if (_debug) _debug->println("SensorProvider Begin");
    for (int i=0; i<SENSOR_COUNT; i++) {
        sensors[i].ID = i;
        sensors[i].state = false;
        sensors[i].active = false;
        sensors[i].delay = 0;
        sensors[i].last = -1;
    }
    return true;
}


void SensorProvider::update() {
    for (auto & sensor : sensors) {
        if (sensor.state) {
            update_sensor(sensor); // For Debug activation off
        } else if (sensor.active) {
            if (_debug) {
                _debug->print("Sensor deactivate:  ");
                _debug->println(sensor.ID);
            }
            //sensorManager.end_sensor(sensor.ID);
            sensor.active = false;
        }
    }
}

void SensorProvider::configureSensor(SensorConfigurationPacket& config) {
    // Configure sensor in SensorManager
    if (_debug) _debug->println("Reached Configuration");

    int ID = config.sensorId;

    if (_debug) {
        _debug->print("ID: ");
        _debug->println(ID);
    }

    if (config.sampleRate == 0.0) {
        sensors[ID].state = false;
        return;
    }

    float rate = config.sampleRate;

    int delay = (int)(1000.0/rate);
    sensors[ID].state = true;
    sensors[ID].delay = delay;
}

void SensorProvider::update_sensor(Sensor &sens) {
    if (!sens.active) {
        sensorManager.start_sensor(sens.ID);
        sens.active = true;
    }

    unsigned long now = millis();

    if (now - sens.last > sens.delay) {
        sens.last = now;
        send_sensor_data(sens.ID);
    }
}

void SensorProvider::send_sensor_data(int ID) {
    // Get data from SensorManager
    // Send data via BLE
    if (_debug) {
        _debug->print("Sending data ID:  ");
        _debug->println(ID);
    }

    int type = ID_type_assignment[ID];

    int *int_data;
    float *float_data;

    if (type == _type_int) {
        int_data = sensorManager.get_int_data(ID);
        bleHandler_G.send(ID, int_data);
        delete[] int_data;
    } else if (type == _type_float) {
        float_data = sensorManager.get_float_data(ID);
        bleHandler_G.send(ID, float_data);
        delete[] float_data;
    }
}

void SensorProvider::init_ID_type_assignment() {
    int ID;
    for (int i=0; i < _int_type_count; i++) {
        ID = _return_type_int[i];
        ID_type_assignment[ID] = _type_int;
    }

    for (int i=0; i < _float_type_count; i++) {
        ID = _return_type_float[i];
        ID_type_assignment[ID] = _type_float;
    }
}

void SensorProvider::debug(Stream &stream) {
    _debug = &stream;
    sensorManager.debug(stream);
}

SensorProvider sensorProvider;