/* Exercise 1:

Create an array with 10 random numbers in it. 
Your program should also be able to output the elements in the array.
*/

#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> ar {2, 4, 19, 3, 1, 7, 8, 5, 6, 11};

    for(const auto& num : ar)
        std::cout << num << ", ";

    return 0;
}



/* Exercise 2:

Add a function that receives an std::array and a number, 
and checks whether the number is in the array. 
The function should return a boolean value.
*/

#include <iostream>
#include <array>

bool contains_num (std::array<int, 10> arr, int num)
{
    for(const auto& s : arr) {
        if (s == num) {
            return true;
        } 
        
    }
    return false;
}    

int main()
{

    std::array<int, 10> arr {2, 4, 19, 3, 1, 7, 8, 5, 6, 11};
    int num {2};
    
    std::cout << contains_num(arr, num) << '\n';

    return 0;
}


/*
Exercise 3:

Create a program that has a function that receives
the sum of all the elements in an array. The vector
will be filled automatically with different numbers.
*/

#include <iostream>
#include <array>
#include <numeric>

int sum(std::array<int, 10> arr)
{
    int sum {std::accumulate(arr.begin(), arr.end(), 0)};
    return sum;
}

int main()
{
    std::array<int, 10> arr {2, 4, 19, 3, 1, 7, 8, 5, 6, 11};
    
    std::cout << sum(arr) << '\n';

    return 0;
}


/* 
Exercise 4:

Create a  program that that prints out the product of all elements in an array
*/


#include <functional>
#include <iostream>
#include <array>
#include <numeric>

int product(std::array<int, 10> arr)
{
    int product {std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<int>())};
    return product;
}

int main()
{
    std::array<int, 10> arr {2, 4, 19, 3, 1, 7, 8, 5, 6, 11};
    
    std::cout << product(arr) << '\n';

    return 0;
}



/* Exercise 5:

Create a program that will ask the user for the size of a vector. */


#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter size for a vector: ";
    int size {};
    std::cin >> size;

    std::vector<int> vektor; // create a vector

    vektor.resize(size); // resize vector to user-given size

    std::cout << vektor.size() << '\n'; 

    vektor.resize(6);  // resize again and force size to 6

    std::cout << vektor.size() << '\n';
}

/* Exercise 6:

Create a function that will output the smallest and largest number in the list. */

#include <algorithm>
#include <iostream>
#include <vector>

void min_and_max(std::vector<int> v)
{
    
    const auto [min, max] = std::minmax_element(begin(v), end(v)); // palauttaa iteraattorit min ja max

    std::cout << *min << " is smallest. \n"; // *min koska on pointteri joka osoittaa pienimpään arvoon
    std::cout << *max << " is largest. \n";
}

int main()
{
    std::vector<int> vektor {2, 4, 19, 3, 1, 7, 8, 5, 6, 11};

    min_and_max(vektor);

    return 0;
}

/*
Exercise 7:

Create a function that will remove all instances
of a value from the vector and inform
if the value was found and removed.
*/

#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v) // tulostaa vektorin
{
    for (int i : v)
        std::cout << i << " ";
    std::cout << '\n';
}

void remove_all_cases(std::vector<int>& v, int rem) // poistaa elementit joiden arvo rem
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end();)
    {
        if (*it == rem)
            it = v.erase(it);
        else
            ++it;
    }   
}

int main()
{
    std::vector<int> vektor {2, 4, 19, 3, 1, 7, 8, 19, 6, 11};
    int rem {19};

    print_vector(vektor);           // tulostaa vektorin
    remove_all_cases(vektor, rem);  // poistaa elementit arvolla 19
    print_vector(vektor);           // tulostaa uudelleen

    return 0;
}