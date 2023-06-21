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

std::string search_value_str(std::string filename, std::string target_id);

#endif