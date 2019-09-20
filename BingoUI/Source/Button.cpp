#include "Button.hpp"

#include <utility>
#include <Graphics.hpp>


Button::Button(std::string text, Texture *normal, Texture *hovered) : text(std::move(text))
{
    this->active = normal;
    this->normal = normal;
    this->hover = hovered;
    this->location.y = 0;
    this->location.x = 0;
}

Texture *Button::GetTexture()
{
    return active;
}


void Button::Update()
{
    int x;
    int y;
    SDL_GetMouseState(&x, &y);

    SDL_Rect size = active->GetSDLRect();
    if (x > location.x && y > location.y && x < location.x + size.w && y < location.y + size.h)
    {
        active = hover;
    } else
    {
        active = normal;
    }
}

void Button::Draw()
{
    Graphics::DrawTexture(GetTexture(), &location);
    SDL_Point centered = location;
    SDL_Rect buttonTextureSize = GetTexture()->GetSDLRect();
    centered.x += buttonTextureSize.w / 2;
    centered.y += buttonTextureSize.h / 2;
    SDL_Rect textSize = Graphics::MeasureText(text);
    centered.x -= textSize.w / 2;
    centered.y -= textSize.h / 2;
    Graphics::DrawText(text, centered, {255, 255, 255});
}

void Button::SetPosition(SDL_Point loc)
{
    this->location = loc;
}
