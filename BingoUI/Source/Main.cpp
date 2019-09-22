

#include <AssetsManager.hpp>
#include <Graphics.hpp>
#include "BingoUI.hpp"


#undef main

int main(int argc, char* args[])
{
    //The asset manager needs an OpenGL context to create the textures, so we initialize graphics first
    Graphics::Init();

    AssetsManager::Init("Assets");

    BingoUI();
    return EXIT_SUCCESS;
}