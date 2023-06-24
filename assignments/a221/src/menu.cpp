#include "../includes/food.h"
#include "../includes/menu.h"
#include <iostream>
#include <vector>

void add_to_menu(std::vector<Food>& menu, Food food)
{
menu.push_back(food);
}

Food get_food_from_menu(std::vector<Food>& menu, std::string input)
{
    for (auto& food : menu) {
        if (food.name == input) {
        return food;
        }
    }
    Food empty_food {};
    return empty_food;  // if food not found, returns empty
}

void print_menu(std::vector<Food>& menu)
{
    std::cout << "--- MENU ---\n";
    
    for (auto& food : menu)
        {
        std::cout << food.name << " - " << food.price << " euros \n";
        }

    std::cout << "-------\n";
}