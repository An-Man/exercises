// Ass. 1_4_1 Exercise 5
// square root

#include <iostream>
#define NDEBUG // to ignore assert --> causes result -nan
#include <cassert>

bool play_game (int x) 
{
    assert((x >= 1) && "Game over: out of range"); // fail if x is 0 or less
    assert((x <= 100) && "Game over: out of range"); // fail if x is 0 or less

    return ((x >= 1) && (x <= 100));
}

int main ()
{
    std::cout << "Enter an integer: ";
    int input {};
    std::cin >> input;

    if (play_game(input)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose.\n";    
    }
    
    return 0;
}