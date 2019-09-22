

#pragma once

#include <string>
#include "Texture.hpp"
#include "Widget.hpp"

class ButtonWidget : public Widget
{
private:


    Texture *normal;
    Texture *hover;
    std::string text;
    Texture *active;
    bool hovered;
    bool enabled = true;

    SDL_Cursor* normalCursor;
    SDL_Cursor* hoverCursor;
    SDL_Cursor* disabledCursor;
    bool previousFrameHovered;
    bool leftPressedPrevious;

    void (* callback)() = nullptr;


public:

    ButtonWidget(std::string text, Texture* normal, Texture* hovered);

    Texture* GetTexture();

    void SetEnabled(bool enabled);

    void Update() override;

    //void SetSize(int width, int height);

    void SetCallback(void (* callback)());

    void Draw() override;


};

