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
    auto background = new Texture("Assets/Fondo_Juego.bmp");
    auto buttonBigNormal = new Texture("Assets/botongrande01.bmp");
    auto buttonBigHovered = new Texture("Assets/botongrande02.bmp");
    auto buttonSmallNormal = new Texture("Assets/botonpeque01.bmp");
    auto buttonSmallHovered = new Texture("Assets/botonpeque02.bmp");

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    std::vector<Button *> buttons;


    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();

    buttons.push_back(new Button("Cobrar", buttonBigNormal, buttonBigHovered));
    buttons[0]->SetPosition({0, backgroundSize.h - buttonBigNormalSize.h});
    buttons.push_back(new Button("Numeros", buttonSmallNormal, buttonSmallHovered));
    buttons[1]->SetPosition({buttonBigNormalSize.w, backgroundSize.h - buttonSmallNormalSize.h});
    buttons.push_back(new Button("JUGAR", buttonBigNormal, buttonBigHovered));
    buttons[2]->SetPosition({backgroundSize.w - buttonBigNormalSize.w, backgroundSize.h - buttonBigNormalSize.h});
    buttons.push_back(new Button("Monedas", buttonSmallNormal, buttonSmallHovered));
    buttons[3]->SetPosition({backgroundSize.w - buttonBigNormalSize.w - buttonSmallNormalSize.w,
                             backgroundSize.h - buttonSmallNormalSize.h});

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


    Graphics::Clean();

    return EXIT_SUCCESS;
}