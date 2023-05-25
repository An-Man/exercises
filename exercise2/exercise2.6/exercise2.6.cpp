//exercise 2.6 Palkkatehtävä

#include <iostream>

int main()
{
    int paiva {0};

    for (int palkka{1}; palkka < 10'000'000;palkka *= 2)
        {
        ++paiva;
        std::cout << "päivä" << paiva << "palkka" << palkka << "euroa\n";
        }
        

    std::cout << paiva;

    return 0;
}
