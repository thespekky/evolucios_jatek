#include <iostream>
#include <string>
#include <algorithm>

#include "../rand/rand.h"
class Eloleny
{
    bool lepett;
    unsigned szint;
    unsigned x, y;
    unsigned ero;
    unsigned kezdeti_ero;

public:
    Eloleny(const unsigned &x, const unsigned &y) : lepett(false), szint(1), x(x), y(y), ero(Randomszam::getRandom(0, 100))
    {
        kezdeti_ero = ero;
    };
    Eloleny() : lepett(false), szint(1), x(0), y(0), ero(Randomszam::getRandom(0, 100))
    {
        kezdeti_ero = ero;
    };

    void change_hely(const int &x, const int &y)
    {
        this->x = x;
        this->y = y;
    }
    const unsigned &get_x() const
    {
        return x;
    }
    const unsigned &get_y() const
    {
        return y;
    }
    const unsigned &get_ero() const
    {
        return ero;
    }
    const unsigned &get_szint() const
    {
        return szint;
    }
    const bool &get_lepett() const
    {
        return lepett;
    }
    void set_lepett(const bool &b)
    {
        lepett = b;
    }
    void szintLepes()
    {
        if (ero > kezdeti_ero)
        {
            ero = kezdeti_ero;
            szint += 1;
        }
    }
    // harc
    Eloleny &operator>(Eloleny &eloleny)
    {
        if (this->szint > eloleny.get_szint())
        {
            ero += eloleny.get_ero();
            return *this;
        }
        else if (this->szint < eloleny.get_szint())
        {
            eloleny.ero += this->kezdeti_ero;
            return eloleny;
        }
        else
        {
            if (this->ero > eloleny.get_ero())
            {
                ero += eloleny.get_ero();
                return *this;
            }
            else
            {
                eloleny.ero += this->kezdeti_ero;
                return eloleny;
            }
        }
    }
};