#include "includes/account.h"
#include "includes/fileop.h"
#include "includes/user.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>

// A banking program -- Assignment 1_3_2, Exercise 3

int main()
{
    std::cout << "Welcome to banking system!\n"; 

    while (true)
    {       
        switch (get_choice_main_menu()) // perform function call and return to beginning of loop
        {
            case 1:
            {
                // Adding a user and info
                int new_user_num {create_user()};

                std::cout << "Enter name: ";
                std::string name {ask_str_input()};
                std::cout << "Enter address: ";
                std::string addr {ask_str_input()};
                std::cout << "Enter telephone number: ";
                std::string tel {ask_str_input()};

                add_user_info(new_user_num, name, addr, tel);
                break;
            }
            case 2:
            {
                bool stay_in_loop = true;

                while (stay_in_loop)   
                {                    
                    switch (get_choice_actions())
                    {
                        case 1:
                        {
                            print_user_info();
                            break;
                        }
                        case 2:
                        {
                            add_new_account();
                            break;
                        }
                        case 3:
                        {
                            check_balance();
                            break;
                        }
                        case 4:
                        {
                            add_money();
                            break;
                        }
                        case 5:
                        {
                            withdraw_money();
                            break;
                        }
                        case 6:
                        {
                            // go back
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

            break; 
            
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