/* 
Assignment 3_2_3
Exercise 1

Write a recursive function that takes a string
as input and returns the string reversed. 
*/
#include <string>
#include <iostream>
#include <vector>

std::string reverse(std::string str)
{
    if (str.size() == 0) {
        return "";
    }
    
    return reverse(str.substr(1)) + str[0];
    // Makes a substring of the string from second character and concatenates
    // it with first character of str, calling:
    // reverse("amburger") + 'H'
    // reverse("mburger") + 'a' ...
    // and returns them from end to beginning as the call stack unwinds
}

int main()
{
    std::cout << reverse("Hamburger") << '\n';

    return 0;
}