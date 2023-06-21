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
 
    for (int i = 1; i <= 10; ++i) {
       slaves.push_back(generate_slave(i));
    } 
    
    // generate master device
    Master master { random_1000to9999(), "yes" };

    // output devices to devices.csv
    write_devices_to_file("devices.csv", slaves, master);

    // output registers to registers.csv: device id, register_adr, value
    write_registers_to_file("registers.csv", slaves);
    
    // simulate master reading from file

    std::string target_id {"5"}; // set specified device id as 5

    
    search_value_str("registers.csv", target_id);

    std::cout << "Register value of id " << target_id << " is: " <<
    search_value_str("registers.csv", target_id) << '\n';

    //simulate master writing to file
    // write_to_slave_register()
    // std::ofstream output_file_reg2 ("registers.csv");


    return 0;

}