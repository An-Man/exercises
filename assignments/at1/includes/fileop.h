#ifndef FILEOP_H
#define FILEOP_H
#include "transaction.h"
#include <fstream>
#include <vector>
#include <string>

std::string write_to_file(std::string filename, std::vector<Transaction> transactions);

void print_from_file(std::string filename);

#endif