#include "fileop.h"
#include "user.h"
#include "account.h"
#include <iostream>
#include <fstream>
#include <string>

void print_to_file(std::string filename)
{
    std::ofstream outf{filename};

        if (!outf)
        {
            std::cout << "File error!\n";
            return; 
        }

    std::cout << "To print user info to file, input customer number: " << '\n';
    int input_cust {};
    std::cin >> input_cust;

    std::cout << "To print account info to file, input account number: " << '\n';
    int input_acc {};
    std::cin >> input_acc;

    outf << "User information on customer number " << input_cust << ": \n";
    outf << "Name: " << all_users[input_cust].name << '\n'; 
    outf << "Address: " << all_users[input_cust].address << '\n'; 
    outf << "Telephone number: " << all_users[input_cust].tel << '\n';
    
    outf << "Bank account number: " << input_acc << '\n';
    outf << "Balance: " << all_users[input_cust].accounts[input_acc].acc_balance << '\n';

    std::cout << "Printed to file.\n" ;
}