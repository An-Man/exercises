/* 
Assignment 2_2_2 Ex 1 -
Calculator
*/

#include <iostream>
#include "utility.h"

int main()
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