//
// Created by Dylan Ray Roodt on 23.05.2022.
//
#if defined(TARGET_SEEED_XIAO_NRF52840_SENSE)
#ifndef EDGE_ML_SEEED_H
#define EDGE_ML_SEEED_H

#include "BLEHandler_Seeed.h"
#include "Sensor_Provider_Seeed.h"

class Edge_ML_Seeed {
public:
    Edge_ML_Seeed();
    bool begin();
    void update();
    void debug(Stream &stream);
private:
    Stream *_debug;
};



extern Edge_ML_Seeed edge_ml_seeed;

#endif //EDGE_ML_SEEED_H
#endif