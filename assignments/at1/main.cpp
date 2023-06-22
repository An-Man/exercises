/*  Assessment test 1 / Anna Pikkarainen
    Personal finance management system
    Requirements: 
    - can track income and expenses
    - must have at least two unit tests
    Parts 1-3

    !! The program may not run at main.cpp with doctest.h included -- comment out to run
    if this happens !!
*/

#include "includes/transaction.h"
#include "includes/fileop.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<Transaction> transactions;

int main()
{
    std::cout << "Welcome to Personal Finances System!\n\n";

    while (true)
    {
        std::cout << "Choose from the following: \n";
        std::cout << "(1) Make an expenses transaction, (2) Make an "
        "income transaction, \n" <<
        "(3) View transactions, (4) Show total expenses, "
        "(5) Print to file, (6) read from file, (7) Quit ?\n";
        char choice {};
        std::cin >> choice;

        switch (choice)
        {
            case '1':
            {
                std::cout << "Making an expense transaction, enter sum: ";
                int sum {};
                std::cin >> sum;
                transactions.push_back(new_expense_transaction(sum));
                break;
            }
            case '2':
            {
                std::cout << "Making an income transaction, enter sum: ";
                int sum {};
                std::cin >> sum;
                transactions.push_back(new_income_transaction(sum));
                break;
            }
            case '3':
            {
                std::cout << "Viewing transactions: \n";
                view_transactions(transactions);
                break;
            }
            case '4':
            {
                print_total_expenses(transactions);
                break;
            }
            case '5':
            {
                std::cout << "Printing transactions to file.\n";
                write_to_file("records.txt", transactions);
                break;
            }
            case '6':
            {
                std::cout << "Printing transactions from file: \n";
                print_from_file("records.txt");
                break;
            }
            case '7':
            {
                std::cout << "Exiting program.\n";
                return 0;
            }
            default:
            {
                break;
            }
        }    
    }

    return 0;

}