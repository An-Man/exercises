
#include "../includes/account.h"
#include "../includes/user.h"
#include <iostream>
#include <limits>
#include <map>
#include <string>

int get_choice_main_menu()
{
    std::cout << "\n---- MAIN MENU ----\n";
    std::cout << "Choose (1) to create new user, "
        "(2) to manage user,\n(3) to output to file, or (4) to exit: ";
    int choice {ask_int_input()};

    return choice;
}

int get_choice_actions()
{
    std::cout << "\n --- USER ACTIONS ---\n";
    std::cout << "Press (1) to display user info, (2) to add an account, \n"
    "(3) to check balance, (4) to deposit money, (5) to withdraw, (6) to go back: ";
    
    int choice {ask_int_input()};

    return choice;
}

bool user_exists(int input, std::map<int, User>& all_users)
{
    for (auto& pair : all_users)
    {
        if (pair.first == input)
        return true;
    }
    return false;
}

int create_user()
{
    while (true)
    {
        std::cout << "\nCreating a new user. " << '\n';
        std::cout << "Please input unique customer number: " << '\n';

        int input {ask_int_input()};

        if (user_exists(input, all_users)) // check if number is unique
        {
            std::cout << "User number already exists.\n";  
        } 
        else
        {
        User new_user {}; // create new User, use input as customer num
        new_user.customer_num = input;
        all_users[input] = new_user;  // add user to map by cust num

        return new_user.customer_num;
        }
    }
}

void add_user_info(int customer_num)  // gets data from user
{
    std::cout << "Enter name: ";
    std::string name {ask_str_input()};

    std::cout << "Enter address: ";
    std::string addr {ask_str_input()};

    std::cout << "Enter telephone number: ";
    std::string tel {ask_str_input()};

    all_users[customer_num].name = name; 
    all_users[customer_num].address = addr;
    all_users[customer_num].tel = tel;
}

std::string ask_str_input()
{
    std::string input;
    std::getline(std::cin >> std::ws, input); //remove whitespace if needed
    return input;
}

int ask_int_input()
{
    while (true)
    {
        int input {};
        std::cin >> input;

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // clear cin
            ignoreLine();     // and remove input
            std::cout << "Try again: ";
        }
        else if (input <= 0)
        {
            std::cout << "Number must be positive and not 0\n";
            std::cout << "Try again: ";
        }
        else
        {
            ignoreLine();
            return input;
        }
    }
}

int get_cust_number()
{
    while (true) {
        std::cout << "Input customer number: \n";
        int input {ask_int_input()};

        if (input == 0) { // lets user get out of loop if needed
            return 0;
        }

        if (!user_exists(input, all_users)) {
            std::cout << "Customer not found. Try again or choose"
            " (0) to go back.\n";
        } else {
        return input;
        }
    }
}

void print_user_info()
{
    int input {get_cust_number()};
        if (input != 0) {
        std::cout << "Name: " << all_users[input].name << '\n'; 

        std::cout << "Address: " << all_users[input].address << '\n'; 

        std::cout << "Telephone number: " << all_users[input].tel << '\n';
        }
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}