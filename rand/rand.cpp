#include <cstdlib>
#include <ctime>
#include "rand.h"
void Randomszam::resetseed()
{
    std::srand(std::time(nullptr)); // idó állítás hogy a mindog más random értékek legyenek
}
int Randomszam::getRandom(int min, int max)
{
    // std::srand(std::time(nullptr)); // idó állítás hogy a mindog más random értékek legyenek
    return min + (rand() % (max - min + 1));
};