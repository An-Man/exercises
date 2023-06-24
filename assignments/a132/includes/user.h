#ifndef USER_H
#define USER_H
#include "account.h"
#include <string>
#include <map>

struct User  // all variables related to user
{
	std::string name {};
	std::string address {};
	std::string tel {};
	int customer_num {};
    std::map<int, Account> accounts;
};

inline std::map<int, User> all_users {};

int add_user();

void enter_user_info(int customer_num);

void print_user_info();



#endif