#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "sajathiba.cpp"
using namespace std;

int getRandom(int min, int max)
{
    std::srand(std::time(nullptr)); // idó állítás hogy a mindog más random értékek legyenek
    return min + (rand() % (max - min + 1));
};

int main(int argc, char const *argv[])
{
    int jatekosok_szama = 0;
    int palyameret = 0;
    double palyameret_hiba = false;
    double jatekosok_hiba = false;
    // pálya méret beolvasása és hiba kezelése
    while (!palyameret_hiba)
    {
        try
        {
            string valasz;
            cout << "Kerem hogy adja meg hogy mekkora(x*x) legyen a palya merete,( maximun 15)." << endl;
            cout << "Ha nem ad meg semmit akkor a palya merete 8 lesz" << endl;
            getline(cin, valasz);
            if (valasz == "")
            {
                palyameret = 8;
            }
            else
            {
                palyameret = stoi(valasz);
                if (palyameret > 15 || palyameret < 2)
                {
                    throw sajathiba("Helytelen adatot adott meg");
                }
            }
            palyameret_hiba = true;
        }
        catch (const sajathiba &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (invalid_argument &error)
        {
            std::cerr << "Konvertalasi hiba: " << error.what() << '\n';
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // jatekosok számának beolvasás a és hiba kezelése
    while (!jatekosok_hiba)
    {
        try
        {
            string valasz;
            cout << "Mennyi jatekost szertne (Ha nem ad meg semmi akkor veletlen darab lesz) :";
            getline(cin, valasz);
            if (valasz == "")
            {
                jatekosok_szama = getRandom(2, pow(palyameret, 2));
                cout << "Random jatekosok szama: " << jatekosok_szama << endl;
            }
            else
            {
                jatekosok_szama = stoi(valasz);
                if (jatekosok_szama > pow(palyameret, 2))
                {
                    throw sajathiba("Ennyi jatekost nem lehet generalni");
                }
            }
            jatekosok_hiba = true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const sajathiba &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
