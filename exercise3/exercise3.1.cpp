#include <iostream>

int main()
{
    int koko {};
    std::cout << "Montako lukua syötetään listaan? ";
    std::cin >> koko;

    int* dynamicArray {new int[koko]};

    for (int i = 0; i < koko; ++i)
    {
        dynamicArray[i] = i + 1;
        std::cout << "Luku " << i + 1 << ": ";
        std::cin >> dynamicArray[i];
    }

    std::cout << "Listan sisältö: ";
    for (int i = 0; i < koko; ++i)
    {
        std::cout << dynamicArray[i] << ", ";
    }
    std::cout << '\n';

    // summan laskeminen
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