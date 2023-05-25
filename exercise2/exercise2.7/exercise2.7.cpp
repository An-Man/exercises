// Exercise 2.7 Fibonaccin luvut

#include <iostream>

void fibo(int n) //funktio tulostaa n määrän Fibonaccin lukuja alkaen 0:sta
{
    int F0 {0};
    int F1 {1};
    int nextF {};

    for (int count{1}; count <= n; ++count)
    {
        if ( count == 1 )
            {
                std::cout << F0 << ", ";
                continue;
            }
        if ( count == 2 )
            {
                std::cout << F1 << ", ";
                continue;
            }
        nextF = F0 + F1;
        F0 = F1;
        F1 = nextF;

        std::cout << nextF << ", ";
    }
}

int main ()
{
    std::cout << "Montako lukua tulostetaan?: ";
    int lkm {};
    std::cin >> lkm;
    
    fibo(lkm);
    std::cout << "\n";

    return 0;
}
