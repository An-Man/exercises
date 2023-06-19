#include "includes/sensor.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>


int main()
{
    std::vector<Sensor> sensor_data {generate_list_of_20()};

    print_sensor_readings(sensor_data);

    
}