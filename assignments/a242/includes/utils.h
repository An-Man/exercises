#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <string>
#include <vector>

int random_1000to9999();
int random_100k_200k();
int random_0_255();

void search_and_print(std::ifstream& inputf, std::string target_id);

#endif