
#pragma once

#include "Texture.hpp"
#include <SDL_ttf.h>

class Graphics
{

private:

#ifdef SDL_VERSION
    static SDL_Renderer *renderer;
    static SDL_Window *window;
    static TTF_Font* smallFont;
    static TTF_Font *font;
    static TTF_Font* bigFont;
    static SDL_Surface *screenSurface;
#endif

public:
    static void Init();

    static void CreateWindow();


    static void DrawTexture(Texture *texture);

    static void DrawTexture(Texture *texture, SDL_Rect *dest);

    static void DrawTexture(Texture *texture, SDL_Point *dest);



    static void SwapBuffers();

    static SDL_Renderer* GetSDLRenderer();

    static SDL_Rect MeasureText(const std::string& stringstream);

    static void Clean();

    static TTF_Font* GetDefaultFont();

    static TTF_Font* GetBigFont();

    static TTF_Font* GetSmallFont();

    static void DrawText(std::string text, SDL_Point location, SDL_Color color);

    static void DrawText(std::string text, SDL_Point location, SDL_Color color, TTF_Font* font);

    static SDL_Rect MeasureText(const std::string& stringstream, TTF_Font* font);


};