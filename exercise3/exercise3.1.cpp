#include <iostream>

// Funktio jolla tulostetaan listan arvot
void tulostaLista (int* arr, int size)
{
    std::cout << "Listan sisältö: ";

    for (int i{0}; i < size; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << '\n';
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

    tulostaLista(dynamicArray, koko);
    

    // tästä summafunktio
    int summa {};
    for (int i = 0; i < koko; ++i)
        {
          summa += dynamicArray[i];  
        }

    // keskiarvon laskeminen
    double keskiarvo {static_cast<double>(summa) / koko};

    // tulostetaan summa ja keskiarvo
    std::cout << "Lukujen summa on: " << summa << '\n';
    std::cout << "Lukujen keskiarvo on: " << keskiarvo << '\n';

    delete[] dynamicArray;

    return 0;
}

