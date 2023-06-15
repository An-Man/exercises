#include "../includes/getwords.h"

// This .cpp is for Exercise 3: to take a file name as a command-line
// argument and print number of words in the text file.

void get_words(std::string filename)
{
    std::ifstream input_file {filename};

    if (input_file.is_open())
    {
        int word_count {0};
        std::string word {};

        while (input_file >> word) {
            word_count++;
        }
        std::cout << "File word count is: " << word_count << '\n';
    } 
    else 
    {
        std::cout << "Unable to open file.\n";
    }
}