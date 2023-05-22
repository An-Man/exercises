// Exercise 2.2: polttoainekustannus lisättynä sähköautovaihtoehdolla

#include "constants.h"
#include <iostream>

//funktio joka kysyy ja palauttaa ajettavan matkan
    double kysyMatka()
    {
        std::cout << "Anna ajettu matka (km): ";
        double matka {};
        std::cin >> matka;

        return matka;
    }

 //kysy kulutus satasella
    double kysyKulutus()
    {
        std::cout << "Anna polttoaineen kulutus l/100 km: ";
        double kulutus {};
        std::cin >> kulutus;

        return kulutus;
    }

int main()
{
    //kysy moottorin tyyppi
    std::cout << "Diesel, bensa vai sähkö [D/B/S]? ";
    char polttisTyyppi {};
    std::cin >> polttisTyyppi;

    //alustetaan muuttujat matkalle ja kulutukselle
    

    // ilmoitetusta moottorin tyypistä riippuen kysytään joko matka ja kulutus tai pelkästään matka,
    // jos kyse sähköautosta
    switch (polttisTyyppi)
    {
        double matka;       //nämä voisi alustaa casen sisällä blokissa, tässä sallittu vain declaration
        double kulutus;

        case 'D':
            matka = kysyMatka();        //muuttujan arvon sijoitus on ok casen sisällä
            kulutus = kysyKulutus();
            std::cout << "Polttoainekustannus on " << ((matka * kulutus) / 100) *
                constants::dieselEuroa << " euroa.\n";
            break;
        
        case 'B':
            matka = kysyMatka();
            kulutus = kysyKulutus();
            std::cout << "Polttoainekustannus on " << ((matka * kulutus) / 100) *
                constants::e95Euroa << " euroa.\n";
            break;
 
        case 'S':
            matka = kysyMatka();
            std::cout << "Käyttövoimakustannus keskiarvokulutuksella ja -hinnalla on "
                << ((matka * constants::sahkonKulutus) / 100) *
                (constants::sahkonHinta / 100) << " euroa.\n";
            break;
    }
    
    return 0;
}