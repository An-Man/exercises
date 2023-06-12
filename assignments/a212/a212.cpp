/*
Exercise 1:

Create a vector<int> with 10 numbers in it. 
Use std::partition to separate the even and 
odd numbers. Print out the vector after partitioning.
*/

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

// Exercise 2:
// 
// Create two std::vector<int> and fill them with random
// amount of random numbers. Use std::set_intersection to find 
// common elements between them.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print_vec(const std::vector<int>& vecc)
{
        for (int elem : vecc)            // print out vector vek
            std::cout << elem << ' ';
        std::cout << '\n';
}

int main()
{
    std::vector<int> vek1 {5, 4, 9, 2, 4, 10};
    std::vector<int> vek2 {11, 2, 4, 8, 16, 17};

    std::cout << "Initial vectors:\n";
    print_vec(vek1);
    print_vec(vek2);
    
    std::cout << "Sorted vectors:\n";
    std::sort(vek1.begin(), vek1.end());
    std::sort(vek2.begin(), vek2.end());

    print_vec(vek1);
    print_vec(vek2);

    std::vector<int> v_intersection;
    std::set_intersection(vek1.begin(), vek1.end(), vek2.begin(), vek2.end(),
                          std::back_inserter(v_intersection));
    
    std::cout << "Common elements in the vectors:\n";
    print_vec(v_intersection);

    return 0;
} 


/*
Exercise 3:

Create a vector with 10 random elements in it. Rotate elements to the right by 3 positions with std::rotate.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print_vec(const std::vector<int>& vecc)
{
        for (int elem : vecc)            // print out vector vek
            std::cout << elem << ' ';
        std::cout << '\n';
}

int main()
{
    std::vector<int> vek1 {5, 4, 9, 2, 15, 10, 7, 3, 0, 6};

    print_vec(vek1);

    std::rotate(vek1.rbegin(), vek1.rbegin() + 3, vek1.rend());

    print_vec(vek1);

    return 0;

}

/*
Exercise 4:

Create a std::list<int> with 10 elements. Use std::adjacent_find
to find the first two adjacent elements that are equal. 
If no such elements exist, print a suitable message.
*/

#include <algorithm>
#include <iostream>
#include <list>

void print_list(const std::list<int>& list)
{
        for (int elem : list)            // print out vector vek
            std::cout << elem << ' ';
        std::cout << '\n';
}

int main()
{
    std::list<int> list {5, 4, 9, 2, 1, 10, 7, 3, 0, 6};

    print_list(list);

    auto i1 = std::adjacent_find(list.begin(), list.end());
 
    if (i1 == list.end())
        std::cout << "No matching adjacent elements\n";
    else
        std::cout << "The first adjacent pair of equal elements is at "
                  << std::distance(list.begin(), i1) << ", *i1 = "
                  << *i1 << '\n';

    return 0;

}

/*
Exercise 5:

Create a new program that will create a vector of random size, filled with random numbers between 1 and 100.
*/

#include <iostream>
#include <random>
#include <vector>

int generate_random1_100()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution random1to100 { 1, 100 };

    return random1to100 (mt);
}

int generate_random1_10()
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution random1to10 { 1, 10 };

    return random1to10 (mt);
}

void print_vec(const std::vector<int>& vecc)
{
        for (int elem : vecc)            // print out vector vek
            std::cout << elem << ' ';
        std::cout << '\n';
}

int main()
{

    std::vector<int> vek1(generate_random1_10());

    for (int& i : vek1)
        i = generate_random1_100();
    
    print_vec(vek1);

    return 0;
}


/*
Exercise 6:

Add a function that will output the smallest and largest number in the array.
*/

#include <algorithm>
#include <iostream>
#include <array>

void min_and_max(std::array<int, 10> arr)
{
    const auto [min, max] = std::minmax_element(begin(arr), end(arr)); // palauttaa iteraattorit min ja max

    std::cout << *min << " is smallest. \n"; // *min koska on pointteri joka osoittaa pienimpään arvoon
    std::cout << *max << " is largest. \n";
}

int main()
{
    std::array<int, 10> arr {2, 4, 200, 3, 1, 7, 8, 5, 6, 11};

    min_and_max(arr);

    return 0;
}
