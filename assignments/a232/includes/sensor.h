#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <vector>


struct Sensor
{
    int timestamp {};
    std::string sensor_id {};
    float sensor_value {};

};

Sensor generate_sensor_reading();

std::vector<Sensor> generate_list_of_20();

void print_sensor_readings(std::vector<Sensor>& sensor_vector);

#endif