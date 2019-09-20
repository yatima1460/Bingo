#include <SDL.h>
#include <cstdio>
#include <SDL_ttf.h>
#include <cassert>
#include <string>
#include <sstream>

#include <Player.hpp>
#include <Game.hpp>


#include "Texture.hpp"
#include "Graphics.hpp"

#include "Button.hpp"


Texture *background;


void loadMedia()
{
    background = new Texture("Assets/Fondo_Juego.bmp");
}


#undef main
int main(int argc, char *args[])
{

    Player player;

    Game game(player);
    game.SetDrumSize(60);
    game.SetCardsSize(5, 3);


#ifndef NDEBUG
    player.AddCredits(100);
#endif

    //Start up SDL
    Graphics::Init();

    //Load media
    loadMedia();

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    // Enable VSync
    SDL_GL_SetSwapInterval(-1);

    std::vector<Button *> buttons;

    Texture *buttonBigNormal = new Texture("Assets/botongrande01.bmp");
    Texture *buttonBigHovered = new Texture("Assets/botongrande02.bmp");

    buttons.push_back(new Button("Cobrar", buttonBigNormal, buttonBigHovered));
    buttons.push_back(new Button("Numeros", buttonBigNormal, buttonBigHovered));
    buttons.push_back(new Button("Monedas", buttonBigNormal, buttonBigHovered));
    buttons.push_back(new Button("JUGAR", buttonBigNormal, buttonBigHovered));


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

        for (Button *button: buttons)
        {
            button->Update();
        }


        // Draw background
        Graphics::DrawTexture(background);
        //SDL_RenderCopy(Graphics::GetSDLRenderer(), background, nullptr, nullptr);

        for (Button *button: buttons)
        {
            button->Draw();
        }

        // Draw credits
        std::stringstream player_credits;
        player_credits << "$ " << player.CreditsLeft();
        std::string creditsString = player_credits.str();

        SDL_Rect size = Graphics::MeasureText(creditsString);
        Graphics::DrawText(creditsString, {static_cast<int>(1120 - size.w / 2), 20}, {255, 255, 255});


        Graphics::SwapBuffers();
    }

    //Free resources and close SDL

    //Deallocate background


    Graphics::Clean();

    return EXIT_SUCCESS;
}