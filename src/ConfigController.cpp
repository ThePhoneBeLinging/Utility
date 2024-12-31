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
        configLookupTable_[item.key()] = item.value();
    }
}

std::string ConfigController::getConfig(const std::string& key)
{
    std::lock_guard lock(mutex_);
    if (not configLookupTable_.contains(key))
    {
        throw std::invalid_argument("Key not found");
    }
    return configLookupTable_[key];
}
