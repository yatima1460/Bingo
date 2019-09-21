

#pragma once

#include <string>
#include "Texture.hpp"
#include "Widget.hpp"

class Button : public Widget
{
private:


    Texture *normal;
    Texture *hover;
    std::string text;
    Texture *active;
    bool hovered;

    SDL_Cursor* normalCursor;
    SDL_Cursor* hoverCursor;
    bool previousFrameHovered;
    bool leftPressedPrevious;

    void (* callback)() = nullptr;


public:

    Button(std::string text, Texture *normal, Texture *hovered);

    Texture* GetTexture();


    void Update();

    void SetSize(int width, int height);

    void SetCallback(void (* callback)());

    void Draw() override;


};

