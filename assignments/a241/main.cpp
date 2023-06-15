/*
Assignment 2_4_1, see exercise-related .cpp-files in src-folder by feature.
Printfile-library is exercise 1.
getlines-library is exercise 2.
getwords-library is exercise 3.
...
*/

#include <iostream>
#include <fstream>
#include "getlines.h"
#include "printfile.h"
#include "getwords.h"
#include "getchars.h"

int main(int argc, char *argv[])
{
    /*  // to print arguments for debugging purposes
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << '\n';
    }
    */



    std::string arg2 {};
    
    if (argc == 3) 
    {
        arg2 = argv[2];
    }
    
    if (argc < 2) // if filename-argument is missing from command line
    {
        std::cerr << "Error: Filename missing." << '\n';
        return 1;
    }
    
    if (argc == 3 && arg2 == "-l")
    {
        std::string filename {argv[1]};
        get_lines(filename);
    }

    if (argc == 3 && arg2 == "-w")
    {
        std::string filename {argv[1]};
        get_words(filename);
    }

    if (argc == 3 && arg2 == "-c")
    {
        std::string filename {argv[1]};
        get_chars(filename);
    }      
    
    if (argc == 2)
    {
        std::string filename {argv[1]};
        print_file(filename); // print file with the filename provided
    }

    

    return 0;
}