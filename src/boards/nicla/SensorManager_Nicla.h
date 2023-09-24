#if defined(ARDUINO_NICLA)
#ifndef EDGEML_ARDUINO_SENSORMANAGER_NICLA_H
#define EDGEML_ARDUINO_SENSORMANAGER_NICLA_H

#include "Arduino.h"
#include "Arduino_BHY2.h"

#include "generic/Generic.h"
#include "sensor/SensorInterface.h"
#include "sensor/SensorManagerInterface.h"
#include "sensor/SensorTypes.h"

#include "DFU_Interface.h"

#include "ACC_Sensor_Nicla.h"
#include "GYRO_Sensor_Nicla.h"
#include "MAG_Sensor_Nicla.h"
#include "ORI_Sensor_Nicla.h"
#include "TEMP_Sensor_Nicla.h"
#include "BARO_Sensor_Nicla.h"
#include "HUMI_Sensor_Nicla.h"
#include "GAS_Sensor_Nicla.h"

class SensorManager_Nicla : public SensorManagerInterface {
public:
    void setup() override;
    void begin() override;
    void update() override;
private:

};

#endif //EDGEML_ARDUINO_SENSORMANAGER_NICLA_H
#endif
