#include "../includes/utility.h"
#include <iostream>

int get_integer()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

char get_operator()
{
    std::cout << "Enter +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

int add(int a, int b)
{
    return (a + b);
}

int substract(int a, int b)
{
    return (a - b);
}

int multiply(int a, int b)
{
    return (a * b);
}

double divide(int a, int b)
{
    return (static_cast<double>(a) / static_cast<double>(b));
}

