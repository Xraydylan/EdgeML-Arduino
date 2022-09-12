#ifndef MASTERFLAG
	#include "flags.h"
#endif

#ifndef BOARDFLAG
	#include "board_include.h"
#endif

#ifdef XIAO_SEEED_FLAG
	SensorManager_Seeed sensorManager;
	
#elif defined BLE33NANO_FLAG
	SensorManager_Nano sensorManager;
#else 
    #error Invalid board flag"
#endif
