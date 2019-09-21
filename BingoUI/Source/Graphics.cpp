
#include <SDL.h>
#include <SDL_ttf.h>
#include <cassert>
#include "Graphics.hpp"

SDL_Window *Graphics::window;
TTF_Font *Graphics::font;
SDL_Renderer *Graphics::renderer;
SDL_Surface *Graphics::screenSurface;

void Graphics::Init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(
            "Bingo",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            -1, -1,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Init();
    font = TTF_OpenFont("Assets/Roboto-Regular.ttf", 32);
    if (font == nullptr)
    {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    if (window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    // Enable VSync
    SDL_GL_SetSwapInterval(-1);
}

void Graphics::DrawTexture(Texture *texture)
{
    SDL_Rect r = texture->GetSDLRect();

    assert(renderer != nullptr);
    SDL_RenderCopy(renderer, texture->GetSDLTexture(), nullptr, &r);
}

void Graphics::SwapBuffers()
{
    assert(renderer != nullptr);
    SDL_RenderPresent(renderer);
}

void Graphics::DrawText(std::string text, SDL_Point location, SDL_Color color)
{
    SDL_Surface *creditsSurface = TTF_RenderText_Blended(font, text.c_str(), color);

    // is null if string has length zero
    if (creditsSurface)
    {
        SDL_Texture* creditsTexture = SDL_CreateTextureFromSurface(renderer, creditsSurface);
        assert(creditsTexture != nullptr);

        SDL_Rect Message_rect; //create a rect
        Message_rect.x = location.x;  //controls the rect's x coordinate
        Message_rect.y = location.y; // controls the rect's y coordinte
        Message_rect.w = creditsSurface->w; // controls the width of the rect
        Message_rect.h = creditsSurface->h; // controls the height of the rect

        SDL_FreeSurface(creditsSurface);
        creditsSurface = nullptr;

        assert(renderer != nullptr);
        SDL_RenderCopy(renderer, creditsTexture, nullptr, &Message_rect);
        SDL_DestroyTexture(creditsTexture);
        creditsTexture = nullptr;

    }


}

SDL_Rect Graphics::MeasureText(const std::string& stringstream)
{


    SDL_Surface *creditsSurface = TTF_RenderText_Blended(font, stringstream.c_str(), {255, 255, 255});

    // is null if string has length zero
    if (creditsSurface)
    {
        SDL_Rect r = creditsSurface->clip_rect;
        SDL_FreeSurface(creditsSurface);
        creditsSurface = nullptr;
        return r;
    }
    SDL_Rect empty = {0, 0, 0, 0};
    return empty;
}

void Graphics::Clean()
{
    assert(font != nullptr);
    TTF_CloseFont(font);
    font = nullptr;

    //Destroy window
    assert(window != nullptr);
    SDL_DestroyWindow(window);
    window = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}

void Graphics::DrawTexture(Texture *texture, SDL_Rect *dest)
{
    assert(texture != nullptr);

    auto sdlt = texture->GetSDLTexture();
    assert(sdlt != nullptr);

    assert(renderer != nullptr);
    assert(dest != nullptr);
    SDL_RenderCopy(renderer, sdlt, nullptr, dest);
}


void Graphics::DrawTexture(Texture *texture, SDL_Point *dest)
{
    assert(texture != nullptr);
    SDL_Rect rec = texture->GetSDLRect();

    assert(dest != nullptr);
    rec.x = dest->x;
    rec.y = dest->y;

    auto sdlt = texture->GetSDLTexture();
    assert(sdlt != nullptr);

    assert(renderer != nullptr);
    SDL_RenderCopy(renderer, sdlt, nullptr, &rec);
}

TTF_Font* Graphics::GetDefaultFont()
{
    return font;
}

