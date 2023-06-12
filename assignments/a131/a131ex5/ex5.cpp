#include <iostream>

int main()
{
    int x {1}; // declare x

    std::cout << x << '\n'; // print x

    if (x == 1) // modify x inside if statement
    {
        x -= 1;
    }

    std::cout << x << '\n'; // print x again

    return 0;
}