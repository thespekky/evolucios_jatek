#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "hiba/sajathiba.cpp"
#include "palya/palya.cpp"
#include "rand/rand.h"
using namespace std;

// pálya 2d dinamikus tömb elemei egy hely osztály típú elemm ami tartalmaz egy listát a helyen lévő előlényekról

int main(int argc, char const *argv[])
{

    int eloleny_szama = 0;
    int palyameret = 0;
    double palyameret_hiba = false;
    double eloleny_hiba = false;
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
            std::cerr << "out of range: " << e.what() << '\n';
        }
    }

    // jatekosok számának beolvasása és hiba kezelése
    while (!eloleny_hiba)
    {
        try
        {
            string valasz;
            cout << "Mennyi eloleny szertne (Ha nem ad meg semmi akkor veletlen darab lesz) :";
            getline(cin, valasz);
            if (valasz == "")
            {
                eloleny_szama = Randomszam::getRandom(2, pow(palyameret, 2));
                cout << "Random jatekosok szama: " << eloleny_szama << endl;
            }
            else
            {
                eloleny_szama = stoi(valasz);
                if (eloleny_szama > pow(palyameret, 2))
                {
                    throw sajathiba("Ennyi eloleny nem lehet generalni");
                }
                if (eloleny_szama < 2)
                {
                    throw sajathiba("Keves eloleny legalabb 2 kell");
                }
            }
            eloleny_hiba = true;
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
    Palya palya(palyameret);
    palya.elolenyek_letrehozasa(eloleny_szama);
    palya.palya_rajzolas();
    string valasz;
    while (palya.get_korokszama() < 20)
    {
        try
        {
            cout << "\n"
                 << endl;
            cout << "Korok szama: " << palya.get_korokszama() << endl;
            cout << "\n"
                 << endl;
            cout << "Menu opciok:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1 - [Enter] Jatek folytatasa" << endl;
            cout << "2 - k Kilepes" << endl;
            getline(cin, valasz);
            if (valasz == "" || valasz == "1")
            {
                cout << "fight" << endl;
                palya.jatek();
            }
            else if (valasz == "2" || valasz == "k")
            {
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}