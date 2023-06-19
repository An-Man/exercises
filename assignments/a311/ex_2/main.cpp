/* 
2. Write a program that reads in a list of integers
and finds the maximum value. Return an error code if 
the list is empty.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int find_max_value(std::vector<int>& vector)
{
    std::vector<int>::iterator result; // an iterator to find the value
    result = std::max_element(vector.begin(), vector.end());

    if (vector.size() == 0) // if vector is empty, returns an "error code" -1000
    {    
        return -1000;
    }

    return *result; //returns value where the iterator points at
}

int main()
{
    std::vector<int> vector_full {1, 5, 7, 10, 20, 24};
    std::vector<int> vector_empty {};
    
    int max {find_max_value(vector_full)};      // these two statements are used to choose
    //int max {find_max_value(vector_empty)};   // either the empty or "full vector" for testing

    if (max == -1000)
    {
        std::cout << "The list was empty.\n";
    } else {
        std::cout << "Maximum value is: " << max << '\n';
    }

    return 0;
}