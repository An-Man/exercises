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
    std::map<int, Account> accounts;  // a map to connect the accounts
};

inline std::map<int, User> all_users {}; // this is inline to make it available across files

char get_choice_main_menu();

int add_user();

bool is_unique(int input, std::map<int, User>& all_users);

void enter_user_info(int customer_num);

void print_user_info();



#endif