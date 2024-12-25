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

void Utility::appendToFile(const std::string& fileName, const std::string& msg)
{
    std::ofstream outfile;
    outfile.open(fileName, std::ios_base::app);
    outfile << msg;
}

std::string Utility::readFromFile(const std::string& fileName)
{
    std::string myText;
    std::ifstream file(fileName);
    std::string str;
    while (std::getline(file, str))
    {
        myText.append(str);
        myText.append("\n");
    }
    file.close();
    return myText;
}
