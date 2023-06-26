#include "user.h"
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <cctype>



char get_choice_main_menu() // ei ole hyvä koska ottaa kaksi numeroa bufferiin
{
    std::cout << "\n---- MAIN MENU ----\n";
    std::cout << "Choose (1) to create new user, "
        "(2) to manage user,\n(3) to output to file, or (4) to exit: ";
    char input;
    std::cin >> input;
        if (input == '1' || input == '2' || input == '3' || input == '4')
        {
            return input;
        }
    return -1;     
}

bool is_unique(int input, std::map<int, User>& all_users)
{
    for (auto& pair : all_users)
    {
        if (pair.first == input)
        return false;
    }
    return true;
}

int add_user()
{
    std::cout << "Creating a new user. " << '\n';
    std::cout << "Please input unique customer number: " << '\n';
    std::string input_str {};
    std::getline(std::cin >> std::ws, input_str);
    int input {std::stoi(input_str)};

    if (!is_unique(input, all_users))
    {
        std::cout << "User number already exists.\n";
        return -1; // error code -1 if not unique number
    } 
    else 
    {
    User new_user {};
    new_user.customer_num = input;
    all_users[input] = new_user;

    return new_user.customer_num;
    }
}

void enter_user_info(int customer_num)  // gets data from user
{
    std::cout << "Enter name: ";
    std::string input;
    std::getline(std::cin >> std::ws, input);
    all_users[customer_num].name = input;

    std::cout << "Enter address: ";
    std::getline(std::cin >> std::ws, input);
    all_users[customer_num].address = input;
    
    std::cout << "Enter telephone number: ";
    std::getline(std::cin >> std::ws, input);
    all_users[customer_num].tel = input;
}

void print_user_info()
{
    std::cout << "To print user info, input customer number: " << '\n';
    int input {};
    std::cin >> input;

    std::cout << "Name: " << all_users[input].name << '\n'; 

    std::cout << "Address: " << all_users[input].address << '\n'; 

    std::cout << "Telephone number: " << all_users[input].tel << '\n';
}