//
// Created by eal on 12/31/24.
//

#ifndef CONFIGCONTROLLER_H
#define CONFIGCONTROLLER_H
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>


class ConfigController
{
public:
    static void loadConfig(const std::string& fileName);
    static std::string getConfigString(const std::string& key);
    static int getConfigInt(const std::string& key);
    static bool getConfigBool(const std::string& key);
    static std::vector<std::pair<std::string, std::string>> getConfigList();
    static void TESTsetConfigInt(const std::string& key, int value);
    static void TESTsetConfigString(const std::string& key, const std::string& value);
private:
    static inline std::unordered_map<std::string,std::string> configStringLookupTable_;
    static inline std::unordered_map<std::string,int> configIntLookupTable_;
    static inline std::unordered_map<std::string,bool> configBoolLookupTable_;
    static inline std::mutex mutex_;
};



#endif //CONFIGCONTROLLER_H
