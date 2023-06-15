#include <filesystem>
#include "../includes/getsize.h"
#include <iostream>

// This .cpp is for Exercise 5: to make a function that
// calculates the size of the text files in a directory;
// in this case the directory where the executable is.

namespace fs = std::filesystem;

void iterate_directory(fs::path& current_directory)
{
    for (const auto& item : fs::directory_iterator(current_directory))
    {
        if (!item.is_directory() && fs::path(current_directory/item).extension() == ".txt")
            std::cout << item.path() << " file size: " << item.file_size() << "\n"; 
    }
}

void get_text_files_size()
{
    fs::path current_path {fs::current_path()};
    iterate_directory(current_path);
}
