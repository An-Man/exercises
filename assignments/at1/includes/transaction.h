#ifndef TRANSACTION_H
#define TRANSACTION_H
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

struct Transaction
{
    int income {};
    int expense {};
};

Transaction new_income_transaction(int amount);

Transaction new_expense_transaction(int amount);

void view_transactions(std::vector<Transaction> transactions);

int calc_total_expenses(std::vector<Transaction> transactions);

void print_total_expenses(std::vector<Transaction> transactions);

#endif