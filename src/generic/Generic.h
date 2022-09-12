#ifndef GENERIC_H_
#define GENERIC_H_

#include "BLEHandler_G.h"
#include "SensorProvider.h"

class Edge_ML_Generic {
    public:
        Edge_ML_Generic();
        virtual ~Edge_ML_Generic();
        
        bool begin();
        void update();
        void debug(Stream &stream);
    private:
        Stream *_debug;
};

extern Edge_ML_Generic edge_ml_generic;

#endif