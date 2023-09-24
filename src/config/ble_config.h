#ifndef MASTERFLAG
	#include "flags.h"
#endif

// when using custom board don't forget to change DEVICE_IDENTIFER and DEVICE_GENERATION

extern const char * sensorEdgeServiceUuid;
extern const char * sensorEdgeDataUuid;
extern const char * sensorEdgeConfigUuid;
extern const char * deviceInfoServiceUuid;
extern const char * deviceIdentifierUuid;
extern const char * deviceGenerationUuid;
extern const char * parseInfoServiceUuid;
extern const char * parseSchemeUuid;

#ifdef XIAO_SEEED_FLAG
    #define DEVICE_IDENTIFER "Seeed XIAO"
	#define DEVICE_GENERATION "1.2.1"
#elif defined BLE33NANO_FLAG
    #define DEVICE_IDENTIFER "NANO"
	#define DEVICE_GENERATION "1.2.1"
#elif defined NICLA_FLAG
    #define DEVICE_IDENTIFER "NICLA"
    #define DEVICE_GENERATION "1.2.1"
#else 
	#warning "Default BLE config"
    #define DEVICE_IDENTIFER "Generic"
	#define DEVICE_GENERATION "0.0.0"
#endif