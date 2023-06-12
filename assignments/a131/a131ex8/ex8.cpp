#include <iostream>

void print_array(const int *arr, int size)
{
    for (int i{0}; i < size; ++i)
    {
    std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main()
{
    int size {5};

    int* d_array { new int[size]{} };

    print_array(d_array, size); // prints values (set to 0)

    delete[] d_array;

    return 0;
}