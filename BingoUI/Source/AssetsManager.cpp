#include "AssetsManager.hpp"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <dirent.h>
#include <cassert>

namespace fs = std::filesystem;


std::map<std::string, void*> AssetsManager::assets;


std::string pathAppend(const std::string& p1, const std::string& p2)
{

    char sep = '/';
    std::string tmp = p1;

#ifdef _WIN32
    sep = '\\';
#endif

    if (p1[p1.length()] != sep)
    { // Need to add a
        tmp += sep;                // path separator
        return (tmp + p2);
    } else
        return (p1 + p2);
}

bool hasEnding(std::string const& fullString, std::string const& ending)
{
    if (fullString.length() >= ending.length())
    {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else
    {
        return false;
    }
}

void AssetsManager::Init(const std::string& assetsDirectory)
{
    DIR* dirp = opendir(assetsDirectory.c_str());
    struct dirent* dp;

    while ((dp = readdir(dirp)) != nullptr)
    {

        auto name = dp->d_name;

        std::string nameStr(name);

        if (hasEnding(nameStr, "bmp"))
        {

            auto t = new Texture(pathAppend(assetsDirectory, nameStr));
            assert(t != nullptr);

            size_t lastindex = nameStr.find_last_of('.');
            std::string rawname = nameStr.substr(0, lastindex);

            assets[rawname] = t;

        } else if (hasEnding(nameStr, "wav"))
        {
            // TODO
        }

    }

}
