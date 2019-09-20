


#include <Texture.hpp>
#include <string>
#include <SDL_surface.h>
#include <cassert>
#include <Graphics.hpp>


Texture::Texture(const std::string &path)
{
    //Load splash image
    SDL_Surface *background_surface = SDL_LoadBMP(path.c_str());
    assert(background_surface != nullptr);

    internal = SDL_CreateTextureFromSurface(Graphics::GetSDLRenderer(), background_surface);
    assert(internal != nullptr);


    SDL_FreeSurface(background_surface);


}


SDL_Texture *Texture::GetSDLTexture()
{
    return internal;
}

