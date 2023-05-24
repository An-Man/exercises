#include <iostream>
// Exercise 2.5 Henkilötunnus

int kysyHetu() //funktio kysyy numeroa ja palauttaa sen
{
    std::cout << "Anna suomalainen henkilötunnus (vain numeroita): ";
    int hetu {};
    std::cin >> hetu;

    return hetu;
}

int main()
{
    //alustetaan long int muuttuja funktion kysyhetu palauttamalla arvolla
    long letu{kysyHetu()}; 

    if (letu % 2 == 0) //jos muuttujan letu arvo on parillinen, kyseessä nainen, muuten mies
        std::cout << "Antamasi hetu implikoi naista.\n";
    else
        std::cout << "Antamasi hetu implikoi miestä.\n";

    return 0;
}
