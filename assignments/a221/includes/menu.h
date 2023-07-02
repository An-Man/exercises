#include "food.h"
#include <vector>

#ifndef MENU_H
#define MENU_H

void add_to_menu(std::vector<Food>& menu, Food food);

Food get_food_from_menu(std::vector<Food>& menu, std::string input);

void print_menu(std::vector<Food>& menu);

#endif