/* 
Assignment 3_2_3
Exercise 3

Write a recursive function to calculate the power of a number.
Your recursive function should be able to handle any size of x 
to the power of n.
*/

#include <iostream>

long double power(long double x, int n)
{
    if (n == 0) {
        return 1;
    }
        
    return x * power(x, n - 1); // x times x to power of n, n decreases by 1
}

int main()
{
    std::cout << power(4.0, 5) << '\n';

    return 0;
}