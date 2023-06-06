#include <cctype>
#include <iostream>
#include <string>

std::string get_password()
{
    std::cout << "Enter a strong password: ";
    std::string passwd;
    std::cin >> passwd;

    return passwd;
}

bool has_lower(std::string str)
{
    int length = str.length();
    bool lower {false};

    for (int i = 0; i < length; ++i)
        if (std::islower(str[i]))      
            lower = true;
        
    return lower;
}

bool has_upper(std::string str)
{
    int length = str.length();
    bool upper {false};

    for (int i = 0; i < length; ++i)
        if (std::isupper(str[i]))      
            upper = true;
        
    return upper;
}

bool has_digit(std::string str)
{
    int length = str.length();
    bool digit {false};

    for (int i = 0; i < length; ++i)
        if (std::isdigit(str[i]))      
            digit = true;
        
    return digit;
}

bool has_spec_ch(std::string str)
{
    int length = str.length();
    bool spec_ch {false};

    for (int i = 0; i < length; ++i)
        if (!std::isalnum(str[i]))      
            spec_ch = true;
        
    return spec_ch;
}

int main()
{
    std::string password {get_password()};
    int length = password.length();

    if (has_lower && has_upper && has_digit &&
        has_spec_ch && (length >= 8))
        std::cout << "Password is strong.\n";
    
    else
        std::cout << "Password is not strong.\n";

    return 0;
}