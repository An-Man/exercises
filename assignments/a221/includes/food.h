#include <string>

#ifndef FOOD_H
#define FOOD_H

struct Food
{
    std::string name {};
    int price {};
    std::string ingredients {};
};

Food create_new_food();

void print_food_data(Food& food);

#endif