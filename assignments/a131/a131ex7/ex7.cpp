#include <iostream>

// tämä on kesken, koska en osannut tehdä toimivaa private muuttujaa :'D

struct Example
{
    int id {};

    int get_id()
    {
        return id;
    }

    void set_id(int new_id)
    {
        id = new_id;
    }
};

int main()
{
    Example esim {12};   // määritellään Example esim arvolla 12

    std::cout << esim.id << '\n'; // voi tulostaa suoraan koska structissa public

    esim.set_id(66); // muutetaan arvoksi 66

    std::cout << esim.get_id() << '\n'; //haetaan funktiolla (periaatteessa turha)

    return 0;
}