#include "../includes/getlines.h"

// This .cpp is for Exercise 2: to take a file name as a command-line
// argument and print number of lines in the text file.

void get_lines(std::string filename)
{
    std::ifstream input_file {filename};

    if (input_file.is_open())
    {
        int line_count {0};
        std::string line {};

        while (std::getline(input_file, line)) {
            line_count++;
        }
        std::cout << "File line count is: " << line_count << '\n';
    } 
    else 
    {
        std::cout << "Unable to open file.\n";
    }
}