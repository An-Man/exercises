#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account // variables of account
{
    int acc_num {};
    int acc_balance {};
};

void add_new_account();

void check_balance();

void add_money();

void withdraw_money();



#endif