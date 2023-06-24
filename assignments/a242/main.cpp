/*
Assignment 2_4_2 Modbus communication
*/

#include "devices.h"
#include "utils.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main()
{
    //create a vector of slaves with id 1-10
    std::vector<Slave> slaves {add_10_slaves_to_vector()};
 
    // generate a master device
    Master master { random_1000to9999(), "yes" };

    // output devices to devices.csv
    write_devices_to_file("devices.csv", slaves, master);

    // output registers to registers.csv: device id, register_adr, value
    write_registers_to_file("registers.csv", slaves);
    
    // simulate master reading from file
    int target_id_num {5}; // set specified device id as 5

    // searches register value from file with id
    search_value_str("registers.csv", target_id_num);

    // prints value by device id
    print_register_value("registers.csv", target_id_num);

    // simulate master writing to file
    // find value by device id, replace with new value and write to file
    // here: searches device id 5, changes value to 100 
    int new_value {100};
    write_to_slave_register("registers.csv", target_id_num, new_value, slaves);

    // prints value again after change
    print_register_value("registers.csv", target_id_num);

    return 0;

}