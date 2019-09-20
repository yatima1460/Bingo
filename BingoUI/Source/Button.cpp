#include "Button.hpp"

#include <utility>
#include <Graphics.hpp>


Button::Button(std::string text, Texture *normal, Texture *hovered) : text(std::move(text))
{
    active = normal;
    location.y = 0;
    location.x = 0;
}

Texture *Button::GetTexture()
{
    return active;
}


void Button::Update()
{

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
