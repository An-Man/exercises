#include "../includes/devices.h"
#include "../includes/utils.h"
#include <map>

Slave generate_slaves_registers(std::map<int, Slave>& all_slaves)
{
    Slave new_slave {};

    int generate_id {random_1000to9999()};

    new_slave.dev_id = generate_id;
    new_slave.is_master = false;
    all_slaves[generate_id] = new_slave;

    int generate_reg_adr {random_100k_200k()};
    int generate_reg_value {random_0_255()};
    Register new_register {generate_reg_adr, generate_reg_value};
    new_slave.regs[generate_reg_adr] = new_register;
    

    return new_slave;
}

