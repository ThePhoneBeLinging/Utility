//
// Created by eal on 12/31/24.
//

#include "include/Utility/ConfigController.h"

#include <iostream>
#include <nlohmann/json.hpp>

#include "Utility/Utility.h"

void ConfigController::loadConfig(const std::string& fileName)
{
    std::lock_guard lock(mutex_);
    std::string fileString = Utility::readFromFile(fileName);

    auto jsonObject = nlohmann::json::parse(fileString);

    for (const auto& item : jsonObject.items())
    {
        if (item.value().is_string())
        {
            std::cout << "HELO" << std::endl;
            std::cout << item.key() << std::endl;
            configStringLookupTable_[item.key()] = item.value();
        }
        else if (item.value().is_number_integer())
        {
            configIntLookupTable_[item.key()] = item.value();
        }
        else if (item.value().is_boolean())
        {
            configBoolLookupTable_[item.key()] = item.value();
        }
    }
}

int ConfigController::getConfigInt(const std::string& key)
{
    std::lock_guard lock(mutex_);
    if (not configIntLookupTable_.contains(key))
    {
        throw std::runtime_error("ConfigController::getConfigInt: Key " + key + " not found");
    }
    return configIntLookupTable_[key];
}

bool ConfigController::getConfigBool(const std::string& key)
{
    std::lock_guard lock(mutex_);
    if (not configBoolLookupTable_.contains(key))
    {
        throw std::runtime_error("ConfigController::getConfigBool: Key " + key + " not found");
    }
    return configBoolLookupTable_[key];
}

std::string ConfigController::getConfigString(const std::string& key)
{
    std::lock_guard lock(mutex_);
    if (not configIntLookupTable_.contains(key))
    {
        throw std::runtime_error("ConfigController::getConfigString: Key " + key + " not found");
    }
    return configStringLookupTable_[key];
}

std::vector<std::pair<std::string, std::string>> ConfigController::getConfigList()
{
    std::lock_guard lock(mutex_);
    std::vector<std::pair<std::string, std::string>> configList;
    for (const auto& item : configIntLookupTable_)
    {
        auto pair = std::make_pair(item.first, std::to_string(item.second));
        configList.push_back(pair);
    }
    for (const auto& item : configStringLookupTable_)
    {
        auto pair = std::make_pair(item.first, item.second);
        configList.push_back(pair);
    }
    return configList;
}

void ConfigController::TESTsetConfigInt(const std::string& key, int value)
{
    std::lock_guard lock(mutex_);
    configIntLookupTable_[key] = value;
}

void ConfigController::TESTsetConfigString(const std::string& key, const std::string& value)
{
    std::lock_guard lock(mutex_);
    configStringLookupTable_[key] = value;
}
