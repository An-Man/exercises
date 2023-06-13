#ifndef FOOD_H
#define FOOD_H

#include <iostream>

struct Food
{
    std::string name {};
    int price {};
    std::string ingredients {};

};

Food create_new_food();

void print_ingredients(Food& food);

#endif