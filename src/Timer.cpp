//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#include "include/Utility/Timer.h"

#include <chrono>

Timer::Timer(int timeInMilli) : mTotalTime(timeInMilli)
{

}

int Timer::milliSecondsLeft()
{
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeElapsed = end - mStartTime;
    int elapsedTime = timeElapsed.count() * 1000;
    if (elapsedTime >= mTotalTime) return 0;
    return mTotalTime - elapsedTime;
}

void Timer::start()
{
    mStartTime = std::chrono::high_resolution_clock::now();
}

void Timer::reset()
{

}
