#if defined(ARDUINO_NICLA)
#include "SensorManager_Nicla.h"



void SensorManager_Nicla::setup() {
    edge_ml_generic.ble_manual_advertise();
    BHY2.begin(NICLA_STANDALONE);

    ACC_Sensor_Nicla * acc = new ACC_Sensor_Nicla();
    GYRO_Sensor_Nicla * gyro = new GYRO_Sensor_Nicla();
    MAG_Sensor_Nicla * mag = new MAG_Sensor_Nicla();
    ORI_Sensor_Nicla * ori = new ORI_Sensor_Nicla();

    TEMP_Sensor_Nicla * temp = new TEMP_Sensor_Nicla();
    BARO_Sensor_Nicla * baro = new BARO_Sensor_Nicla();
    HUMI_Sensor_Nicla * humi = new HUMI_Sensor_Nicla();
    GAS_Sensor_Nicla * gas = new GAS_Sensor_Nicla();

    SensorInterface ** modules = new SensorInterface * [MODULE_COUNT_PHYSICAL_NICLA] {
            (acc),
            (gyro),
            (mag),
            (ori),
            (temp),
            (baro),
            (humi),
            (gas)
    };

    SensorManagerInterface::set_modules(modules);
    SensorManagerInterface::set_sensor_counts(SENSOR_COUNT_NICLA, MODULE_COUNT_PHYSICAL_NICLA);

    SensorManagerInterface::set_sensor_configs(CONFIG_NICLA);
}

void SensorManager_Nicla::begin() {


    BLE.advertise();
}

void SensorManager_Nicla::update() {
    BHY2.update();
}

#endif


