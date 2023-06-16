/* 
Assignment 2_2_2 - Calculator

From the command line the program calculates an operation of _two_ integers
given as arguments after the operation argument, separated by comma. Example:
./calculator --add 3,4
If no arguments are given, the program uses an interface loop.
*/

#include <cassert>
#include <iostream>
#include <vector>
#include "utility.h"
#include "cxxopts.hpp"

int main(int argc, char* argv[])
{
    // one argument is ok, 3 is ok, 2 not ok and more than 3 not ok
    assert(argc != 2 && "Give an argument and two integers separated by comma");
    assert(argc < 4 && "Give an argument and two integers separated by comma");
    
    
    // if three arguments are given: program name, operation and two integers
    if (argc == 3 )
    {
        cxxopts::Options options("Calculator", "A simple calculator"); 

        options.add_options() // Options for operations from command line
        ("a, add", "Addition", cxxopts::value<std::vector<int>>())
        ("s, substract", "Substract", cxxopts::value<std::vector<int>>())
        ("m, multiply", "Multiply", cxxopts::value<std::vector<int>>())
        ("d, divide", "Division", cxxopts::value<std::vector<int>>())
        ;
    
        auto result {options.parse(argc, argv)}; // parses command line arguments

        if (result.count("add")) // if add-argument included, get values from vector
        {
            const auto args = result["add"].as<std::vector<int>>();

            assert(args.size() == 2 && "Give two integers after operation argument");

            int arg1 {args[0]};
            int arg2 {args[1]};

            std::cout << add(arg1, arg2) << '\n';
        }
         
        else if (result.count("substract"))
        {
            const auto args = result["substract"].as<std::vector<int>>();

            assert(args.size() == 2 && "Give two integers after operation argument");

            int arg1 {args[0]};
            int arg2 {args[1]};

            std::cout << substract(arg1, arg2) << '\n';
        }
        else if (result.count("multiply"))
        {
            const auto args = result["multiply"].as<std::vector<int>>();

            assert(args.size() == 2 && "Give two integers after operation argument");

            int arg1 {args[0]};
            int arg2 {args[1]};

            std::cout << multiply(arg1, arg2) << '\n';
        }
        else if (result.count("divide"))
        {
            const auto args = result["divide"].as<std::vector<int>>();
            int arg1 {args[0]};
            int arg2 {args[1]};

            assert(args.size() == 2 && "Give two integers after operation argument");

            assert(arg2 != 0 && "Division by 0 not allowed.\n");
            
            std::cout << divide(arg1, arg2) << '\n';           
        }
    }  
    else if ( argc == 1) // when only program name called
    {
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
                if ( second == 0 ) // here no assert to let user continue
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
                break;
            }
        }
    }   
    return 0;
}