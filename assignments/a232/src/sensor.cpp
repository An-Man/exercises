#include "sensor.h"

#include <string>

struct Sensor_reading
{
    int timestamp {};
    std::string sensor_id {};
    float sensor_value {}; 
};

