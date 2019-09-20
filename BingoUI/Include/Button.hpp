

#pragma once

#include <string>
#include "Texture.hpp"

class Button
{
private:

    SDL_Point location;
    Texture *normal;
    Texture *hover;
    std::string text;
    Texture *active;


public:

    Button(std::string text, Texture *normal, Texture *hovered);

    Texture *GetTexture();

    void SetPosition(SDL_Point location);

    void Update();

    void Draw();
};

