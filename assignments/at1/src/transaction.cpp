#include "../includes/transaction.h"
#include "../includes/doctest.h"
#include <iostream>
#include <vector>

Transaction new_income_transaction(int amount)
{
    Transaction new_transaction {};
    new_transaction.income = amount;
    new_transaction.expense = 0;

    std::cout << "Created new income transaction: " 
        << new_transaction.income << '\n';

    return new_transaction;
}

Transaction new_expense_transaction(int amount)
{
    Transaction new_transaction {};
    new_transaction.expense = amount;
    new_transaction.income = 0;

    std::cout << "Created new expense transaction: "
        << new_transaction.expense << '\n';

    return new_transaction;
}

void view_transactions(std::vector<Transaction> transactions)
{
    for (auto& tr : transactions)
    {
    std::cout << "Transaction - Expense: " << tr.expense <<
    ", Income : " << tr.income << '\n';
    }
}

int calc_total_expenses(std::vector<Transaction> transactions)
{
    int sum {};
    for (auto& tr : transactions)
    {
        sum += tr.expense;
    }

    return sum;
}

void print_total_expenses(std::vector<Transaction> transactions)
{
    std::cout << "Total expenses are : " << calc_total_expenses(transactions) << '\n';
}
