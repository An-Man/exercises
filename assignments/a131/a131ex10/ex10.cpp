#include <iostream>

namespace avaruus
{
    int luku {2}; // variable inside namespace
}

int main()
{
    int luku {5}; // variable defined in a function

    std::cout << luku << '\n'; // prints the local scope variable
    std::cout << avaruus::luku << '\n'; // prints the variable in namesp avaruus

    return 0;
}