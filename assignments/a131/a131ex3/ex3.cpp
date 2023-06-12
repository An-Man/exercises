#include <iostream>

void calculate()
{
    int x {5}; //declare variable x inside function

    std::cout << x << '\n'; //print x works here
}

int main()
{
    std::cout << x << '\n'; //does not work here as x is undefined

    return 0;
}