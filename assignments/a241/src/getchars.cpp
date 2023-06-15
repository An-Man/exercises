#include "../includes/getchars.h"
#include <iomanip>

// This .cpp is for Exercise 4: to take a file name as a command-line
// argument and print number of characters in the text file.

void get_chars(std::string filename)
{
    std::ifstream input_file {filename};

    if (input_file.is_open())
    {
        int char_count {0};
        char c {};

        while (input_file >> std::noskipws >> c) {
            char_count++;
        }
        std::cout << "File character count is: " << char_count << '\n';
    } 
    else 
    {
        std::cout << "Unable to open file.\n";
    }
}