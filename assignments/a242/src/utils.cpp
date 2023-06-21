#include "../includes/utils.h"
#include "../includes/devices.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>


int random_1000to9999()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r1000to9999 { 1000, 9999 };

    return r1000to9999 (mt);
}

int random_100k_200k()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r_100k_200k { 100000, 200000 };

    return r_100k_200k (mt);
}

int random_0_255()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r_0_255 { 0, 255 };

    return r_0_255 (mt);    
}

void write_devices_to_file(std::string filename, std::vector<Slave> slaves, Master master)
{
    std::ofstream output_file (filename);

    if (!output_file) {
        std::cout << "error\n";
        return;
    }
    output_file << "Device id, Master\n";

    for (auto& c : slaves) { // first loop slaves from vector, then add master
        output_file << c.dev_id << "," << c.master << "," << '\n';
    }                    
    output_file << master.dev_id << "," << master.master << "," << '\n';

    output_file.close();    
}

void write_registers_to_file(std::string filename, std::vector<Slave> slaves)
{
    std::ofstream output_file (filename);
        
    if (!output_file) {
        std::cout << "error\n";
        return;
    }
        
    output_file << "Slave id, Register address, Value\n";
    
    for (auto& slave : slaves) { //
        output_file << slave.dev_id << "," << slave.reg_adr <<
          "," << slave.reg_value << '\n';
    } 

    output_file.close();
}

std::string search_value_str(std::string filename, std::string target_id)
{
    std::ifstream input_file ("registers.csv");

    if(!input_file) {
        return "Error: file not found\n";
    }
    
    if(!input_file.is_open()) {
    return "Error: file not found\n";
    }

    std::string line {};

    while (std::getline(input_file, line))
    {
        std::istringstream iss(line);
        std::string id_string;
        std::getline(iss, id_string, ',');

        if (target_id == id_string)
        {
        std::string reg {};
        std::getline(iss, reg, ',');
        std::string value {};
        std::getline(iss, value, ',');
        input_file.close();
        return value;
        }
    }   
    return "Target_id not found";                      
}