


#include <Texture.hpp>
#include <string>
#include <SDL_surface.h>
#include <cassert>
#include <Graphics.hpp>


Texture::Texture(const std::string& path)
{
    //Load splash image
    assert(!path.empty());
    SDL_Surface* background_surface = SDL_LoadBMP(path.c_str());
    assert(background_surface != nullptr);

    internal = SDL_CreateTextureFromSurface(Graphics::GetSDLRenderer(), background_surface);
    assert(internal != nullptr);

    assert(background_surface != nullptr);
    SDL_FreeSurface(background_surface);
}


SDL_Texture* Texture::GetSDLTexture()
{
    return internal;
}

SDL_Rect Texture::GetSDLRect()
{
    SDL_Rect size = {0, 0, 0, 0};
    assert(internal != nullptr);
    SDL_QueryTexture(internal, nullptr, nullptr, &size.w, &size.h);
    return size;
}

Texture::~Texture()
{
    assert(internal != nullptr);
    SDL_DestroyTexture(internal);
}

