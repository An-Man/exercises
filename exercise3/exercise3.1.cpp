#include <iostream>

// Funktio jolla tulostetaan listan arvot
void tulostaLista(int* arr, int size)
{
    std::cout << "Listan sisältö: ";

    for (int i{0}; i < size; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << '\n';
}

// summafunktio
int laskeSumma(int* arr, int size)
{
    int summa{};
    for (int i{0}; i < size; ++i)
        {
          summa += arr[i];  
        }

    return summa;
}

int main()
{
    int koko {}; // käyttäjän määrittelemä listan koko
    std::cout << "Montako lukua syötetään listaan? ";
    std::cin >> koko;

    // luodaan pointerin avulla dynaaminen array jonka koko otetaan muuttujasta 
    int* dynamicArray {new int[koko]};

    // syötetään luvut listaan loopin kautta
    for (int i = 0; i < koko; ++i)
    {
        dynamicArray[i] = i + 1;
        std::cout << "Luku " << i + 1 << ": ";
        std::cin >> dynamicArray[i];
    }

    // tulostetaan listan luvut syöttöjärjestyksessä
    tulostaLista(dynamicArray, koko);
    
    // lasketaan listan lukujen summa funktiolla
    int summa {laskeSumma(dynamicArray, koko)};
 
    // lasketaan keskiarvo summan ja koon avulla
    double keskiarvo {static_cast<double>(summa) / koko};

    std::cout << "Lukujen summa on: " << summa << '\n';
    std::cout << "Lukujen keskiarvo on: " << keskiarvo << '\n';

    // tuhotaan dynamicArray muistin vapauttamiseksi
    delete[] dynamicArray;

    return 0;
}

