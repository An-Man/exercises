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
#include "getsize.h"

int main(int argc, char *argv[]) // standard parameters of int main()
{
    // loop to search for argument "size"
    for (int i = 1; i < argc; ++i) {
        // std::cout << argv[i] << '\n';
        std::string argument = argv[i];
        if (argument == "size") {
            get_text_files_size(); // call function in library getsize

            return 0; // end program
        }
    }

    if (argc < 2) // if filename-argument, which must be second, is missing from command line
    {
        std::cerr << "Error: Filename missing." << '\n';
        return 1;
    }

    std::string arg2 {}; // this is to help comparison in the next cases
    if (argc == 3) 
    {
        arg2 = argv[2];
    }
    
    // the second argument can be either -l, -w or -c
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
    
    if (argc == 2) // if there are two arguments, the second must be a filename :'D
    {
        std::string filename {argv[1]};
        print_file(filename); // print file with the filename provided
    }

    return 0;
}