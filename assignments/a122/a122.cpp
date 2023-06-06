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

// function returns true if password is strong - string given as reference
bool is_strong_password(const std::string& password)
{
    //criteria for strong password
    const int min_length {8};
    const int min_uppercase {1};
    const int min_lowercase {1};
    const int min_digits {1};
    const int min_special_chars {1};

    //discard short password
    if (password.length() < min_length)
    {
        return false;
    }

    bool has_uppercase {false};
    bool has_lowercase {false};
    bool has_digit {false};
    bool has_special_char {false};

    //check inside string range with cctype functions
    for (char c : password)
    {
        if (std::isupper(c)) {
            has_uppercase = true;
        } else if (std::islower(c)) {
            has_lowercase = true;
        } else if (std::isdigit(c)) {
            has_digit = true;
        } else if (!std::isalnum(c)) {
            has_special_char = true;
        }
    }

    return (has_uppercase && has_lowercase && has_digit && has_special_char);
}

int main()
{
    std::string password {get_password()};

    if (is_strong_password(password)) {
        std::cout << "Password is strong.\n";
    } else {
        std::cout << "Password is not strong.\n";
    }

    return 0;
}