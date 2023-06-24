#include "account.h"
#include "user.h"
#include <iostream>

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