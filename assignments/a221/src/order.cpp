#include "../includes/food.h"
#include <iostream>
#include <vector>

void add_to_order(std::vector<Food>& order, Food food)
{
order.push_back(food);
}

void print_order(std::vector<Food>& order)
{
    std::cout << "Current order: \n";
    
    for (auto& n : order)
        {
        std::cout << n.name << ", " << n.price << " euros \n";
        }
}

int calc_order_price(std::vector<Food>& order)
{
    int sum {};
    for (auto& n : order)
        {
            sum += n.price;
        }
    return sum;
}
