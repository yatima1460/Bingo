
#pragma once

#include <SDL.h>

class Widget
{

protected:
    SDL_Point location = {0, 0};

public:

    virtual void Update() = 0;

    virtual void Draw() = 0;

    void SetPosition(SDL_Point location);
};