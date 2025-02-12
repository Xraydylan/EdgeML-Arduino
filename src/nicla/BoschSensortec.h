#if defined(ARDUINO_NICLA)

#ifndef BOSCH_SENSORTEC_H_
#define BOSCH_SENSORTEC_H_

#include "Arduino.h"
//#include "mbed.h"

#include "bosch/common/common.h"
#include "nicla/sensors/SensorTypes.h"


#define ARM_CM_DEMCR (*(uint32_t *)0xE000EDFC)
#define ARM_CM_DWT_CTRL (*(uint32_t *)0xE0001000)
#define ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)

#ifdef __cplusplus
extern "C"
{
#endif
#include "bosch/bhy2.h"
#ifdef __cplusplus
}
#endif

#define WORK_BUFFER_SIZE    1024

#define MAX_READ_WRITE_LEN 256

enum SensorAckCode {
  SensorAck = 0x0F,
  SensorNack = 0x00
};

class BoschSensortec {
public:
  BoschSensortec();
  virtual ~BoschSensortec();

  // sketch-side API
  bool begin(); 
  void update();
  void configureSensor(SensorConfigurationPacket& config);

  //uint8_t availableSensorData();
  //bool readSensorData(SensorDataPacket &data);

  // ANNA <-> BOSCH interface
  //void addSensorData(SensorDataPacket &sensorData);

  uint8_t acknowledgment();

private:
  //mbed::CircularBuffer<SensorDataPacket, SENSOR_QUEUE_SIZE, uint8_t> _sensorQueue;

  uint8_t _workBuffer[WORK_BUFFER_SIZE];
  uint8_t _acknowledgment;
  
  struct bhy2_dev _bhy2;
  uint8_t _sensorsPresent[32];

private:
  friend class Arduino_BHY2;
  void debug(Stream &stream);
  Stream *_debug;
};

extern BoschSensortec sensortec;

#endif

#endif