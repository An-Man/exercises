#include "../includes/account.h"
#include "../includes/user.h"
#include <iostream>

void add_new_account() // lets the user create another account
{
    std::cout << "Adding a new account." << '\n';
    int input_cust{get_cust_number()};

    while (true)
    {
        std::cout << "Input unique account number: " << '\n';
        int input_acc{ask_int_input()};

        if (user_account_exists(input_cust, input_acc, all_users))
        {
            std::cout << "Account number already exists.\n";
        }
        else
        {
            Account new_account{input_acc, 0};
            all_users[input_cust].accounts[input_acc] = new_account;
            std::cout << "Account created.\n";
            break;
        }
    }
}

bool user_account_exists(int customer, int acc, std::map<int, User>& all_users)
{
    for (auto& pair : all_users)
    {
        if (pair.first == customer && pair.second.accounts[acc].acc_num == acc)
            
        return true;
    }
    return false;
}

int get_acc_number(int cust_number)
{
    while (true)
    {
        std::cout << "Input account number: \n";
        int input_acc{ask_int_input()};

        if (input_acc == 0)
        {
            return 0;
        }

        if (!user_account_exists(cust_number, input_acc, all_users))
        {
            std::cout << "Account not found. Try again or choose"
                " (0) to go back.\n";
        }
        else
        {
            return input_acc;
        }
    }
}

int get_acc_balance() // asks for customer and account number, returns balance
{
    int input_cust{get_cust_number()};
    int input_acc{get_acc_number(input_cust)};
    return all_users[input_cust].accounts[input_acc].acc_balance;
}

void add_money() // add money on chosen account
{
    std::cout << "Starting deposit.\n";

    int input_cust{get_cust_number()};
    int input_acc{get_acc_number(input_cust)};

    std::cout << "Input sum to deposit to account: ";
    int add_sum{ask_int_input()};

    all_users[input_cust].accounts[input_acc].acc_balance += add_sum;

    std::cout << add_sum << " deposited to account.\nBalance: "
        << all_users[input_cust].accounts[input_acc].acc_balance << '\n';
}

void withdraw_money() // withdraw from account
{
    std::cout << "Starting withdrawal.\n ";

    int input_cust{get_cust_number()};
    int input_acc{get_acc_number(input_cust)};

    std::cout << "Input sum to deposit to account: ";
    int withd_sum{ask_int_input()};

    all_users[input_cust].accounts[input_acc].acc_balance -= withd_sum;
    std::cout << withd_sum << " withdrawn from account.\nBalance: "
        << all_users[input_cust].accounts[input_acc].acc_balance << '\n';
}