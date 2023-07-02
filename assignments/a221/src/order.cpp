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
    
    for (auto& food : order)
        {
        std::cout << food.name << ", " << food.price << " euros \n";
        }
}

// calculates total price for order
int calc_order_price(std::vector<Food>& order)
{
    int sum {};
    for (auto& food : order)
        {
            sum += food.price;
        }
    return sum;
}
