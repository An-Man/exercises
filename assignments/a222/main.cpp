/* 
Assignment 2_2_2 Ex 1 -
Calculator
*/

#include <iostream>
#include "utility.h"
#include "cxxopts.hpp"

int main(int argc, char* argv[])
{
    cxxopts::Options options("Calculator", "A simple calculator");

    options.add_options() 
        ("i,integer", "Int param", cxxopts::value<int>())
        ("a, add", "Addition", cxxopts::value<std::string>())
        ("s, substract", "Substract", cxxopts::value<std::string>())
        ("m, multiply", "Multiply", cxxopts::value<std::string>())
        ("d, divide", "Division", cxxopts::value<std::string>())
        // ("h, help", "Help", cxxopts::value<std::string>())
        ;
    
    auto result {options.parse(argc, argv)};

    if (result.count("add")
    {
        
    })
    else if (result.count("help")
    {

    }


    while (true)
    {    
        std::cout << " - Calculator - " << "\n";
        int first { get_integer() };
        char op { get_operator() };
        int second { get_integer() };
        
        if (op == '+')
        {
            std::cout << "= " << add(first, second) << "\n\n";
            
        }
        else if (op == '-')
        {
            std::cout << "= " << substract(first, second) << "\n\n";
            
        }
        else if (op == '*')
        {
            std::cout << "= " << multiply(first, second) << "\n\n";
            
        }
        else if (op == '/')
        {
            if ( second == 0 )
            {
                std::cout << "Division by 0 not allowed.\n\n";
            } 
            else 
            {
            std::cout << "= " << divide(first, second) << "\n\n";
            }
        }
        else 
        {
            std::cout << "Invalid operator!\n\n";  
        }
    }
    return 0;
}