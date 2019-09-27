#include <fstream>
#include <iostream>
#include <sstream>
#include <iostream>
#include "Settings.hpp"


std::map<std::string, std::string> Settings::config;

bool Settings::save()
{

    std::ofstream out("Settings.ini");
    out << toString();
    out.close();

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

bool Settings::ParseFile(const std::string& contents)
{
    const auto oldConfig = config;
    config.clear();

    std::string line;
    std::istringstream input(contents);
    while (std::getline(input, line))
    {

        const std::string delimiter = "=";
        const auto posEqual = line.find(delimiter);
        if (posEqual == std::string::npos)
        {
            config = oldConfig;
            return false;
        }
        std::string key = line.substr(0, posEqual);
        std::string value = line.substr(posEqual + delimiter.length());

        config[key] = value;
    }

    return true;

}

bool Settings::load()
{

    std::string settingsFile;
    std::ifstream file("Settings.ini");

    if (file)
    {


        std::stringstream buffer;
        buffer << file.rdbuf();

        file.close();

        return ParseFile(buffer.str());
    } else
    {
        std::cout << "ERROR: can't load settings file" << std::endl << std::endl;
        return false;
    }


}
