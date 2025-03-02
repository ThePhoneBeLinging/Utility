//
// Created by eal on 3/2/25.
//

#include "include/Utility/DebugController.h"

#include <iostream>

#include "include/Utility/ConfigController.h"
#include "include/Utility/Utility.h"

void DebugController::initDebug(const int limit)
{
    currentIndexInt_ = 0;
    debugLines_.resize(limit);
}

void DebugController::debugWrite(const std::string& debugText)
{
    std::lock_guard<std::mutex> lock(debugMutex_);
    debugLines_[currentIndexInt_] = debugText;
    currentIndexInt_++;
    currentIndexInt_ %= debugLimit_;
}

void DebugController::dumpDebug(const std::string* src)
{
    std::lock_guard<std::mutex> lock(debugMutex_);
    for (const auto& line : debugLines_)
    {
        if (src != nullptr)
        {
            Utility::appendToFile(*src,line);
            Utility::appendToFile(*src,"\n");
        }
        else
        {
            std::cout << line << std::endl;
        }
    }
}
