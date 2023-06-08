#include <iostream>
#include <map>

// A banking program -- Assignment 1_3_2, Exercise 2

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

void enter_user_info(User& user)  // gets data from user
{
    std::cout << "Enter name: ";
    std::getline(std::cin, user.name);

    std::cout << "Enter address: ";
    std::getline(std::cin, user.address);

    std::cout << "Enter telephone number: ";
    std::getline(std::cin, user.tel);

    std::cout << "Enter your customer nr: ";
    std::cin >> user.customer_num;
}

void check_balance(User& user) // checks balance on account, asks which number
{
    std::cout << "Let's check the balance." << '\n';
    std::cout << "Enter account number (default account is 1001): ";
    int input {};
    std::cin >> input;

    std::cout << "Balance on account nr "
        << input << " is: " << user.accounts[input].acc_balance << '\n';
}

void add_money(User& user) // add money on chosen account
{
    std::cout << "Let's add money" << '\n';
    std::cout << "Enter account number (default account is 1001): ";
    int input {};
    std::cin >> input;
    std::cout << "Input sum to add to account: ";
    int add {};
    std::cin >> add;
    user.accounts[input].acc_balance += add;
    std::cout << add << " added to account balance." << '\n';                        
}            

void withdraw_money(User& user) // withdraw from account
{
    std::cout << "Let's withdraw money" << '\n';
    std::cout << "Enter account number (default account is 1001): ";
    int input {};
    std::cin >> input;
    std::cout << "Input sum to withdraw money from account: " << '\n';
    int withdr {};
    std::cin >> withdr;
    user.accounts[input].acc_balance -= withdr;
    std::cout << withdr << " taken from account balance." << '\n';                                
    }

void add_new_account(User& user) // lets the user create another account
{
    std::cout << "Let's add another bank account" << '\n';
    std::cout << "Input unique account number: " << '\n';
    int input {};
    std::cin >> input;

    Account new_account {input, 0};     // new instance of Account, acc_number is the user input
    user.accounts[input] = new_account; // connects user to the account by same number
}

int main()
{
    User user1 {}; // creates first user

    Account acc01 = {1001, 9000};
    
    user1.accounts[1001] = acc01; // account created and linked to user1 in map
     
    enter_user_info(user1); // user info is input at start

    while (true) // loop gives user 4 choices 
    {
        std::cout << "Press (1) to check balance, (2) to add money, (3) "
         "to withdraw, (4) to add new account, (5) to quit: ";
        int choice {};
        std::cin >> choice;

        switch (choice) // perform function call and return to beginning of loop
        {
            case 1:
            {
                check_balance(user1);
                break;
            }
            case 2:
            {
                add_money(user1);
                break;
            }
            case 3:
            {
                withdraw_money(user1);
                break;
            }
            case 4:
            {
                add_new_account(user1);
                break;
            }
            case 5:
                std::cout << "Bye bye!" << '\n'; // quits program
                return 0;
            default:
                break;  // if not one of 1-4, go to beginning of loop
        }

    }

    return 0;
}