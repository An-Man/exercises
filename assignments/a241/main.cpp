#include <iostream>
#include <fstream>
#include "printfile.h"
#include "cxxopts.hpp"

/*
Assignment 2_4_1, see exercise-related .cpp-files in src-folder by feature.
Printfile-library is exercise 1.
...
*/

int main(int argc, char *argv[])
{

    if (argc < 2) // if filename-argument is missing from command line
    {
        std::cerr << "Error: Filename missing." << '\n';
        return 1;
    }

    std::string filename{argv[1]}; // create a string with user input argument

    print_file(filename); // print file with the filename provided

    return 0;
}