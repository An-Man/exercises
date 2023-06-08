// Ass. 1_4_1 Exercise 2
// Factorial of a number

#include <iostream>
#include <cassert>

int factorial(int x) {
    int fact {1};

    for (int i = 1; i <= x; ++i) {
        fact *= i;
    }

    return fact;
}

bool is_positive(int x)
{
    return(x >= 0);
}

int main ()
{
    std::cout << "Enter an integer: ";
    int input {};
    std::cin >> input;

    assert((is_positive(input)) && "FAIL: number not positive");

    std::cout << "Factorial of " << input << " is " << factorial(input) << '\n';

    return 0;
}