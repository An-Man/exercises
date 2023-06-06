#include <iostream>
#include <string>

// funktiolla kysytään käyttäjältä merkkijono
std::string getString()
{
    std::cout << "Enter a string of characters (no whitespace): ";
    std::string str {};
    std::cin >> str;
    
    return str;
}

// funktio palauttaa merkkijonon lopusta alkuun kääntäen
std::string reverseString(std::string string)
{
    std::string takapString {};
    for (int i = string.length() - 1; i >= 0; --i)
    {
        takapString += string[i];
    }

    return takapString;
}

int main()
{
    std::string str { getString() };

    std::cout << "Let's print it in reverse!\n";
    std::cout << reverseString(str) << '\n';

    return 0;
}