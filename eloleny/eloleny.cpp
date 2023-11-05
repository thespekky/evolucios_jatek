#include <iostream>
#include <string>

#include "../rand/rand.h"
class Eloleny
{
    unsigned level;
    unsigned x, y;
    unsigned ero;

public:
    Eloleny(const unsigned &x, const unsigned &y) : level(1), x(x), y(y), ero(Randomszam::getRandom(0, 100)){};
    Eloleny() : level(1), x(0), y(0), ero(Randomszam::getRandom(0, 100)){};

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
    const unsigned &get_level() const
    {
        return level;
    }
    /* bool operator>(const Eloleny &eloleny)
     {
         return false;
     };*/
};