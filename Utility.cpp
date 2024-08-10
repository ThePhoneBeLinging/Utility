//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#include "Utility.h"

#include <cstdlib>
#include <ctime>


bool Utility::mRandInitialised = false;
int Utility::getRandomFloat(int min, int max)
{
    if (!mRandInitialised)
    {
        srand(time(nullptr));
        mRandInitialised = true;
    }
    int returnValue = rand() % max;
    while (returnValue < min)
    {
        returnValue = rand() % max;
    }
    return returnValue;
}
