//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer {
public:
    Timer(int timeInMilli);
    int milliSecondsLeft();
    void start();
    void reset();
private:
    int mTotalTime;
    std::chrono::time_point<std::chrono::steady_clock> mStartTime;
};



#endif //TIMER_H
