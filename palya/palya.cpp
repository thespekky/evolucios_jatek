#include <string>
#include <vector>

#include "../eloleny/eloleny.cpp"

using namespace std;
class Palya
{
    unsigned elolenyek_szama;
    unsigned korokszama;
    int meret;
    vector<vector<Eloleny *>> palya; // 2 dimenziós pálya aminek az elemei egy élőlény pointer
    vector<vector<Eloleny *>> palya_tmp;

public:
    Palya(const int &x) : korokszama(0), meret(x)
    {
        for (int i = 0; i < meret; i++)
        {
            palya_tmp.push_back(vector<Eloleny *>());
            palya.push_back(vector<Eloleny *>()); //
            for (int j = 0; j < meret; j++)
            {
                // a 2dim pálya feltöltése null elemmel
                palya[i].push_back(nullptr);
                palya_tmp[i].push_back(nullptr);
            }
        }
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
                    cout << palya[i][j]->get_szint() << " | ";
                }
            }
            cout << endl;
        }
    }
    void elolenyek_letrehozasa(const int &db)
    {
        elolenyek_szama = db;
        int x = -1;
        int y = 0;
        for (int i = 0; i < db; i++)
        {
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
        korokszama++;
        tmp_torles();
        leptetes();
        harc();
        if (korokszama % 10 == 0 && korokszama != 0)
        {
            szintlepes();
        }

        palya_rajzolas();
    }
    void szintlepes()
    {
        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {
                if (palya[i][j] != nullptr)
                {
                    palya[i][j]->szintLepes();
                }
            }
        }
    }
    void harc()
    {
        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {

                if (palya[i][j] == nullptr && palya_tmp[i][j] != nullptr)
                {
                    palya[i][j] = palya_tmp[i][j];
                }
                else if (palya[i][j] != nullptr && palya_tmp[i][j] != nullptr)
                {
                    // a pályában elmentem azt az elemet ami erősebb
                    // derefálást végzek ->*(palya_tmp[i][j])
                    palya[i][j] = &(palya[i][j]->operator>(*(palya_tmp[i][j])));
                    elolenyek_szama -= 1;
                }
                if (palya[i][j] != nullptr)
                {
                    palya[i][j]->set_lepett(false);
                }
            }
        }
    }
    void tmp_torles()
    {
        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {
                palya_tmp[i][j] = nullptr;
            }
        }
    }
    void leptetes()
    {
        Randomszam::resetseed();
        int r;
        unsigned count = 0;
        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {
                if (palya[i][j] != nullptr && count < elolenyek_szama)
                {
                    if (!palya[i][j]->get_lepett())
                    {
                        // 0 fel 1 le 2 jobra 3 balra
                        r = Randomszam::getRandom(0, 3);
                        count += 1;
                        palya[i][j]->set_lepett(true);
                        Eloleny *e = palya[i][j];
                        switch (r)
                        {
                        case 0:
                            if (i == 0)
                            {
                                e->change_hely(i + 1, j);
                                if (palya[i + 1][j] == nullptr)
                                {
                                    palya[i + 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i + 1][j] = e;
                                    palya[i][j] = nullptr;
                                }

                                break;
                            }
                            else
                            {
                                e->change_hely(i - 1, j);
                                if (palya[i - 1][j] == nullptr)
                                {
                                    palya[i - 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i - 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            break;
                        case 1:
                            if (i == meret - 1)
                            {
                                e->change_hely(i - 1, j);
                                if (palya[i - 1][j] == nullptr)
                                {
                                    palya[i - 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i - 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            else
                            {
                                e->change_hely(i + 1, j);
                                if (palya[i + 1][j] == nullptr)
                                {
                                    palya[i + 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i + 1][j] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            break;
                        case 2:
                            if (j == meret - 1)
                            {
                                e->change_hely(i, j - 1);
                                if (palya[i][j - 1] == nullptr)
                                {
                                    palya[i][j - 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i][j - 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            else
                            {
                                e->change_hely(i, j + 1);
                                if (palya[i][j + 1] == nullptr)
                                {
                                    palya[i][j + 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i][j + 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            break;
                        case 3:
                            if (j == 0)
                            {
                                e->change_hely(i, j + 1);
                                if (palya[i][j + 1] == nullptr)
                                {
                                    palya[i][j + 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i][j + 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            else
                            {
                                e->change_hely(i, j - 1);
                                if (palya[i][j - 1] == nullptr)
                                {
                                    palya[i][j - 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                else
                                {
                                    palya_tmp[i][j - 1] = e;
                                    palya[i][j] = nullptr;
                                }
                                break;
                            }
                            break;

                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
    void vegeredmeny()
    {
        int tuleltek = 0;
        int x, y;
        cout << "" << endl;
        cout << "Akik tuletek:" << endl;
        cout << "---------------------------" << endl;
        for (int i = 0; i < meret; i++)
        {
            for (int j = 0; j < meret; j++)
            {
                if (palya[i][j] != nullptr)
                {
                    tuleltek++;
                    x = i;
                    y = j;
                    cout << tuleltek << ". "
                         << "szintje: " << palya[i][j]->get_szint() << " ereje: "
                         << palya[i][j]->get_ero() << " helye: " << i << " , " << j << endl;
                }
            }
        }
        if (tuleltek == 1)
        {
            cout << "A nyertes eloleny:" << endl;
            cout << "---------------------------" << endl;
            cout << "szintje: " << palya[x][y]->get_szint() << " ereje: "
                 << palya[x][y]->get_ero() << " helye: " << x << " , " << y << endl;
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
                palya_tmp[i][j] = nullptr;
            }
        }
        // felszabadítja a pályát
        palya.clear();
        palya_tmp.clear();
    };
};