#include "user.h"
#include <iostream>
#include <string>



int add_user()
{
    std::cout << "Creating a new user. " << '\n';
    std::cout << "Please input unique customer number: " << '\n';
    int input {};
    std::cin >> input;
    // tähän kutsu bool-funktio joka luuppaa käyttäjänumerot ja kertoo onko uniikki
    // palauta error tai exception jos on jo olemassa 
    User new_user {};
    new_user.customer_num = input;
    all_users[input] = new_user;

    return new_user.customer_num;
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