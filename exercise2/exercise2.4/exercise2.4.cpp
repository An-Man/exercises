#include <iostream>

double BMI (double pituus, double paino) //funktio joka palauttaa painoindeksin liukulukuna
{
    return (paino / (pituus * pituus));
}

int main()
{
    //kysytään pituus ja paino käyttäjältä
    std::cout << "Anna pituutesi metreinä, (esim. 1.70): ";
    double pituus {};
    std::cin >> pituus;

    std::cout << "Anna painosi (kg): ";
    double paino {};
    std::cin >> paino;
    
    double painoindeksi {BMI(pituus, paino)}; //luodaan painoindeksille muuttuja, alustetaan funktiolla, argumentit pituus ja paino

    if (painoindeksi < 18.5)
        std::cout << "Painoindeksisi " << painoindeksi << " on ""alipainoinen"".\n";
    else if (painoindeksi > 30.0)
        std::cout << "Painoindeksisi " << painoindeksi << " on ""merkittävästi ylipainoinen"".\n";
    else if (18.5 < painoindeksi && painoindeksi < 24.9)
        std::cout << "Painoindeksisi " << painoindeksi << " on ""normaali"".\n";
    else
        std::cout << "Painoindeksisi " << painoindeksi << " on ""lievästi ylipainoinen"".\n";
}