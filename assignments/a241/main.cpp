#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: Filename missing." << '\n';
        return 1;
    }

    std::string filename = argv[1];

    std::ifstream input_file("lorem_ipsum.txt");

    if (input_file.is_open()) {
        std::string text;
        while (input_file >> text) {
            std::cout << text << '\n';
        }
    } else {
        std::cout << "Unable to open file.\n";
    }


}