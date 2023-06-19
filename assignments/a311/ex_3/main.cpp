/* 
3. Create a program that will print out a list of names. 
The user can choose a person in the list by inputting the
user index and their name gets printed out. If the user tries
to choose a user that is outside of the index, throw an
appropriate exception.  
*/

#include <iostream>
#include <stdexcept>
#include <vector>

int get_index_num()
{
    std::cout << "Enter an index to print name: ";
    int input {};
    std::cin >> input;

    return input;
}

// function returns name as a string by index
std::string get_name_by_index(std::vector<std::string>& vector, int& index)
{
    if (index < 0 || index >= vector.size()) {    // index must be inside vector size limits
        throw std::runtime_error("Index number out of range!");
    }

    std::string name = vector[index];
    
    return name;  
}

int main()
{
    std::vector<std::string> names {"John", "Jill", "Jane", "Joe", "Jack", "Jedi", "Jolene"};
    
    int index = {get_index_num()};

    try {
        std::cout << "Name at index " << index << " is: "
        << get_name_by_index(names, index) << '\n';
    } catch (std::runtime_error const& error) { // exception caught if index num out of bounds
        std::cout << "Error: " << error.what() << '\n';
    }

    return 0;
}
