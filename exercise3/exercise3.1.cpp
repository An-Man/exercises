// Exercise 3.1 Lista luvuista ja tilastotietoa
#include <algorithm>
#include <iostream>
#include <numeric>

// Funktio jolla tulostetaan listan arvot
void tulostaLista(int *arr, int size)
{
    std::cout << "Listan sisältö: ";

    for (int i{0}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// summafunktio
int laskeSumma(int *arr, int size)
{
    int summa = std::accumulate(arr, arr + size, 0);
    return summa;
}

// pienimmän luvun palauttava funktio
int minArvo(int *arr, int size)
{
    int *minElement = std::min_element(arr, arr + size);
    return *minElement;
}

// suurimman luvun palauttava funktio
int maxArvo(int *arr, int size)
{
    int *maxElement = std::max_element(arr, arr + size);
    return *maxElement;
}

// funktio joka palauttaa yleisimmän luvun, tai ensimmäisen, jos monta yhtä yleistä
// pitkällä listalla tämä ei ole kovin tehokas tapa
int yleisinArvo(int *arr, int size)
{
    int mostFrequentValue{arr[0]};
    int maxFrequency{1};

    for (int i{0}; i < size - 1; ++i) //ulompi loop käy läpi arrayn arvot
    {
        int currentFrequency = 1;

        for (int j = i + 1; j < size; ++j) //sisempi vertaa arvoa jokaiseen seuraavaan arvoon
        {
            if (arr[i] == arr[j])
            {
                ++currentFrequency; //jos arvo on sama, frekvenssi kasvaa yhdellä
            }
        }

        if (currentFrequency > maxFrequency)
        {
            maxFrequency = currentFrequency;
            mostFrequentValue = arr[i];
        }
    }

    return mostFrequentValue;
}

int main()
{
    int koko{};
    std::cout << "Montako lukua syötetään listaan? ";
    std::cin >> koko;

    // luodaan pointerin avulla dynaaminen array jonka koko otetaan muuttujasta
    int *dynamicArray{new int[koko]{}};

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
    int summa{laskeSumma(dynamicArray, koko)};

    // lasketaan keskiarvo summan ja koon avulla
    double keskiarvo{static_cast<double>(summa) / koko};

    std::cout << "Lukujen summa on: " << summa << '\n';
    std::cout << "Lukujen keskiarvo on: " << keskiarvo << '\n';
    std::cout << "Pienin luku on: " << minArvo(dynamicArray, koko) << '\n';
    std::cout << "Suurin luku on: " << maxArvo(dynamicArray, koko) << '\n';
    std::cout << "Pienimmän ja suurimman erotus on: " << 
        (maxArvo(dynamicArray, koko) - minArvo(dynamicArray, koko)) << '\n';

    // etsitään funktiolla yleisintä lukua
    int yleisin {yleisinArvo(dynamicArray, koko)};
    std::cout << "Yleisin luku (tai ensimmäinen, jos yhtä yleisiä): " << yleisin << '\n';

    // tuhotaan pointteri dynamicArray muistin vapauttamiseksi
    delete[] dynamicArray;

    return 0;
}
