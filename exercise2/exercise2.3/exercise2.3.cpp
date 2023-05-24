// Exercise 2.3 Kuntosalijäsenyyslaskuri

#include <iostream> 

int main()
{
    std::cout << "Anna vuosijäsenyyden hinta: "; //kysytään vuosikortin hinta
    int vuosiEuroa { };
    std::cin >> vuosiEuroa;

    std::cout << "Anna kertamaksun hinta: "; //kysytään kertamaksun hinta
    int kertaEuroa { };
    std::cin >> kertaEuroa;

    std::cout << "Montako kertaa käyt vuodessa: "; //kysytään käyntikertojen määrä vuodessa
    int lkmKaynti { };
    std::cin >> lkmKaynti;

    if (vuosiEuroa < (kertaEuroa * lkmKaynti)) //verrataan kumpi vaihtoehto on halvempi
        {
            std::cout << "Vuosijäsenyys, " << vuosiEuroa << " euroa, tulee halvemmaksi.\n";
        }    
    else if (vuosiEuroa == (kertaEuroa * lkmKaynti))
        {
            std::cout << "Kertamaksut ja vuosijäsenyys ovat saman hintaiset.\n";
        }
    else
        {
            std::cout << "Kertamaksu " << kertaEuroa << " euroa " << lkmKaynti <<
            " käyntikerralla on halvempi kuin vuosijäsenyys.\n";
        }


    return 0;
}