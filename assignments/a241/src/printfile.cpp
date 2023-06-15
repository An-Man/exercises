#include "../includes/printfile.h"
#include <fstream>
#include <iostream>

// This .cpp is for Exercise 1: to take a file name as a command-line
// argument and print contents of the file to console 

void print_file(std::string filename)
{
    std::ifstream input_file {filename};

    if (input_file.is_open()) {
        std::string text;
        while (input_file >> text) {
        std::cout << text << ' ';
        }
        std::cout << '\n';
    } else {
        std::cout << "Unable to open file.\n";
    }
}