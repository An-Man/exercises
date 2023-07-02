#include "../includes/food.h"  // toimii vain jos polku kerrottu
#include <iostream>
#include <string>

void print_food_data(Food& food) // used only in earlier versions of exercise
{
    std::cout << "Ingredients of " << food.name << " are: " << food.ingredients << "\n";
    std::cout << "Price of " << food.name << " is: " << food.price << "\n";
}

Food create_new_food() // used only in earlier versions of exercise
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
