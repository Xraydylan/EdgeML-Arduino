#ifndef SENSORMANAGER_SEEED_H
#define SENSORMANAGER_SEEED_H

#include "Arduino.h"

#include "sensor/SensorInterface.h"
#include "sensor/SensorManagerInterface.h"
#include "sensor/SensorTypes.h"

#include "SensorID_Seeed.h"
#include "IMU_Sensor_Seeed.h"

class SensorManager_Seeed : public SensorManagerInterface {
public:
    void setup() override;
};

#endif //SENSORMANAGER_SEEED_H
