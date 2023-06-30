/* 
Assignment 3_2_3
Exercise 2
Write a recursive function that finds the Greatest Common 
Divisor of two numbers. Hint: you can use the Euclidean algorithm.
*/


#include <iostream>

int calc_gcd(int a, int b)
{
    if (a == 0) {
        return b;
    }
    return calc_gcd(b % a, a); // modulus from b/a and a
}

int main()
{
    std::cout << calc_gcd(1500, 720) << '\n';

    return 0;
}