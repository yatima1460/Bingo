#include <Config.hpp.old>
#include <Engine.hpp>
#include "AssetsManager.hpp"
#include "Graphics.hpp"
#include "BingoLevel.hpp"


#undef main

int main(int argc, char* args[])
{
    Engine::Init();
    Engine::MainLoop();
    Engine::Clean();

    return EXIT_SUCCESS;
}