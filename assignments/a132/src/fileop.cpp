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

    std::cout << "\nPrinting user info to file --\n";
    int input_cust {get_cust_number()};
    
    outf << "User information on customer number " << input_cust << ": \n";
    outf << "Name: " << all_users[input_cust].name << '\n'; 
    outf << "Address: " << all_users[input_cust].address << '\n'; 
    outf << "Telephone number: " << all_users[input_cust].tel << '\n';
    
    outf << "Bank accounts:\n"; // loop accounts and print balances

        for (auto& acc : all_users[input_cust].accounts)
        {
            outf << acc.first << ", balance: " << acc.second.acc_balance << '\n';
        }

    std::cout << "Data printed to file.\n" ;
}