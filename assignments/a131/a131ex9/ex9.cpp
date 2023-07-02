#include <iostream>

int get_new_x()
{
    static int s_x{0}; //static variable s_x increments by every call
    return s_x++;
}

int main()
{
    
    std::cout << get_new_x() << '\n'; // call function to return first 0
    std::cout << get_new_x() << '\n'; // then 1
    std::cout << get_new_x() << '\n'; // then 2 ...

    return 0;
}