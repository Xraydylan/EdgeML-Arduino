#ifndef EDGEML_ARDUINO_SENSORID_NICLA_H
#define EDGEML_ARDUINO_SENSORID_NICLA_H

#include "Arduino.h"
#include "sensor/SensorTypes.h"

const int SENSOR_COUNT_NICLA = 8;
const int MODULE_COUNT_PHYSICAL_NICLA = 8;

// In correct order ID ascending
enum SensorID_NICLA {
    IMU_ACC_NICLA,
    IMU_GYRO_NICLA,
    IMU_MAG_NICLA,
    IMU_ORI_NICLA,

    TEMP_NICLA,
    BARO_NICLA,
    HUMI_NICLA,
    GAS_NICLA
};

// In correct order ID ascending
enum ModuleID_Seeed {
    MODULE_IMU_ACC_NICLA,
    MODULE_IMU_GYRO_NICLA,
    MODULE_IMU_MAG_NICLA,
    MODULE_IMU_ORI_NICLA,

    MODULE_TEMP_NICLA,
    MODULE_BARO_NICLA,
    MODULE_HUMI_NICLA,
    MODULE_GAS_NICLA
};

const SensorComponent ACC_COMPONENTS_Nicla[] = {
        {"ACC", PARSE_TYPE_INT16, "X", ""},
        {"ACC", PARSE_TYPE_INT16, "Y", ""},
        {"ACC", PARSE_TYPE_INT16, "Z", ""}
};

const SensorComponent GYRO_COMPONENTS_Nicla[] = {
        {"GYRO", PARSE_TYPE_INT16, "X",""},
        {"GYRO", PARSE_TYPE_INT16, "Y",""},
        {"GYRO", PARSE_TYPE_INT16, "Z",""}
};

const SensorComponent MAG_COMPONENTS_Nicla[] = {
        {"MAG", PARSE_TYPE_INT16, "X",""},
        {"MAG", PARSE_TYPE_INT16, "Y",""},
        {"MAG", PARSE_TYPE_INT16, "Z",""}
};

const SensorComponent ORI_COMPONENTS_Nicla[] = {
        {"ORI", PARSE_TYPE_FLOAT, "heading",""},
        {"ORI", PARSE_TYPE_FLOAT, "pitch",""},
        {"ORI", PARSE_TYPE_FLOAT, "roll",""}
};

const SensorComponent TEMP_COMPONENTS_Nicla[] = {
        {"TEMP", PARSE_TYPE_FLOAT, "Temperature", "°C"}
};

const SensorComponent BARO_COMPONENTS_Nicla[] = {
        {"BARO", PARSE_TYPE_FLOAT, "Pressure", "kPa"}
};

const SensorComponent HUMI_COMPONENTS_Nicla[] = {
        {"HUMI", PARSE_TYPE_FLOAT, "Humidity", "%"}
};

const SensorComponent GAS_COMPONENTS_Nicla[] = {
        {"GAS", PARSE_TYPE_FLOAT, "Gas", ""}
};

const EdgeSensorConfig CONFIG_NICLA[SENSOR_COUNT_NICLA] = {
        {
                "ACC",
                IMU_ACC_NICLA,
                MODULE_IMU_ACC_NICLA,
                3,
                ACC_COMPONENTS_Nicla
        },
        {
                "GYRO",
                IMU_GYRO_NICLA,
                MODULE_IMU_GYRO_NICLA,
                3,
                GYRO_COMPONENTS_Nicla
        },
        {
                "MAG",
                IMU_MAG_NICLA,
                MODULE_IMU_MAG_NICLA,
                3,
                MAG_COMPONENTS_Nicla
        },
        {
                "ORIENTATION",
                IMU_ORI_NICLA,
                MODULE_IMU_ORI_NICLA,
                3,
                ORI_COMPONENTS_Nicla
        },
        {
                "TEMPERATURE",
                TEMP_NICLA,
                MODULE_TEMP_NICLA,
                1,
                TEMP_COMPONENTS_Nicla
        },
        {
                "BAROMETER",
                BARO_NICLA,
                MODULE_BARO_NICLA,
                1,
                BARO_COMPONENTS_Nicla
        },
        {
                "HYGROMETER",
                HUMI_NICLA,
                MODULE_HUMI_NICLA,
                1,
                HUMI_COMPONENTS_Nicla
        },
        {
                "GAS",
                GAS_NICLA,
                MODULE_GAS_NICLA,
                1,
                GAS_COMPONENTS_Nicla
        }
};

#endif //EDGEML_ARDUINO_SENSORID_NICLA_H
