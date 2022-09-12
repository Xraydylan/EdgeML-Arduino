#ifndef Edge_ML_BASE_H_
#define Edge_ML_BASE_H_

#include <auto_include/flags.h>

#ifdef NICLA_FLAG
    #include<boards/special_boards/nicla/Edge_ML_Nicla.h>
#else
	#include<generic/Generic.h>
#endif

class Edge_ML {
    public:
        Edge_ML() {
          #ifdef NICLA_FLAG
            Edge_ML_Nicla();
          #else 
            Edge_ML_Generic();
          #endif
        }
        bool begin() {
          #ifdef NICLA_FLAG
            edge_ml_nicla.begin();
          #else 
            edge_ml_generic.begin();
          #endif
        }
        void update() {
          #ifdef NICLA_FLAG
            edge_ml_nicla.update();
          #else 
            edge_ml_generic.update();
          #endif
        }
        void debug(Stream &stream) {
          #ifdef NICLA_FLAG
            edge_ml_nicla.debug(stream);
          #else 
            edge_ml_generic.debug(stream);
          #endif
        }
};

extern Edge_ML edge_ml;

#endif
