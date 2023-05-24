//Exercise 2.1: Fuel consumption cost

#include "constants.h"
#include <iostream>

int main()
{
    //kysy matkan pituus
    std::cout << "Anna ajettu matka (km): ";
    double matka {};
    std::cin >> matka;

    //kysy kulutus satasella
    std::cout << "Anna polttoaineen kulutus l/100 km: ";
    double kulutus {};
    std::cin >> kulutus;

    //kysy diesel vai bensa
    std::cout << "Diesel vai bensa [D/B]? ";
    char polttisTyyppi {};
    std::cin >> polttisTyyppi;
    
    //laske kustannus
    if (polttisTyyppi == 'D')
        std::cout << "Polttoainekustannus on " << ((matka * kulutus) / 100) 
        * constants::dieselEuroa << " euroa.\n";
    else
        std::cout << "Polttoainekustannus on " << ((matka * kulutus) / 100) 
        * constants::e95Euroa << " euroa.\n";

    return 0;
}