#include <Graphics.hpp>
#include <cassert>
#include <utility>
#include "LabelWidget.hpp"


LabelWidget::LabelWidget(std::string t)
{
    this->text = std::move(t);
}

void LabelWidget::Draw()
{


    SDL_Surface* fontSurface = TTF_RenderText_Blended(Graphics::GetDefaultFont(), text.c_str(), color);

    // is null if string has length zero
    if (fontSurface)
    {
        SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(Graphics::GetSDLRenderer(), fontSurface);
        assert(fontTexture != nullptr);

        SDL_Rect Message_rect; //create a rect
        Message_rect.x = location.x;  //controls the rect's x coordinate
        Message_rect.y = location.y; // controls the rect's y coordinte
        Message_rect.w = fontSurface->w; // controls the width of the rect
        Message_rect.h = fontSurface->h; // controls the height of the rect

        SDL_FreeSurface(fontSurface);
        fontSurface = nullptr;

        assert(Graphics::GetSDLRenderer() != nullptr);
        SDL_RenderCopy(Graphics::GetSDLRenderer(), fontTexture, nullptr, &Message_rect);
        SDL_DestroyTexture(fontTexture);
        fontTexture = nullptr;

    }
}

void LabelWidget::SetText(std::string basicString)
{
    this->text = std::move(basicString);
}
