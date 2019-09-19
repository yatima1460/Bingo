#include <SDL.h>
#include <cstdio>
#include <SDL_ttf.h>
#include <cassert>
#include <Player.hpp>
#include <string>
#include <sstream>

SDL_Window *gWindow = nullptr;
SDL_Surface *gScreenSurface = nullptr;
SDL_Renderer *renderer;
SDL_Texture *background;
TTF_Font *font;


void init()
{

    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    gWindow = SDL_CreateWindow(
            "Bingo",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            -1, -1,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);


    renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    TTF_Init();
    font = TTF_OpenFont("Assets/Roboto-Regular.ttf", 32);
    if (font == nullptr)
    {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    if (gWindow == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    //Get window surface
    gScreenSurface = SDL_GetWindowSurface(gWindow);
}

bool loadMedia()
{
    bool success = true;

    //Load splash image
    SDL_Surface *background_surface = SDL_LoadBMP("Assets/Fondo_Juego.bmp");
    assert(background_surface != nullptr);

    background = SDL_CreateTextureFromSurface(renderer, background_surface);
    assert(background != nullptr);

    SDL_FreeSurface(background_surface);
    return success;
}


#undef main
int main(int argc, char *args[])
{

    Player player;

#ifndef NDEBUG
    player.AddCredits(100);
#endif

    //Start up SDL
    init();

    //Load media
    loadMedia();

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    // Enable VSync
    SDL_GL_SetSwapInterval(-1);


    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
                case SDL_QUIT:
                {
                    quit = true;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch (e.key.keysym.sym)
                    {
                        // ESC closes
                        case SDLK_ESCAPE:
                            quit = true;
                            break;

                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }


        // Draw background
        SDL_RenderCopy(renderer, background, nullptr, nullptr);

        // Draw credits
        std::stringstream player_credits;
        player_credits << "$ " << player.CreditsLeft();
        SDL_Surface *creditsSurface = TTF_RenderText_Blended(font, player_credits.str().c_str(), {255, 255, 255});
        SDL_Texture *creditsTexture = SDL_CreateTextureFromSurface(renderer, creditsSurface);
        SDL_FreeSurface(creditsSurface);
        SDL_Rect Message_rect; //create a rect
        Message_rect.x = 1120 - creditsSurface->w * 0.5f;  //controls the rect's x coordinate
        Message_rect.y = 20; // controls the rect's y coordinte
        Message_rect.w = creditsSurface->w; // controls the width of the rect
        Message_rect.h = creditsSurface->h; // controls the height of the rect
        SDL_RenderCopy(renderer, creditsTexture, nullptr, &Message_rect);
        SDL_DestroyTexture(creditsTexture);

        // Swap buffers
        SDL_RenderPresent(renderer);


    }

    //Free resources and close SDL

    //Deallocate background
    SDL_DestroyTexture(background);
    background = nullptr;

    TTF_CloseFont(font);
    font = nullptr;

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    //Quit SDL subsystems
    SDL_Quit();

    return EXIT_SUCCESS;
}