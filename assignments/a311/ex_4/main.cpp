/*
4. Overload a function called process_data(). One version should 
accept an integer and the other a string. If the integer is negative 
or the string contains any non-alphabet characters, throw an exception.
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

void process_data(int number) // function with int parameter
{
    if (number < 0) {
        throw std::runtime_error("Negative number!");
    }

    std::cout << "Processed data: " << number << '\n'; // just to show it passed
}

void process_data(std::string string) //function with string parameter
{
    bool alpha {true};

    for (char c : string) { // checks if string is all letters
        if (!std::isalpha(c)) {
            alpha = false;
        }
    }
     
    if (!alpha) {   // if divider is 0, throw an exception
        throw std::runtime_error("Not alphabetic!");
    }

    std::cout << "Processed data: " << string << '\n';
}

int main()
{
    int num {5};
    std::string string {"stick"};

    try {
        process_data(string); // string or num can be given as an argument
    } catch (std::runtime_error const& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    
    return 0;
}