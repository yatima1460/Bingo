#include <Config.hpp>
#include "AssetsManager.hpp"
#include "Graphics.hpp"
#include "Bingo.hpp"


#undef main
int main(int argc, char* args[])
{
    //The asset manager needs an OpenGL context to create the textures, so we initialize graphics first
    Graphics::Init();

    // Load all the files inside the input directory
    AssetsManager::Init(ASSETS_PATH);

    Bingo();

    AssetsManager::Clean();
    Graphics::Clean();
    return EXIT_SUCCESS;
}