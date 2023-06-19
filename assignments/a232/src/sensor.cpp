#include "../includes/sensor.h"
#include "../includes/randomnum.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

void print_sensor_readings(std::vector<Sensor>& sensor_vector)
{
    for (const auto& reading : sensor_vector)
    {
        std::cout << "Sensor ID: " << reading.sensor_id <<
        "\tSensor timestamp: " << reading.timestamp <<
        "\tSensor value: " << reading.sensor_value << '\n';
    }

    std::cout << "---\n";
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

std::vector<Sensor> filter_by_sensor(std::vector<Sensor>& all_sensors, std::string filt_id)
{
    std::vector<Sensor> new_vector;

    for (auto& reading : all_sensors)
    {
        if (reading.sensor_id == filt_id)
        {
            new_vector.push_back(reading);
        }
    }
    return new_vector;
}

bool compare_by_time(const Sensor& sensor1, const Sensor& sensor2) 
{
        return sensor1.timestamp < sensor2.timestamp;
}

std::vector<Sensor> sort_by_time(std::vector<Sensor>& data)
{
    std::sort(data.begin(), data.end(), compare_by_time);

    return data;
}

double calc_mean_value(std::vector<Sensor>& data)
{
    double sum {};
    for (auto& reading : data) {
        sum += reading.sensor_value;
    }

    return (sum / data.size());
}

void print_outliers(std::vector<Sensor>& data, double mean)
{
    for (auto& reading : data) {
        if (reading.sensor_value >= (mean + 8.0) || 
        reading.sensor_value <= (mean - 8.0))
        {
            std::cout << "Outlier detected - " <<
            " Sensor ID: " << reading.sensor_id <<
            " Sensor timestamp: " << reading.timestamp <<
            " Sensor value: " << reading.sensor_value << '\n';
        }
    }
}

std::string find_most_frequent(std::vector<Sensor>& data)
{
    std::map<std::string, int> frequency_map;

    for (const auto& reading : data) {
        frequency_map[reading.sensor_id]++;
    }

    int max_freq {0};
    std::string max_freq_sensor_id {};

    for (const auto& pair : frequency_map) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
            max_freq_sensor_id = pair.first;
        }
    }
    return max_freq_sensor_id;
}