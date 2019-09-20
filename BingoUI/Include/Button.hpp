

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
    bool hovered;

    SDL_Cursor* normalCursor;
    SDL_Cursor* hoverCursor;
    bool previousFrameHovered;
    bool leftPressedPrevious;

    void (* callback)();


public:

    Button(std::string text, Texture *normal, Texture *hovered);

    Texture* GetTexture();

    void SetPosition(SDL_Point location);

    void Update();

    void SetSize(int width, int height);

    void SetCallback(void (* callback)());

    void Draw();


};

