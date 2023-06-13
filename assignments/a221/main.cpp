/* 
Exercise 1: Ordering system for a restaurant

Set up your program and create the first set of data

To start, your menu ordering program should have a struct called Food. The members for the struct should contain the name, price and ingredients. Your program needs to be able to print out all of the attributes. Divide the program into multiple source and header files as needed.
Test your program by creating a food item and printing out its ingredients in the main.cpp file.
*/

#include "food.h"
#include "menu.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    Food init_food { "sausage", 15, "meat" };

    std::vector<Food> menu;

    add_to_menu(menu, init_food);

    add_to_menu(menu, create_new_food());
    add_to_menu(menu, create_new_food());

    print_menu(menu);

    return 0;

}
