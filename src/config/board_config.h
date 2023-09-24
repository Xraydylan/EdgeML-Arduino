#include "sensor/SensorManagerInterface.h"

#ifndef MASTERFLAG
#include "flags.h"
#endif


#ifdef XIAO_SEEED_FLAG
#include <boards/xiaoblesense/SensorManager_Seeed.h>
#include <boards/xiaoblesense/SensorID_Seeed.h>
#elif defined BLE33NANO_FLAG
#include <boards/ble33nano/SensorManager_Nano.h>
#include <boards/ble33nano/SensorID_Nano.h>
#elif defined NICLA_FLAG
#include <boards/nicla/SensorManager_Nicla.h>
#include <boards/nicla/SensorID_Nicla.h>
#else
#error "Invalid board flag"
#endif

SensorManagerInterface * get_manager();