#ifndef USER_H
#define USER_H
#include "account.h"
#include <string>
#include <map>

struct Account;

struct User  // all variables related to user
{
	std::string name {};
	std::string address {};
	std::string tel {};
	int customer_num {};
	std::map<int, Account> accounts {}; // a map to connect the accounts
};

inline std::map<int, User> all_users {}; // this is inline to make it available across files

int get_choice_main_menu();

int get_choice_actions();

int create_user();

std::string ask_str_input();
int ask_int_input();

bool user_exists(int input, std::map<int, User>& all_users);

void add_user_info(int customer_num);

int get_cust_number();

void print_user_info();

void ignoreLine();

#endif