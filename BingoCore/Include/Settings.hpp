#pragma once

#include <string>
#include <map>
#include <sstream>

class Settings
{

    /**
     * Map holding the settings, in a key=value format for the ini-like file
     */
    static std::map<std::string, std::string> config;


    /**
     * Parses the ini-like string
     * @param contents settings in ini-like format
     * @return true if parsed, false if error
     */
    static bool parseFile(std::string contents);


public:

    /**
     * Generates a string of the current settings
     * @return ini-like file representation
     */
    static std::string toString();

    template<typename T>
    static void set(const std::string& key, T value)
    {
        if (key.empty())
            throw std::invalid_argument("key can't be empty");

        std::stringstream iss;
        iss << value;
        if (iss.str().empty())
            throw std::invalid_argument("VALUE can't be empty");
        if (iss.fail())
            throw std::logic_error(value + " can't be converted to string");
        const auto s = iss.str();
        config[key] = s;
    }

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

    /**
     * Loads and validates settings from file
     * @return true if loaded, false if error
     */
    [[nodiscard]] static bool load();

    /**
     * Save settings to file
     * @return true if saved, false if error
     */
    [[nodiscard]] static bool save();


};

