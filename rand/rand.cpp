#include <cstdlib>
#include <ctime>
#include "rand.h"
void Randomszam::resetseed()
{
    std::srand(std::time(nullptr)); // idő állítás hogy a mindig más random értéket adjon
}
int Randomszam::getRandom(int min, int max)
{

    return min + (rand() % (max - min + 1));
};