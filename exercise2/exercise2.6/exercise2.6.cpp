//exercise 2.6 Palkkatehtävä

#include <iostream>

//funktio kertoo päivän, palkan ja palkkojen summan kun palkka tuplaantuu joka päivä
//luuppi pyörii niin kauan kuin palkkojen summa on alle tavoitteen
void palkkalaskuri(int tavoite)
{
    int palkkasumma {};
    for (int palkka{1}, paiva{1}; palkkasumma < tavoite; palkka *= 2, ++paiva)
        {
            palkkasumma += palkka;
            std::cout << "päivä: " << paiva << " palkka: " << palkka << 
                " palkkasumma: " << palkkasumma << " euroa\n";
        } 
}

int main()
{
    palkkalaskuri(10'000'000);

    return 0;
}
