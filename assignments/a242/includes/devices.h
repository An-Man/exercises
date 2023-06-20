#ifndef DEVICES_H
#define DEVICES_H
#include <map>
#include <registers.h>
#include <string>

struct Master {
    int dev_id {};
    std::string master {};
};

struct Slave {
    std::string dev_id {};
    std::string master {};
    int reg_adr {};
    int reg_value {};
};

Slave generate_slave(int id);

#endif