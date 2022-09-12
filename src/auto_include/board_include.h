#define BOARDFLAG

#ifndef MASTERFLAG
	#include "flags.h"
#endif

#ifdef XIAO_SEEED_FLAG
    #include<boards/generic_boards/xiaoblesense/SensorManager_Seeed.h>
	#include<boards/generic_boards/xiaoblesense/SensorID_Seeed.h>
	extern SensorManager_Seeed sensorManager;
	
#elif defined BLE33NANO_FLAG
    #include<boards/generic_boards/ble33nano/SensorManager_Nano.h>
	#include<boards/generic_boards/ble33nano/SensorID_Nano.h>
	extern SensorManager_Nano sensorManager;
#else 
    #error Invalid board flag"
#endif
