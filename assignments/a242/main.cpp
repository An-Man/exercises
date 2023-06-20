/*
Assignment 2_4_2 Modbus communication
*/

#include "devices.h"
#include "utils.h"
#include "registers.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

//std::map<int, Slave> all_slaves;
 

int main()
{
    std::vector<Slave> slaves;

    /*     
    for (int i = 1; i <= 10; ++i) {
       slaves.push_back(generate_slave(i));
    } 
    */

    Slave new_slave {};

    new_slave.dev_id = "001";
    new_slave.master = "no";
    new_slave.reg_adr = random_100k_200k();
    new_slave.reg_value = random_0_255();
    slaves.push_back(new_slave);

    Slave new_slave2 {};

    new_slave2.dev_id = "002";
    new_slave2.master = "no";
    new_slave2.reg_adr = random_100k_200k();
    new_slave2.reg_value = random_0_255();
    slaves.push_back(new_slave2);    


    // generate master device
    Master master { random_1000to9999(), "yes" };

    // output devices to devices.csv: device id, is_master
    std::ofstream output_file_dev ("devices.csv");

        if (!output_file_dev) {
            std::cout << "error\n";
            return 1;
        }
        output_file_dev << "Device id, Master\n";

        for (auto& c : slaves) { // first loop slaves from vector, then add master
            output_file_dev << c.dev_id << "," << c.master << "," << '\n';
        }                    
        output_file_dev << master.dev_id << "," << master.master << "," << '\n';
        

    // output registers to registers.csv: device id, register_adr, value
    std::ofstream output_file_reg ("registers.csv");
        
    if (!output_file_reg) {
        std::cout << "error\n";
        return 1;
    }
        
    output_file_reg << "Slave id, Register address, Value\n";
    
    for (auto& slave : slaves) { //
        output_file_reg << slave.dev_id << "," << slave.reg_adr <<  "," << slave.reg_value << '\n';
    } 

    output_file_dev.close();
    output_file_reg.close();


    // simulate master reading from file
    std::ifstream input_file_reg ("registers.csv");

        if(!input_file_reg) {
            std::cout << "Error: file not found\n";
            return 1;
        }

    std::string target_id {"002"}; // set specified device id as 5




        
        
    // search_and_print(input_file_reg, target_id);
    
    return 0;

}