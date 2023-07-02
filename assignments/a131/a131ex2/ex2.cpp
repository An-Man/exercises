#include <iostream>


int main()
{
    for (int i {0}; i < 5; ++i)
    {
        std::cout << i << '\n'; //loop iterates and prints value of i
    }
    
    i = 7; // error: "identifier "i" is undefined" if we try to access i here

    return 0;
}