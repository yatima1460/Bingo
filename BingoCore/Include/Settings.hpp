#pragma once

#include <string>
#include <map>
#include <sstream>

class Settings
{


    static std::map<std::string, std::string> config;


public:


    template<typename T>
    static void set(const std::string& key, T value)
    {
        if (key.empty())
            throw std::invalid_argument("key can't be empty");

        std::stringstream iss;
        iss << value;
        if (iss.str().empty())
            throw std::invalid_argument("value can't be empty");
        if (iss.fail())
            throw std::logic_error(value + " can't be converted to string");
        const auto s = iss.str();
        config[key] = s;
    }


/*

    template<typename T>
    T get(const std::string& key)
    {
        auto it = config.find(key);

        if(it != config.end())
        {
            return config[key];
        }
    }
*/


    template<typename T>
    [[nodiscard]] static T get(const std::string& key)
    {
        auto it = config.find(key);

        if (it == config.end())
            throw std::invalid_argument("Key '" + key + "' does not exist in settings");

        T t;
        std::stringstream iss(config[key]);
        iss >> t;

        if (iss.fail())
        {
            throw std::logic_error("Value of " + key + " can't be converted");
        }

        return t;


    }


    /*   void Settings::operator[](const std::string key,int value)
       {
           int number;
           std::istringstream iss (config[key]);
           iss >> number;
           if (iss.fail()) {
               throw std::logic_error("'"+config[key] + "' can't be converted to an integer");
           }
           return number;
       }

   */


/*    std::string operator[](const std::string& key)
    {
        auto it = config.find(key);

        if(it == config.end())
            throw std::invalid_argument("Key '"+key+"' does not exist in settings");


        return config[key];
    }*/




    [[nodiscard]] static bool save();

    static std::string toString();
};

