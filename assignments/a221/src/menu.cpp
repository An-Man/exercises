#include "../includes/food.h"
#include "../includes/menu.h"
#include <iostream>
#include <vector>

void add_to_menu(std::vector<Food>& menu, Food food)
{
menu.push_back(food);
}

void print_menu(std::vector<Food>& menu)
{
    std::cout << "--- MENU ---\n";
    
    for (auto& n : menu)
        {
        std::cout << n.name << " - " << n.price << " euros \n";
        }
}