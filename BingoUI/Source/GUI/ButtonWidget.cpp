#include "GUI/ButtonWidget.hpp"

#include <utility>
#include <Graphics.hpp>


ButtonWidget::ButtonWidget(std::string text, Texture* normal, Texture* hovered)
{
    this->active = normal;
    this->normal = normal;
    this->hover = hovered;
    this->location.y = 0;
    this->location.x = 0;
    this->text = std::move(text);

    hoverCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    normalCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    disabledCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_NO);
}

Texture* ButtonWidget::GetTexture()
{
    if (enabled)
        return active;
    else
        return hover;
}


void ButtonWidget::Update()
{


    int x;
    int y;
    int bitmask = SDL_GetMouseState(&x, &y);

    bool leftPressed = bitmask == 1;


    SDL_Rect size = active->GetSDLRect();

    hovered = x > location.x && y > location.y && x < location.x + size.w && y < location.y + size.h;

    if (hovered)
    {
        if (enabled)
        {
            SDL_SetCursor(hoverCursor);


            if (leftPressed && !leftPressedPrevious)
            {
                Pressed();
            }
        } else
        {
            SDL_SetCursor(disabledCursor);

        }


        active = hover;


    }

    if (previousFrameHovered && !hovered)
    {
        active = normal;
        SDL_SetCursor(normalCursor);
    }

    leftPressedPrevious = leftPressed;
    previousFrameHovered = hovered;
}

void ButtonWidget::Draw()
{
    Graphics::DrawTexture(*GetTexture(), location);
    SDL_Point centered = location;
    SDL_Rect buttonTextureSize = GetTexture()->GetSDLRect();
    centered.x += buttonTextureSize.w / 2;
    centered.y += buttonTextureSize.h / 2;
    SDL_Rect textSize = Graphics::MeasureText(text);
    centered.x -= textSize.w / 2;
    centered.y -= textSize.h / 2;


    Graphics::DrawText(text, centered, {255, 255, 255, 255});
}


void ButtonWidget::SetEnabled(bool enabled)
{
    this->enabled = enabled;
}
