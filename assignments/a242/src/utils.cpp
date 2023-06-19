#include "../includes/utils.h"
#include <random>

int random_1000to9999()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r1000to9999 { 1000, 9999 };

    return r1000to9999 (mt);
}

int random_100k_200k()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r_100k_200k { 100000, 200000 };

    return r_100k_200k (mt);
}

int random_0_255()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r_0_255 { 0, 255 };

    return r_0_255 (mt);    
}