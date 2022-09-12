#ifndef MASTERFLAG
	#include "flags.h"
#endif

#ifdef XIAO_SEEED_FLAG
    #define DEVICE_IDENTIFER "Seeed XIAO"
	#define DEVICE_GENERATION "1.0.0"
#elif defined BLE33NANO_FLAG
    #define DEVICE_IDENTIFER "Nano"
	#define DEVICE_GENERATION "1.0.0"
#else 
	#warning "Default BLE config"
    #define DEVICE_IDENTIFER "Generic"
	#define DEVICE_GENERATION "0.0.0"
#endif