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

std::vector<Sensor> filter_by_sensor(std::vector<Sensor>& all_sensors, std::string filt_id);

std::vector<Sensor> sort_by_time(std::vector<Sensor>& data);

double calc_mean_value(std::vector<Sensor>& data);

void print_outliers(std::vector<Sensor>& data, double mean);

std::string find_most_frequent(std::vector<Sensor>& data);

#endif