#include <iostream>

int main()
{
    int x {1};

    while (x == 1)
    {
        int y {5};
        std::cout << y << '\n'; // prints y inside block
        break;
    }

    std::cout << y << '\n'; // does not work, y defined inside block

    return 0;
}