/* 
Exercise 1: Ordering system for a restaurant

Set up your program and create the first set of data

To start, your menu ordering program should have a struct called Food. The members for the struct should contain the name, price and ingredients. Your program needs to be able to print out all of the attributes. Divide the program into multiple source and header files as needed.
Test your program by creating a food item and printing out its ingredients in the main.cpp file.
*/

#include "food.h"
#include "menu.h"
#include "order.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<Food> menu;
std::vector<Food> order;

int main()
{
    Food init_food { "Sausage", 15, "Meat" };
    Food init_food2 { "Soup", 9, "Vegetables"};
    Food init_food3 { "Bread", 5, "Flour"};

    add_to_menu(menu, init_food);
    add_to_menu(menu, init_food2);
    add_to_menu(menu, init_food3);

    while (true)
    {
        std::cout << "Please choose:\n"
                    "(1) View menu\n"
                    "(2) Add item to order\n"
                    "(3) View order\n"
                    "(4) Exit\n";
        int choice {};
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                print_menu(menu);
                break;
            }
            case 2:
            {
                std::cout << "Type food name to add: ";
                std::string input;
                std::cin >> input;
  
                add_to_order(order, get_food_from_menu(menu, input));
                break;
            }
            case 3:
            {
                print_order(order);
                std::cout << "Order total price: " << calc_order_price(order) << '\n';
                std::cout << "------\n";
                break;
            }
            case 4:
            {
                std::cout << "Exiting program." << '\n'; // quits program
                return 0;
            }
            default:
            break;
        }
    }
    
    return 0;

}
