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
    for (auto& n : menu)
        if (n.name == input)
        return n;
        // entä jos ei löydy?
}

void print_menu(std::vector<Food>& menu)
{
    std::cout << "--- MENU ---\n";
    
    for (auto& n : menu)
        {
        std::cout << n.name << " - " << n.price << " euros \n";
        }

    std::cout << "-------\n";
}