

#pragma once

#include <string>
#include "Texture.hpp"
#include "Widget.hpp"

class ButtonWidget : public Widget
{
private:


    Texture* normal;
    Texture* hover;
    std::string text;
    Texture* active;
    bool hovered = false;
    bool enabled = true;

    SDL_Cursor* normalCursor = nullptr;
    SDL_Cursor* hoverCursor = nullptr;
    SDL_Cursor* disabledCursor = nullptr;
    bool previousFrameHovered = false;
    bool leftPressedPrevious = false;

    //void (* callback)() = nullptr;
protected:
    virtual void Pressed() = 0;

public:

    ButtonWidget(std::string text, Texture* normal, Texture* hovered);

    Texture* GetTexture();

    void SetEnabled(bool enabled);

    void Update() override;



    //void SetSize(int width, int height);



    void Draw() override;


};

