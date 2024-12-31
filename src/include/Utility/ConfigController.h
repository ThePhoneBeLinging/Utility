//
// Created by eal on 12/31/24.
//

#ifndef CONFIGCONTROLLER_H
#define CONFIGCONTROLLER_H
#include <mutex>
#include <string>
#include <unordered_map>


class ConfigController
{
public:
    static void loadConfig(std::string fileName);
    static std::string getConfigString(const std::string& key);
    static int getConfigInt(const std::string& key);
private:
    static inline std::unordered_map<std::string,std::string> configStringLookupTable_;
    static inline std::unordered_map<std::string,int> configIntLookupTable_;
    static inline std::mutex mutex_;
};



#endif //CONFIGCONTROLLER_H
