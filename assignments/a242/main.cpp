/*
Assignment 2_4_2 Modbus communication
*/

#include "devices.h"
#include "utils.h"
#include "registers.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

std::map<int, Slave> all_slaves;
 

int main()
{
    std::vector<Slave> slaves;
    std::vector<Register> registers;

    for (int i = 1; i <= 10; ++i) {
       slaves.push_back(generate_slaves_registers(all_slaves));
    }

    // generate master device
    Master master { random_1000to9999(), true };

    // output devices to devices.csv: device id, is_master
    std::ofstream output_file ("devices.csv");

        if (!output_file) {
            std::cout << "error\n";
        } else {
            for (auto& c : slaves) { // first loop slaves from vector, then add master
                output_file << c.dev_id << "," << c.is_master << "," << '\n';
            }                    
            output_file << master.dev_id << "," << master.is_master << "," << '\n';
        }

    // output registers to registers.csv: device id, register_adr, value
    std::ofstream output_file_2 ("registers.csv");
        
        if (!output_file_2) {
            std::cout << "error\n";
        } else {
            for (const auto& c : ) {
                output_file_2 << södflksdöfj << '\n';
            }                    
            
        }


    return 0;

}