#ifndef DEVICES_H
#define DEVICES_H
#include <string>
#include <vector>

struct Master {
    int dev_id {};
    std::string master {};
};

struct Slave {
    int dev_id {};
    std::string master {};
    int reg_adr {};
    int reg_value {};
};

Slave generate_slave(int id);

std::vector<Slave> add_10_slaves_to_vector();

#endif