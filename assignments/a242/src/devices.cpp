#include "../includes/devices.h"
#include "../includes/utils.h"
#include <vector>
#include <fstream>

Slave generate_slave(int id)
{
    Slave new_slave {};

    new_slave.dev_id = id;
    new_slave.master = "no";
    new_slave.reg_adr = random_100k_200k();
    new_slave.reg_value = random_0_255();
    
    return new_slave;
}

std::vector<Slave> add_10_slaves_to_vector()
{
    std::vector<Slave> slaves;

    for (int i = 1; i <= 10; ++i) {
       slaves.push_back(generate_slave(i));
    }

    return slaves;
}
