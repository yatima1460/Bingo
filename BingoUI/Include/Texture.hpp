
#pragma once

#include <string>
#include <SDL.h>

class Texture
{

private:
#ifdef SDL_VERSION
    SDL_Texture *internal;
#endif

public:
    explicit Texture(const std::string &path);


#ifdef SDL_VERSION

    SDL_Texture *GetSDLTexture();

#endif

    ~Texture();


    SDL_Rect GetSDLRect();
};