#ifndef SENSORMANAGER_H_NANO
#define SENSORMANAGER_H_NANO

#include "sensor/SensorInterface.h"
#include "sensor/SensorManagerInterface.h"
#include "sensor/SensorTypes.h"

#include "SensorID_Nano.h"
#include "APDS_Sensor_Nano.h"
#include "BARO_Sensor_Nano.h"
#include "HTS_Sensor_Nano.h"
#include "IMU_Sensor_Nano.h"

class SensorManager_Nano : public SensorManagerInterface {
public:
    void setup() override;
};

#endif //SENSORMANAGER_H_NANO
