#if defined(ARDUINO_NICLA)
#include "DFU_Interface.h"

// DFU channels
BLEService dfuService_Edge("34c2e3b8-34aa-11eb-adc1-0242ac120002");
auto dfuInternalUuid_Edge = "34c2e3b9-34aa-11eb-adc1-0242ac120002";
auto dfuExternalUuid_Edge = "34c2e3ba-34aa-11eb-adc1-0242ac120002";
BLECharacteristic dfuInternalCharacteristic_Edge(dfuInternalUuid_Edge, BLEWrite, sizeof(DFUPacket), true);
BLECharacteristic dfuExternalCharacteristic_Edge(dfuExternalUuid_Edge, BLEWrite, sizeof(DFUPacket), true);

DFU_Interface::DFU_Interface() {

}

DFU_Interface::~DFU_Interface() {

}

void DFU_Interface::begin() {
    // DFU channel
    BLE.setAdvertisedService(dfuService_Edge);
    dfuService_Edge.addCharacteristic(dfuInternalCharacteristic_Edge);
    dfuService_Edge.addCharacteristic(dfuExternalCharacteristic_Edge);
    BLE.addService(dfuService_Edge);
    dfuInternalCharacteristic_Edge.setEventHandler(BLEWritten, receivedInternalDFU_Edge);
    dfuExternalCharacteristic_Edge.setEventHandler(BLEWritten, receivedExternalDFU_Edge);

    dfuManager.begin();
}

void DFU_Interface::processDFUPacket_Edge(DFUType dfuType, BLECharacteristic characteristic) {
    uint8_t data[sizeof(DFUPacket)];
    characteristic.readValue(data, sizeof(data));
    /*
     if (_debug) {
        _debug->print("Size of data: ");
        _debug->println(sizeof(data));
    }
    */
    dfuManager.processPacket(bleDFU, dfuType, data);

    if (data[0]) {
        //Last packet
        _lastDfuPack = true;
        dfuManager.closeDfu();
    }
}

void DFU_Interface::receivedInternalDFU_Edge(BLEDevice central, BLECharacteristic characteristic) {
    /*
    if (_debug) {
        _debug->println("receivedInternalDFU");
    }
    */
    dfu_interface.processDFUPacket_Edge(DFU_INTERNAL, characteristic);
}

void DFU_Interface::receivedExternalDFU_Edge(BLEDevice central, BLECharacteristic characteristic) {
    dfu_interface.processDFUPacket_Edge(DFU_EXTERNAL, characteristic);
}

DFU_Interface dfu_interface;

#endif



