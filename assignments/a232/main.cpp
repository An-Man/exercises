// Assignment 2_3_2 Sensor data simulation

#include "includes/sensor.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    // generate initial list with 20 readings from 3 sensors
    std::vector<Sensor> sensor_data {generate_list_of_20()}; 

    print_sensor_readings(sensor_data);

    // define id to filter data by
    std::string wanted_id {"sensor_id_1"};

    // create new vector with filtered data
    std::vector<Sensor> filtered_by_id {filter_by_sensor(sensor_data, wanted_id)};

    print_sensor_readings(filtered_by_id);

    // make yet another vector (as it couldn't be printed directly)
    std::vector<Sensor> sorted_by_time {sort_by_time(filtered_by_id)};

    print_sensor_readings(sorted_by_time);

    // calculate mean value of all initial readings
    double mean {calc_mean_value(sensor_data)};

    std::cout << "Mean value of all readings is: " << mean << '\n';

    // using the mean value, print outliers that deviate more than 8.0
    print_outliers(sensor_data, mean);

    // get the sensor with most reading and print sensor id
    std::cout << "Sensor with highest freq of readings is: " << 
        find_most_frequent(sensor_data) << '\n';

    return 0;
}