#ifndef UTILS_H
#define UTILS_H
#include "devices.h"
#include <fstream>
#include <string>
#include <vector>

int random_1000to9999();
int random_100k_200k();
int random_0_255();

void write_devices_to_file(std::string filename, std::vector<Slave> slaves, Master master);

void write_registers_to_file(std::string filename, std::vector<Slave> slaves);

std::string search_value_str(std::string filename, int target_id_num);

void write_to_slave_register(std::string filename, int target_id, 
    int target_value, std::vector<Slave> slaves);

void print_register_value(std::string filename, int target_id_num);

#endif