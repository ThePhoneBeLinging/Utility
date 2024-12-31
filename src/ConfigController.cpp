//
// Created by eal on 12/31/24.
//

#include "include/Utility/ConfigController.h"

#include <nlohmann/json.hpp>

#include "Utility/Utility.h"

void ConfigController::loadConfig(std::string fileName)
{
    std::lock_guard lock(mutex_);
    std::string fileString = Utility::readFromFile(fileName);

    auto jsonObject = nlohmann::json::parse(fileString);

    for (const auto& item : jsonObject.items())
    {
        if (item.value().is_string())
        {
            configStringLookupTable_[item.key()] = item.value();
        }
        else if (item.value().is_number_integer())
        {
            configIntLookupTable_[item.key()] = item.value();
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

std::string ConfigController::getConfigString(const std::string& key)
{
    std::lock_guard lock(mutex_);
    if (not configIntLookupTable_.contains(key))
    {
        throw std::runtime_error("ConfigController::getConfigInt: Key " + key + " not found");
    }
    return configStringLookupTable_[key];
}
