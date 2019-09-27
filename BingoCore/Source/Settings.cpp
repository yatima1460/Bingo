#include "Settings.hpp"


std::map<std::string, std::string> Settings::config;

bool Settings::save()
{
    // TODO save .ini file
    return true;
}

std::string Settings::toString()
{
    std::stringstream ss;

    for (const auto& p: config)
    {
        ss << p.first << "=" << p.second << std::endl;
    }

    return ss.str();
}
