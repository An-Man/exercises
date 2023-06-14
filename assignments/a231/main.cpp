// Exercise 1:
//
// Write a program that sorts an
// array of integers in ascending order using std::sort


#include <algorithm>
#include <array>
#include <iostream>

void print_array(std::array<int, 5>& arr)
{
    for (auto& n : arr)
    std::cout << n << ", ";
    
    std::cout << '\n';
}

int main()
{
    std::array<int, 5> arr {5, 2, 0, 7, 4};

    print_array(arr);

    std::sort(arr.begin(), arr.end());  // sort in ascending order

    print_array(arr);

}


//  Exercise 2:
//
//  Use std::sort with std::greater<int>() to sort 
//  an array of integers in descending order. 


#include <algorithm>
#include <array>
#include <iostream>

void print_array(std::array<int, 5>& arr)
{
    for (auto& n : arr)
    std::cout << n << ", ";
    
    std::cout << '\n';
}

int main()
{
    std::array<int, 5> arr {5, 2, 0, 7, 4};

    print_array(arr);

    // sort in descending order
    std::sort(arr.begin(), arr.end(), std::greater<int>()); 

    print_array(arr);

}



// Exercise 3:
//
// Create a vector of floating-point numbers and sort it. 
// Experiment with different sizes of vectors and number ranges.


#include <algorithm>
#include <vector>
#include <iostream>

void print_vector(std::vector<double>& vect)
{
    for (auto& n : vect)
    std::cout << n << ", ";
    
    std::cout << '\n';
}

int main()
{
    std::vector<double> vect {5.2, 2.5, 0.3, 7.6, 2.5, 2.6, 4.8};

    print_vector(vect);

    // sort in ascending order
    std::sort(vect.begin(), vect.end()); 

    print_vector(vect);

}


// Exercise 4:
//
// Create a vector of strings and sort them in lexicographical 
// order. Also, sort them based on the string length.



#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print_vector(std::vector<std::string>& vect)
{
    for (auto& n : vect)
    std::cout << n << ", ";
    
    std::cout << '\n';
}

bool sort_by_length(std::string& str1, std::string& str2)
{
    return (str1.length() < str2.length());
}

int main()
{
    std::vector<std::string> vect {"Hyacinth", "Richard", "Onslow", "Emmet", "Elizabeth"};

    print_vector(vect);

    std::ranges::sort(vect); // in c++20 only

    print_vector(vect);

    // sort by string length using custom function
    std::ranges::sort(vect, sort_by_length); 

    print_vector(vect);

} 




// Exercise 5:
// Create a vector of pairs where each pair contains 
// a string and an integer (like a name and an age). 
// Sort the vector based on the integer. 


#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

void print_vector(std::vector<std::pair<std::string, int>>& vect)
{
    for (auto& pair : vect)
    std::cout << pair.first << ", " << pair.second << '\n';
}

bool sort_by_age(std::pair<std::string, int>& p1, std::pair<std::string, int>& p2)
{
    return (p1.second < p2.second);
}

int main()
{
    std::vector<std::pair<std::string, int>> vect {
        {"Bob" , 45},
        {"Jane", 27},
        {"Mike", 15},
    };

    print_vector(vect);

    std::ranges::sort(vect, sort_by_age); // ranges::sort only in c++20

    std::cout << "After sort operation: \n";
    print_vector(vect);

    return 0;

}



// Exercise 7:
//
// Use std::partial_sort to find the top 5 
// elements from a vector of integers. The vector 
// should have at least 20 elements. 


#include <algorithm>
#include <iostream>
#include <vector>

void print_vector(std::vector<int>& vect)
{
    for (auto& n : vect)
    {
        std::cout << n << ", ";
        
    }
    
    std::cout << '\n';
}

int main()
{
    std::vector<int> vect {
        2, 30, 5, 7, 3, 9, 6, 37, 21, 13,
        24, 25, 4, 3, 2, 1, 8, 9, 20, 34,
        56, 33, 12
    };

    print_vector(vect);

    // Sort partially by finding 5 largest; order of the remaining numbers is "unspecified"
    std::partial_sort(vect.begin(), vect.begin() + 5, vect.end(), std::greater<int>());

    print_vector(vect);

} 



// Exercise 8:
//
// Create a vector of pairs with repeating first elements. 
// After sorting, check if the pairs with equal first 
// elements maintain their relative order.


#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

void print_vector(std::vector<std::pair<std::string, int>>& vect)
{
    for (auto& pair : vect)
    std::cout << pair.first << ", " << pair.second << '\n';
}

bool sort_by_name(std::pair<std::string, int>& p1, std::pair<std::string, int>& p2)
{
    return (p1.first < p2.first);
}

int main()
{
    std::vector<std::pair<std::string, int>> vect {
        {"Bob" , 45},
        {"Jane", 27},
        {"Mike", 15},
        {"Bob", 32},
        {"Gob", 13},
        {"Jane", 79},
    };

    print_vector(vect);

    // sort vector by first element of pair (name)
    std::sort(vect.begin(), vect.end(), sort_by_name);

    std::cout << "After sort operation: \n";
    print_vector(vect);  // in this case, equal elements preserved their order

    return 0;

}