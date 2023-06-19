#include "randomnum.h"
#include <random>

int random_1000to2000()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r1000to2000 { 1000, 2000 };

    return r1000to2000 (mt);
}

int random_1to3()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution r_1to3 { 1, 3 };

    return r_1to3 (mt);
}

float random_float1_20()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_real_distribution<float> rf_1to20 { 1.0, 20.0 };

    return rf_1to20 (mt);    
}