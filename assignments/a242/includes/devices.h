#ifndef DEVICES_H
#define DEVICES_H
#include <map>
#include <registers.h>

struct Master {
    int dev_id {};
    bool master {true};
};

struct Slave {
    int dev_id {};
    bool master {false};
    std::map<int, Register> registers;
};



#endif