//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#include "Utility/TimeUtil.h"

#include <chrono>

std::vector<std::string> TimeUtil::getStringsForTmrwAnd7DaysBack()
{
    std::vector<std::string> stringVector;

    // Add tmrw:
    stringVector.push_back(TimeUtil::timeToStringForLookup(TimeUtil::getTommorowTime()));
    auto now = std::chrono::system_clock::now();
    for (int i = 0; i < 7; i++)
    {
        stringVector.push_back(timeToStringForLookup(timeToTM(now)));
        now -= std::chrono::hours(24);
    }
    return stringVector;
}

std::string TimeUtil::getCurrentTimeAsDateString()
{
    auto now = getCurrentTime();
    std::string day = std::to_string(now.tm_mday);
    std::string month = std::to_string(now.tm_mon);
    std::string year = std::to_string(now.tm_year);

    return day + "." + month + "." + year;
}

tm TimeUtil::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    return timeToTM(now);
}

tm TimeUtil::getTommorowTime()
{
    auto now = std::chrono::system_clock::now();
    now += std::chrono::hours(24);
    return timeToTM(now);
}

std::string TimeUtil::timeToStringForAPI(const tm& time)
{
    std::string timeString = std::to_string(time.tm_year) + "-" + std::to_string(time.tm_mon) + "-" + std::to_string(time.tm_mday);
    return timeString;
}

std::string TimeUtil::timeToStringForLookup(const tm& time)
{
    std::string timeString = std::to_string(time.tm_mday) + "." + std::to_string(time.tm_mon) + "." + std::to_string(time.tm_year);
    return timeString;
}

tm TimeUtil::timeToTM(const std::chrono::time_point<std::chrono::system_clock> time)
{
    time_t tt = std::chrono::system_clock::to_time_t(time);
    auto localTM =  *localtime(&tt);
    localTM.tm_year += 1900;
    localTM.tm_mon++;
    return localTM;
}
