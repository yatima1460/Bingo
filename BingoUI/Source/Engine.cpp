#include <Graphics.hpp>
#include <AssetsManager.hpp>
#include <BingoLevel.hpp>
#include <cassert>
#include <Settings.hpp>
#include <iostream>
#include <PrizeSystem.hpp>
#include "Engine.hpp"


Level* Engine::currentLevel;

bool Engine::quit;
SDL_Event Engine::e;


void Engine::Clean()
{
    AssetsManager::Clean();
    Graphics::Clean();
}

void Engine::Init()
{
    if (!Settings::load())
    {
        std::cout << "Can't load settings from .ini file" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!PrizeSystem::load())
    {
        std::cout << "Can't load prize settings from .ini file" << std::endl;
        exit(EXIT_FAILURE);
    }

    //The asset manager needs an OpenGL context to create the textures, so we initialize graphics first
    Graphics::Init();

    // Load all the files inside the input directory
    AssetsManager::Init(Settings::get<std::string>("assets_path"));

    SetLevel(new BingoLevel());
}


void Engine::SetLevel(Level* level)
{
    if (currentLevel != nullptr)
    {
        currentLevel->EndLevel();
        delete currentLevel;
    }
    currentLevel = level;
    level->BeginLevel();
}

void Engine::MainLoop()
{
    // Main loop
    while (!Engine::quit)
    {
        while (SDL_PollEvent(&Engine::e) != 0)
        {
            switch (Engine::e.type)
            {
                case SDL_QUIT:
                {
                    // Pressing the SDLWindow [X] closes
                    Engine::quit = true;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch (e.key.keysym.sym)
                    {
                        // ESC closes
                        case SDLK_ESCAPE:
                            Engine::quit = true;
                            break;

                        default:
                            break;

                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        currentLevel->Update();

        currentLevel->Draw();

        Graphics::SwapBuffers();
    }
}

Level& Engine::GetCurrentLevel()
{
    assert(currentLevel != nullptr);
    return *currentLevel;
}

void Engine::Quit()
{
    quit = true;
}
