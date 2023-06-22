#include "../includes/fileop.h"
#include "../includes/transaction.h"
#include "../includes/doctest.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string write_to_file(std::string filename, std::vector<Transaction> transactions)
{
    std::ofstream output_file (filename);

    if (!output_file)
    {
        return "File not found.\n";
    }

    for (auto& tr : transactions)
    {
        output_file << "Transaction - Expense: " << tr.expense <<
    ", Income : " << tr.income << '\n';
    }
    output_file.close();

    return "File writing succeeded.\n";
}

void print_from_file(std::string filename)
{
    std::ifstream input_file (filename);

    if (!input_file)
    {
        std::cout << "File not found.\n";
        return;
    }

    std::string line;

    while (std::getline(input_file, line))
    {
        std::cout << line << '\n';
    }
    input_file.close();
}