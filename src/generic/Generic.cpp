#include "Generic.h"


Edge_ML_Generic::Edge_ML_Generic() {
    // Init
}

Edge_ML_Generic::~Edge_ML_Generic() {
    
}

bool Edge_ML_Generic::begin() {
    if (_debug) _debug->println("Begin");

    // Begin sensors
    bleHandler_G.begin();
    sensorProvider.begin();

    if (_debug) _debug->println("End Begin \n");
    return true;
}

void Edge_ML_Generic::update() {
    // Update logic
    sensorProvider.update();
    bleHandler_G.update();
}

void Edge_ML_Generic::debug(Stream &stream) {
    _debug = &stream;
    bleHandler_G.debug(stream);
    sensorProvider.debug(stream);

    _debug->println("Debugger Active");
}

Edge_ML_Generic edge_ml_generic;