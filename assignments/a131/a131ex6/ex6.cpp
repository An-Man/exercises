#include <iostream>

int modify(int input)
{
    input = 5; // assign 5 to int input 

    return input;
}

int main()
{
    int x {0}; // declare x

    std::cout << x << '\n'; // print x (0)

    std::cout << modify(x) << '\n'; // call function with x as argument, prints 5

    std::cout << x << '\n'; // print x again, prints 0 again

    return 0;
}