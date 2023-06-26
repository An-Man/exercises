#include "account.h"
#include "fileop.h"
#include "user.h"
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
            case '1':
            {
                //
                int new_user_num {add_user()};
                if (new_user_num == -1)
                {
                    break;
                }

                enter_user_info(new_user_num);
                break;
            }
            case '2':
            {
                bool stay_in_loop = true;

                while (stay_in_loop)   
                {
                    std::cout << "Press (1) to display user info, (2) to add an account, \n"
                    "(3) to check balance, (4) to deposit money, (5) to withdraw, (6) to go back: ";
                    int choice {};
                    std::cin >> choice;
                    
                    switch (choice)
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
                            break;
                    }
                }
                
            break;    
            }
            case '3':
            {
                print_to_file("bank.txt");

                break;
            }

            break; 
            
            case '4':
            {
                std::cout << "Bye bye!" << '\n'; // quits program
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