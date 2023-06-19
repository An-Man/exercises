#include "../includes/sensor.h"
#include "../includes/randomnum.h"
#include <iostream>
#include <string>
#include <vector>

void print_sensor_readings(std::vector<Sensor>& sensor_vector)
{
    for (const auto& reading : sensor_vector)
    {
        std::cout << "Sensor ID: " << reading.sensor_id <<
        "\tSensor timestamp: " << reading.timestamp <<
        "\tSensor value: " << reading.sensor_value << '\n';
    }
}

std::vector<Sensor> generate_list_of_20()
{
    std::vector<Sensor> sensor_data;

    for (int i = 0; i < 20; ++i)
    {
        Sensor new_sensor {generate_sensor_reading()};
        sensor_data.push_back(new_sensor);
    }
    return sensor_data;
}

Sensor generate_sensor_reading() // generates one sensor reading
{
    Sensor new_sensor {};

    int new_time {random_1000to2000()};
    new_sensor.timestamp = new_time;
    
    int new_sensor_random {random_1to3()};

    if (new_sensor_random == 1) {
        new_sensor.sensor_id = "sensor_id_1";
    } else if (new_sensor_random == 2) { 
        new_sensor.sensor_id = "sensor_id_2";
    } else {
        new_sensor.sensor_id = "sensor_id_3";
    }

    float new_sensor_value {random_float1_20()};
    new_sensor.sensor_value = new_sensor_value;

    return new_sensor;
}

