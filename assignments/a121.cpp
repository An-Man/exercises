#include <iostream>
#include <string>

// funktiolla kysytään käyttäjältä merkkijono
std::string getString()
{
    std::cout << "Enter a string of characters: ";
    std::string str {};
    std::cin >> str;
    return str;
}

// funktio tulostaa merkkijonon lopusta alkuun
void reverseString(std::string string)
{
    std::cout << "Let's print it in reverse!\n";
    int i {};
    for (i = string.length() - 1; i >= 0; i--)
    {
        std::cout << string[i];
    }

    std::cout << '\n';

}

int main()
{
    
    std::string str { getString() };

    reverseString(str);

    return 0;
}