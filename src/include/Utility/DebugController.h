//
// Created by eal on 3/2/25.
//

#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H
#include <mutex>
#include <string>
#include <vector>


class DebugController
{
public:
    static void initDebug(int limit);
    static void debugWrite(const std::string& debugText);
    // Give src = nullptr for simply printing to console.
    static void dumpDebug(const std::string* src);
private:
    static inline int currentIndexInt_;
    static inline std::mutex debugMutex_;
    static inline std::vector<std::string> debugLines_;
    static inline int debugLimit_;
};



#endif //DEBUGCONTROLLER_H
