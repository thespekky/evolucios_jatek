#ifndef ran_H
#define ran_H
#include <cstdlib>
#include <ctime>
class Randomszam
{
public:
    static int getRandom(int min, int max);
    static void resetseed();
};
#endif