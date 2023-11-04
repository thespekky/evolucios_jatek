#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandom(int min, int max)
{
    std::srand(std::time(nullptr)); // idó állítás hogy a mindog más random értékek legyenek
    return min + (rand() % (max - min + 1));
};