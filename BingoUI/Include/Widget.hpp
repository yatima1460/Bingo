
#pragma once

class Widget
{

protected:
    SDL_Point location;

public:

    virtual void Update() = 0;
    virtual void Draw() = 0;

    void SetPosition(SDL_Point location);
};