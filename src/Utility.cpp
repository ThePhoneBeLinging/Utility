//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#include "include/Utility/Utility.h"

#include <cstdlib>
#include <ctime>
#include <fstream>


bool Utility::mRandInitialised = false;
int Utility::getRandomInt(int min, int max)
{
    max++;
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

void Utility::writeToFile(const std::string& fileName, const std::string& msg)
{
    std::ofstream MyFile(fileName);
    MyFile << msg;
    MyFile.close();
}

std::string Utility::readFromFile(std::string fileName)
{
    // Create a text string, which is used to output the text file
    std::string myText;

    // Read from the text file
    std::ifstream MyReadFile(fileName);
    std::string returnString;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        returnString.append(myText);
    }
    MyReadFile.close();
    return returnString;
}
