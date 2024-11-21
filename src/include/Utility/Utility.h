//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#ifndef UTILITY_H
#define UTILITY_H
#include <string>


class Utility {
public:
    static int getRandomInt(int min, int max);
    static void writeToFile(const std::string& fileName, const std::string& msg);
    static std::string readFromFile(std::string fileName);
private:
    static bool mRandInitialised;
};



#endif //UTILITY_H
