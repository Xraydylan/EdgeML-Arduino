#include "SensorManager_Seeed.h"

IMU_Sensor_Seeed imu_sensor_seeed;


SensorManager_Seeed::SensorManager_Seeed() {
    ModuleActive act{};
    for (int i=0; i < MODULE_COUNT_PHYSICAL_SEEED; i++) {
        act = active[i];

        for (int u=0; u < ModuleActive_BUF; u++) {
            act.active[u] = false;
        }

        act.module = i;

        switch (i) {
            case MODULE_IMU_SEEED : {
                act.count = imu_sensor_seeed.sensor_count;
                init_act_map(act, IMU_MAP_SEEED);
                init_sensor_module_pos(act.count, IMU_MAP_SEEED);
                break;
            }
            default: {
                break;
            }
        }
    }
}

void SensorManager_Seeed::start_sensor(int ID) {
    // Start sensor
    if (_debug) {
        _debug->print("Starting Sensor: ");
        _debug->println(ID);
    }
    int pos = sensor_module_pos[ID];
    int module = module_assignment[ID];

    switch(ID) {
        case IMU_ACCELERATION_SEEED : {
            activate_pos(module, pos);
            imu_sensor_seeed.start();
            break;
        }
        case IMU_GYROSCOPE_SEEED : {
            activate_pos(module, pos);
            imu_sensor_seeed.start();
            break;
        }
        case IMU_TEMP_SEEED : {
            activate_pos(module, pos);
            imu_sensor_seeed.start();
            break;
        }
        default:
            break;
    }
}

void SensorManager_Seeed::end_sensor(int ID) {
    // End sensor
    int pos = sensor_module_pos[ID];
    int module = module_assignment[ID];

    switch(ID) {
        case IMU_ACCELERATION_SEEED : {
            deactivate_pos(module, pos);
            if (all_inactive(module, pos)) {
                imu_sensor_seeed.end();
            }
            break;
        }
        case IMU_GYROSCOPE_SEEED : {
            deactivate_pos(module, pos);
            if (all_inactive(module, pos)) {
                imu_sensor_seeed.end();
            }
            break;
        }
        case IMU_TEMP_SEEED : {
            deactivate_pos(module, pos);
            if (all_inactive(module, pos)) {
                imu_sensor_seeed.end();
            }
            break;
        }
        default:
            break;
    }
}

int * SensorManager_Seeed::get_int_data(int ID) {
    int* data = new int[4];

    switch(ID) {
        // No Sensors
    }
    return data;
}

float * SensorManager_Seeed::get_float_data(int ID){
    float* data = new float[4];

    switch(ID) {
        case IMU_ACCELERATION_SEEED : {
            data[0] = 3;
            float x,y,z;
            imu_sensor_seeed.get_acc(x, y, z);
            data[1] = x;
            data[2] = y;
            data[3] = z;
            break;
        }
        case IMU_GYROSCOPE_SEEED : {
            data[0] = 3;
            float x,y,z;
            imu_sensor_seeed.get_gyro(x, y, z);
            data[1] = x;
            data[2] = y;
            data[3] = z;
            break;
        }
        case IMU_TEMP_SEEED : {
            data[0] = 1;
            float C;
            imu_sensor_seeed.get_temp(C);
            data[1] = C;
            break;
        }
        default:
            break;
    }

    return data;
}

void SensorManager_Seeed::init_act_map(ModuleActive& act, const int *MAP) {
    for (int i=0; i < act.count; i++) {
        act.map[i] = MAP[i];
        init_assignment(MAP[i], act.module);
    }
}

void SensorManager_Seeed::init_assignment(const int ID, int MODULE) {
    module_assignment[ID] = MODULE;
}

void SensorManager_Seeed::init_sensor_module_pos(int length, const int *MAP) {
    for (int i=0; i<length; i++) {
        sensor_module_pos[MAP[i]] = i;
    }
}

void SensorManager_Seeed::activate_pos(int module, int pos) {
    ModuleActive act;
    act = active[module];
    act.active[pos] = true;
}

void SensorManager_Seeed::deactivate_pos(int module, int pos) {
    ModuleActive act;
    act = active[module];
    act.active[pos] = false;
}

bool SensorManager_Seeed::all_inactive(int module, int pos) {
    ModuleActive act = active[module];
    for (int i=0; i < act.count; i++) {
        if (act.active[pos]) {
            return false;
        }
    }
    return true;
}

int SensorManager_Seeed::get_int_type() {
	return TYPE_INT_SEEED;
}

int SensorManager_Seeed::get_float_type() {
	return TYPE_FLOAT_SEEED;
}

int SensorManager_Seeed::get_int_type_count() {
	return INT_TYPE_COUNT_SEEED;
}

int SensorManager_Seeed::get_float_type_count() {
	return FLOAT_TYPE_COUNT_SEEED;
}

const int * SensorManager_Seeed::get_return_type_int() {
	return RETURN_TYPE_INT_SEEED;
}

const int * SensorManager_Seeed::get_return_type_float() {
	return RETURN_TYPE_FLOAT_SEEED;
}

void SensorManager_Seeed::debug(Stream &stream)
{
    _debug = &stream;
}
