#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <map>

struct User; 

struct Account // variables of account
{
    int acc_num {1};  // initial account is 1 for every user
    int acc_balance {0};
};

void add_new_account();

bool user_account_exists(int customer, int acc, std::map<int, User>& all_users);

int get_acc_number(int cust_number);

int get_acc_balance();

void add_money();

void withdraw_money();

#endif