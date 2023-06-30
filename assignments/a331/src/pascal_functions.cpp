#include "../include/pascal_functions.h"
#include <iostream>

// to calculate the coefficient for drawing the middle numbers
int calculate_coef(int coef, int i, int j)
{
    return (coef*(i-j)/j);
}

// Function to print the Pascal's Triangle
void print_pascal(int row_num)
{
    for (int i{1}; i <= row_num; i++) // row loop
    {
        int coef {1};
        for(int k {row_num - i}; k > 0; k--) // buffer/padding loop
        {
            std::cout << " ";
        }
        for (int j{1}; j <= i; j++) // print numbers 1 + coefficient of 1
        {
            std::cout << coef << " ";
            coef = calculate_coef(coef, i, j);
        }
        std::cout << "\n";
    }
}