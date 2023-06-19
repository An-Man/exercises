/* 
1. Write a program that performs a division operation. The user 
should input two numbers. the program should catch and handle 
the possibility of a division by zero error.  
*/

#include <iostream>
#include <stdexcept>

int get_integer()
{
    std::cout << "Enter an integer: ";
    int a {};
    std::cin >> a;

    return a;
}

double divide_a_b(int a, int b)
{
    if (b == 0) {   // if divider is 0, throw an exception
        throw std::runtime_error("Division by 0 not allowed");
    }
  
    return (static_cast<double>(a) / static_cast<double>(b));
}

int main()
{
    int a {get_integer()};
    int b {get_integer()};

    try {
        std::cout << divide_a_b(a, b) << '\n'; //this prints ok if b is not 0
    } catch (std::runtime_error const& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    
    return 0;
}