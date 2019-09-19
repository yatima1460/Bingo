#include <SDL.h>
#include <cstdio>
#include <SDL_ttf.h>
#include <cassert>
#include <Player.hpp>
#include <string>
#include <sstream>

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The surface contained by the window
SDL_Surface *gScreenSurface = NULL;


TTF_Font *font;

SDL_Renderer *renderer;

SDL_Texture *background;

bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("Bingo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, -1, -1,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);


        renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

        TTF_Init();
        font = TTF_OpenFont("Assets/Roboto-Regular.ttf", 32);
        if (font == nullptr)
        {
            fprintf(stderr, "error: font not found\n");
            exit(EXIT_FAILURE);
        }

        if (gWindow == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
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

void close() {
    //Deallocate surface
    SDL_DestroyTexture(background);
    background = nullptr;

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}

#undef main

int main(int argc, char *args[])
{

    Player player;

#ifndef NDEBUG
    player.AddCredits(100);
#endif



    //Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        //Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {


            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while (!quit) {

                //Handle events on queue
                while (SDL_PollEvent(&e) != 0) {
                    //User requests quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                        //User presses a key
                    else if (e.type == SDL_KEYDOWN) {
                        //Select surfaces based on key press
                        switch (e.key.keysym.sym) {
                            case SDLK_ESCAPE:
                                quit = true;
                                break;

                        }

                    }
                }

                std::stringstream player_credits;

                player_credits << player.CreditsLeft();

                SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, player_credits.str().c_str(), {255, 255, 255});


                SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);





                //Apply the image
                SDL_RenderCopy(renderer, background, nullptr, nullptr);


                SDL_Rect Message_rect; //create a rect
                Message_rect.x = 1120 - surfaceMessage->w * 0.5f;  //controls the rect's x coordinate
                Message_rect.y = 20; // controls the rect's y coordinte
                Message_rect.w = surfaceMessage->w; // controls the width of the rect
                Message_rect.h = surfaceMessage->h; // controls the height of the rect

                SDL_RenderCopy(renderer, Message, nullptr, &Message_rect);

                //Update the surface
                SDL_RenderPresent(renderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}