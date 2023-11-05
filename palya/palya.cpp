#include <string>
#include <vector>

#include "../eloleny/eloleny.cpp"

using namespace std;
class Palya
{
    unsigned korokszama;
    int meret;
    vector<vector<Eloleny *>> palya; // 2 dimenziós pálya aminek az elemei egy élőlény pointer

public:
    Palya(const int &x) : korokszama(0), meret(x)
    {
        for (int i = 0; i < meret; i++)
        {
            palya.push_back(vector<Eloleny *>()); //
            for (int j = 0; j < meret; j++)
            {
                // a 2dim pálya feltöltése null elemmel
                palya[i].push_back(nullptr);
            }
        }
        // palya[5][5] = new Eloleny(0, 1);
    };
    void palya_rajzolas()
    {
        cout << "     ";
        for (int i = 0; i < meret; i++)
        {
            if (i < 10)
            {
                cout << i << "   ";
            }
            else
            {
                cout << i << "  ";
            }
        }
        cout << endl;
        // cout << "0   1   2   3   4   5   6   7   8   9   10  11  12  13  14" << endl;
        for (int i = 0; i < meret; i++)
        {
            if (i < 10)
            {
                cout << " " << i << " | ";
            }
            else
            {
                cout << i << " | ";
            }
            for (int j = 0; j < meret; j++)
            {
                if (palya[i][j] == nullptr)
                {
                    cout << 0 << " | ";
                }
                else
                {
                    cout << palya[i][j]->get_level() << " | ";
                }
            }
            cout << endl;
        }
    }
    /*
                1   2   3   4   5   6   7   8   9   10  11  12  13  14
            1 | 1 | 0 | 2 | 0 | 1 | 0 | 2 | 0 | 1 | 0 | 2 | 0 | 1 | 0 | 2
            2 | 1 | 0 | 2 | 0 | 1 | 0 | 2 | 0 | 1 | 0 | 2 | 0 | 1 | 0 | 2 | 0 |
            3 | 1 |   | 2 |   |
            4
            5
            6
            7
            8
            9
            10
            11
            12
            13
            14
            15
    */
    void elolenyek_letrehozasa(const int &db)
    {
        int x = -1;
        int y = 0;
        // bool bol;
        for (int i = 0; i < db; i++)
        {

            /*do
            {
                x = Randomszam::getRandom(0, meret);
                y = Randomszam::getRandom(0, meret);
                cout << "x: " << x << " y: " << y << endl;
                bol = palya[x][y] != nullptr;
                cout << bol << endl;
            } while (palya[x][y] != nullptr);*/
            // Randomszam::resetseed();
            x += 1;
            if (x >= meret)
            {
                y += 1;
                x = 0;
            }
            palya[x][y] = new Eloleny(x, y);
        }
    }
    const unsigned &get_korokszama() const
    {
        return korokszama;
    }
    void jatek()
    {
        leptetes();
        korokszama++;
        palya_rajzolas();
    }
    void leptetes()
    {
        int r;
        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {
                if (palya[i][j] != nullptr)
                {
                    // 0 fel 1 le 2 jobra 3 balra
                    r = Randomszam::getRandom(0, 3);
                    cout << r << endl;
                    switch (r)
                    {
                    case 0:
                        if (i == 0)
                        {
                            /*Eloleny *e = palya[i][j];
                            e->change_hely(i + 1, j);
                            palya[i + 1][j] = e;
                            palya[i][j] == nullptr;*/
                            palya[i + 1][j] = palya[i][j];
                        }
                        else
                        {
                            /*Eloleny *e = palya[i][j];
                            e->change_hely(i - 1, j);
                            palya[i - 1][j] = e;
                            palya[i][j] == nullptr;*/
                            palya[i - 1][j] = palya[i][j];
                        }
                        break;
                    case 1:
                        if (i == meret - 1)
                        {
                            /*Eloleny *e = palya[i][j];
                            e->change_hely(i + 1, j);
                            palya[i + 1][j] = e;
                            palya[i][j] == nullptr;*/
                            palya[i + 1][j] = palya[i][j];
                        }
                        else
                        {
                            /*Eloleny *e = palya[i][j];
                             e->change_hely(i - 1, j);
                             palya[i - 1][j] = e;
                             palya[i][j] == nullptr;*/
                            palya[i - 1][j] = palya[i][j];
                        }
                        break;
                    case 2:
                        if (j == meret - 1)
                        {
                            /*Eloleny *e = palya[i][j];
                            e->change_hely(i, j - 1);
                            palya[i][j - 1] = e;
                            palya[i][j] == nullptr;*/
                            palya[i][j - 1] = palya[i][j];
                        }
                        else
                        {
                            /*Eloleny *e = palya[i][j];
                            e->change_hely(i, j + 1);
                            palya[i][j + 1] = e;
                            palya[i][j] == nullptr;*/
                            palya[i][j + 1] = palya[i][j];
                        }
                        break;
                    case 3:
                        if (j == 0)
                        {
                            /* Eloleny *e = palya[i][j];
                             e->change_hely(i, j - 1);
                             palya[i][j - 1] = e;
                             palya[i][j] == nullptr;*/
                            palya[i][j - 1] = palya[i][j];
                        }
                        else
                        {
                            /*Eloleny *e = palya[i][j];
                            e->change_hely(i, j + 1);
                            palya[i][j + 1] = e;
                            palya[i][j] == nullptr;*/
                            palya[i][j + 1] = palya[i][j];
                        }
                        break;

                    default:
                        break;
                    }
                    // palya[i][j]->change_hely(i, j);
                }
            }
        }
    }
    ~Palya()
    {

        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {
                // a vectorban lefoglalt helyeket törli
                palya[i][j] = nullptr;
            }
        }
        // felszabadítja a pályát
        palya.clear();
    };
};