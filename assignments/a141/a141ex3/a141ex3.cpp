// Ass. 1_4_1 Exercise 3
// sum of two integers, positive

#include <iostream>
#define NDEBUG     // must be defined before including cassert
#include <cassert>


int sum_of(int x, int y) 
{
    return (x + y);
}

bool is_positive(int x)
{
    return(x >= 0);
}

int main ()
{
    int a {-2};
    int b {-4};

    int sum {sum_of(a, b)};

    assert((is_positive(sum)) && "FAIL: number not positive"); // is ignored by NDEBUG

    return 0;
}