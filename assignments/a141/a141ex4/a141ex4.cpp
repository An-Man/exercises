// Ass. 1_4_1 Exercise 4
// division

#include <iostream>
#define NDEBUG // to ignore assert --> result "inf" when dividing by zero
#include <cassert>


double divide(int x, int y) 
{
    assert((y != 0) && "FAIL: division by 0 not allowed");
    return ((static_cast<double>(x)) / (static_cast<double>(y)));
}

int main ()
{
    int x {3};
    int y {0}; 

    std::cout << (divide(x, y)) << '\n';    

    return 0;
}