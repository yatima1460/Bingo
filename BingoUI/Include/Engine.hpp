#pragma once

#include <SDL.h>
#include "Level.hpp"

class Engine
{

    static Level* currentLevel;
    static bool quit;
    static SDL_Event e;

public:

    [[nodiscard]] static Level& GetCurrentLevel();

    static void Init();

    static void MainLoop();

    static void Clean();

    static void Quit();

    static void SetLevel(Level* level);
};