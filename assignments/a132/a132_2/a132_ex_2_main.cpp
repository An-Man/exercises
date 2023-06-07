#include <iostream>
#include <map> // not implemented yet
#include <string>

// A banking program -- Assignment 1_3_2, Exercise 1

struct Account
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
	long balance {0};
    std::map<int, Account> accounts; // not implemented yet

};

void enter_user_info(User& user)  // gets data from user
{
    std::cout << "Enter name: ";
    std::getline(std::cin, user.name);

    std::cout << "Enter address: ";
    std::getline(std::cin, user.address);

    std::cout << "Enter telephone number : ";
    std::getline(std::cin, user.tel);

    std::cout << "Enter your customer nr: ";
    std::cin >> user.customer_num;
}

void check_balance(User& user)
{
    std::cout << "Let's check the balance." << '\n';
    std::cout << "Your account balance is: " << user.balance << '\n';
}

void add_money(User& user)
{
    std::cout << "Let's add money" << '\n';
    std::cout << "Input sum to add to account: ";
    int add {};
    std::cin >> add;
    user.balance += add;
    std::cout << add << " added to account balance." << '\n';                        
}            

void withdraw_money(User& user)
{
    std::cout << "Let's withdraw money" << '\n';
    std::cout << "Input withdraw money from account: " << '\n';
    int withdr {};
    std::cin >> withdr;
    user.balance -= withdr;
    std::cout << withdr << " taken from account balance." << '\n';                                
    }  

int main()
{
    User user1; // begin with user1

    Account acc01; //create initial account

    enter_user_info(user1); // ask user to input data

    user1.accounts[user1.customer_num]  = acc01; // pair customer num with account ?!?!?

    while (true) // loop gives user 4 choices 
    {
        std::cout << "Press (1) to check balance, (2) to add money, (3) "
         "to withdraw or (4) to quit: ";
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
                std::cout << "Bye bye!" << '\n'; // quits program
                return 0;
            default:
                break;  // if not one of 1-4, go to beginning of loop
        }

    }

    return 0;
}