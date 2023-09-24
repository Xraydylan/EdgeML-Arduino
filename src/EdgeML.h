#ifndef Edge_ML_BASE_H_
#define Edge_ML_BASE_H_

#include <config/flags.h>
#include <generic/Generic.h>

class Edge_ML {
public:
    Edge_ML() {
        // Nothing
    }

    void set_custom(SensorManagerInterface * sensorManager) {
        edge_ml_generic.set_custom(sensorManager);
    }

    bool begin() {
        return edge_ml_generic.begin();
    }
    void update() {
        edge_ml_generic.update();
    }

    void configure_sensor(EdgeSensorConfigurationPacket& config) {
        edge_ml_generic.configure_sensor(config);
    }

    String get_name() {
        return edge_ml_generic.get_name();
    }

    void ble_manual_advertise() {
        return edge_ml_generic.ble_manual_advertise();
    }

    void set_ble_config(String name, String gen = "0.0.0") {
        edge_ml_generic.set_ble_config(std::move(name), std::move(gen));
    }

    int get_active_count() {
        return edge_ml_generic.get_active();
    }

    String parse_to_string(int sensorID, byte * data) {
        return edge_ml_generic.parse_to_string(sensorID, data);
    }

    void set_data_callback(void(*callback)(int id, unsigned int timestamp, uint8_t* data, int size)) {
        edge_ml_generic.set_data_callback(callback);
    }

    void set_config_callback(void(*callback)(EdgeSensorConfigurationPacket *)) {
        edge_ml_generic.set_config_callback(callback);
    }

    void debug(Stream &stream) {
        edge_ml_generic.debug(stream);
    }
};

extern Edge_ML edge_ml;

#endif //Edge_ML_BASE_H_
