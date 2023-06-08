#include <cassert>
#include <sstream>
#include <cctype>
#include <iostream>

// Assignment 1_4_1 Exercise 1; assert and string challenge


std::string capitalize_string(std::string str) // function that capitalises words
{
    std::stringstream ss(str); // stringstream operation
    std::string word;
    std::string result;

    while (ss >> word) { // ss inputs characters into words using whitespace as limit

        if (std::isalpha(word[0])) {    // if a word begins with a letter
            if (std::islower(word[0]))  // that is lower case
            {
                word[0] = std::toupper(word[0]); // make it upper case 
            }
            for (size_t i = 1; i < word.length(); ++i)  // and make rest of the word lower case
            {
                word[i] = std::tolower(word[i]);
            }

        }
        result += word + " "; // add word to result string
    }

    result = result.substr(0, result.length() - 1); // remove extra whitespace

    return result;
}

int main() 
{
    assert("The String Challenge" == capitalize_string("the string challenge"));
    
    std::cout << "Test 1 passed" << std::endl;
    
    assert("This Is An Example, Should Work!" == capitalize_string("THIS IS an ExamplE, should wORk!"));
    
    std::cout << "Test 2 passed" << std::endl;
}