#if defined(ARDUINO_NICLA)
#ifndef NICLA_TEST_DFU_INTERFACE_H
#define NICLA_TEST_DFU_INTERFACE_H

#include "DFUManager.h"
#include "ArduinoBLE.h"
#include "Arduino_BHY2.h"

class DFU_Interface {
public:
    DFU_Interface();
    virtual ~DFU_Interface();

    void begin();

private:
    bool _lastDfuPack = false;

    void processDFUPacket_Edge(DFUType dfuType, BLECharacteristic characteristic);
    static void receivedInternalDFU_Edge(BLEDevice central, BLECharacteristic characteristic);
    static void receivedExternalDFU_Edge(BLEDevice central, BLECharacteristic characteristic);
};

extern DFU_Interface dfu_interface;


#endif //NICLA_TEST_DFU_INTERFACE_H
#endif