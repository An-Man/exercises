#ifndef DEVICES_H
#define DEVICES_H
#include <map>
#include <registers.h>

struct Master {
    int dev_id {};
    bool is_master {true};
};

struct Slave {
    int dev_id {};
    bool is_master {false};
    std::map<int, Register> regs;
};

Slave generate_slaves_registers(std::map<int, Slave>& slaves);

#endif