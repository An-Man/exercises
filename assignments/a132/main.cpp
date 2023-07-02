#include "includes/account.h"
#include "includes/user.h"
#include "includes/fileop.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>

// A banking program -- Assignment 1_3_2, Exercise 3
// Now with input validation and other error handling improvements

int main()
{
    std::cout << "Welcome to banking system!\n"; 

    while (true)
    {       
        switch (get_choice_main_menu())
        {
            case 1: // creates a new user
            {
                int new_user_num {create_user()};
                add_user_info(new_user_num);
                break;
            }
            case 2: // changes to user management loop
            {
                bool stay_in_loop {true};

                while (stay_in_loop)   
                {                    
                    switch (get_choice_actions())
                    {
                        case 1: // print user name etc.
                        {
                            print_user_info();
                            break;
                        }
                        case 2: // create a new account
                        {
                            add_new_account();
                            break;
                        }
                        case 3: // print balance
                        {
                            int balance {get_acc_balance()};
                            std::cout << "Account Balance: " << balance << '\n'; 
                            break;
                        }
                        case 4: // deposit money
                        {
                            add_money();
                            break;
                        }
                        case 5:
                        {
                            withdraw_money();
                            break;
                        }
                        case 6:  // go back
                        {
                            stay_in_loop = false;
                            break;
                        }
                        default:
                        {
                            std::cout << "Try again.\n";
                            break;
                        }
                    }
                }
                
            break;    
            }
            case 3:
            {
                print_to_file("bank.txt");
                break;
            }
            case 4:
            {
                std::cout << "Bye bye!\n"; // quits program
                return 0;
            }
            default:
            {
                std::cout << "Try again.\n";
                break;
            }
        }
    }

    return 0;

}