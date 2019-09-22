
#pragma once

#include <map>
#include "Texture.hpp"

// TODO: default texture in case of error?

class AssetsManager
{


private:

    static std::map<std::string, void*> assets;


public:


    static void Init(const std::string& assetsDirectory);


    template<class T>
    inline static T* Get(const std::string& name)
    {
        return reinterpret_cast<T*>(AssetsManager::assets[name]);
    }


};