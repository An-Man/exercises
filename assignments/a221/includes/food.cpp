#include <iostream>
#include <string>
#include "food.h"

void print_ingredients(Food& food)
{
    std::cout << "Ingredients of " << food.name << " are: " << food.ingredients << "\n";
}

Food create_new_food()
{
    std::cout << "Enter food name: ";
    Food new_food {};
    std::cin >> new_food.name;

    std::cout << "Enter food price: ";
    std::cin >> new_food.price;

    std::cout << "Enter food ingredient: ";
    std::cin >> new_food.ingredients;

    return new_food;
}