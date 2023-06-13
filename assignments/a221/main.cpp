/* 
Exercise 1: Ordering system for a restaurant

Set up your program and create the first set of data

To start, your menu ordering program should have a struct called Food. The members for the struct should contain the name, price and ingredients. Your program needs to be able to print out all of the attributes. Divide the program into multiple source and header files as needed.
Test your program by creating a food item and printing out its ingredients in the main.cpp file.
*/

#include <iostream>
#include <string>
#include "food.h"
// #include "menu.h"
#include <vector>

int main()
{
    Food init_food { "sausage", 15, "meat" };

    print_ingredients(init_food);

    std::vector<Food> menu;

    menu.push_back(create_new_food());

    for (auto& n : menu)
        {
        std::cout << n.name << "\n";
        std::cout << n.price << "\n";
        std::cout << n.ingredients << "\n";
        }

    return 0;

    // print_menu();

}