// Ass. 1_4_1 Exercise 5
// square root

#include <iostream>
#define NDEBUG // to ignore assert --> causes result -nan
#include <cassert>
#include <cmath>


double square_root(double x) 
{
    assert((x >= 0) && "FAIL: negative number"); // fail if x is negative

    return std::sqrt(x);
}

int main ()
{
    std::cout << "Enter an integer: ";
    int input {};
    std::cin >> input;

    std::cout << "Square root of " << input << " is " << square_root(input) << '\n';    

    return 0;
}