#ifndef UTILITY_H
#define UTILITY_H
#include <vector>

int get_integer();

char get_operator();

int add(int a, int b);
int add(std::vector<int>);
int substract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

#endif