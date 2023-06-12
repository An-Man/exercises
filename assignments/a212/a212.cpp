/*
Exercise 1:

Create a vector<int> with 10 numbers in it. 
Use std::partition to separate the even and 
odd numbers. Print out the vector after partitioning.
*/

/* 
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> vek {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int elem : vek)            // print out vector vek
        std::cout << elem << ' ';

    auto it = std::partition(vek.begin(), vek.end(), [](int i) {return i % 2 == 0;});

    std::cout << "\nPartitioned vector: ";
    std::copy(std::begin(vek), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "* ";
    std::copy(it, std::end(vek), std::ostream_iterator<int>(std::cout, " "));

    // printed partitioned: 10 2 8 4 6 * 5 7 3 9 1

    return 0;
} 
*/




// Exercise 2:
// 
// Create two std::vector<int> and fill them with random
// amount of random numbers. Use std::set_intersection to find 
// common elements between them.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print_vec(std::vector<int>& vecc)
{
        for (int elem : vecc)            // print out vector vek
        std::cout << elem << ' ';
}

int main()
{
    std::vector<int> vek1 {1, 3, 4, 5, 6, 7, 9, 10};
    std::vector<int> vek2 {11, 2, 4, 8, 16, 17};

    print_vec(vek1);
    print_vec(vek2);
    
    std::sort(vek1.begin(), vek2.end());
    std::sort(vek2.begin(), vek2.end());

    print_vec(vek1);
    print_vec(vek2);

    

    // std::set_intersection

    return 0;
}
