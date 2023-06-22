#include "../include/pascal_functions.h"
#include <iostream>


// Function to print the Pascal's Triangle
void print_pascal(int row_num)
{
    for (int i{1}; i <= row_num; i++)
    {
        int coef {1};
        for(int k {row_num - i}; k > 0; k--)
        {
            std::cout << " ";
        }
        for (int j{1}; j <= i; j++)
        {
            std::cout << coef << " ";
            coef = coef*(i-j)/j;        // tästä funktio jota voi testata!
        }
        std::cout << "\n";
    }
}