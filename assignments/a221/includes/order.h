#include "food.h"
#include <vector>

#ifndef ORDER_H
#define ORDER_H

void add_to_order(std::vector<Food>& order, Food food);

void print_order(std::vector<Food>& order);

int calc_order_price(std::vector<Food>& order);


#endif