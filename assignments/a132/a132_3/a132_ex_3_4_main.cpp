#include <iostream>
#include <map>
#include <string>
#include <fstream>

// A banking program -- Assignment 1_3_2, Exercise 3

struct Account // variables of account
{
    int acc_num {};
    int acc_balance {};
};

struct User  // all variables related to user
{
	std::string name {};
	std::string address {};
	std::string tel {};
	int customer_num {};
    std::map<int, Account> accounts;
};

std::map<int, User> all_users;

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

void check_balance() // checks balance on account, asks which number
{
    std::cout << "To check balance, input customer number: " << '\n';
    int input_cust {};
    std::cin >> input_cust;
    std::cout << "Input account number: " << '\n';
    int input_acc {};
    std::cin >> input_acc;

    std::cout << "Balance on account nr "
        << input_acc << " is: " << all_users[input_cust].accounts[input_acc].acc_balance << '\n';
}

void add_money() // add money on chosen account
{
    std::cout << "To deposit money, enter customer number: ";
    int input_cust {};
    std::cin >> input_cust;

    std::cout << "Enter account number: ";
    int input_acc {};
    std::cin >> input_acc;

    std::cout << "Input sum to deposit to account: ";
    int add {};
    std::cin >> add;

    all_users[input_cust].accounts[input_acc].acc_balance += add;

    std::cout << add << " deposited to account. \n"
    "Balance: " << all_users[input_cust].accounts[input_acc].acc_balance << '\n';                        
}            

void withdraw_money() // withdraw from account
{
    std::cout << "To withdraw from account, enter customer number: ";
    int input_cust {};
    std::cin >> input_cust;
    std::cout << "Enter account number: ";
    int input_acc {};
    std::cin >> input_acc;
    std::cout << "Input sum to withdraw: ";
    int withdr {};
    std::cin >> withdr;
    all_users[input_cust].accounts[input_acc].acc_balance -= withdr;
    std::cout << withdr << " withdrawn from account. \n"
    "Balance: " << all_users[input_cust].accounts[input_acc].acc_balance << '\n';                                    
}

void add_new_account() // lets the user create another account
{
    std::cout << "To add an account, input customer number: " << '\n';
    int input_cust {};
    std::cin >> input_cust;
    std::cout << "Input unique account number: " << '\n';
    int input_acc {};
    std::cin >> input_acc;
    //tähän kutsutaan bool-funktiota joka luuppaa käyttäjät ja tilit

    Account new_account {input_acc, 0};     // new instance of Account, acc_number is the user input
    all_users[input_cust].accounts[input_acc] = new_account; // connects user to the account by same number
}

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

int main()
{
    std::cout << "Welcome to banking system!\n"; 

    while (true)
    {       
        std::cout << "Choose (1) to create new user, "
            "(2) to manage user, (3) to output to file, or (4) to exit: ";
        char choice {};
        std::cin >> choice;

        switch (choice) // perform function call and return to beginning of loop
        {
            case '1':
            {
                //
                enter_user_info(add_user());// add_user returns customer_number
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
                std::ofstream outf{"bank.txt"};

                if (!outf)
                {
                    std::cerr << "File error!\n";
                    break;
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