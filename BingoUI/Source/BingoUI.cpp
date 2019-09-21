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
#include "CardUI.hpp"

#define COBRAR_CHARGE 100

#define CARTON_COLUMN_0_X 50
#define CARTON_COLUMN_1_X 1135
#define CARTON_COLUMN_0_Y 100
#define CARTON_COLUMN_1_Y 450




Player* player;

void Cobrar()
{
    player->AddCredits(COBRAR_CHARGE);
}


//Main loop flag
bool quit = false;

void Monedas()
{
    player->Collect();
}

void Quit()
{
    quit = true;
}


#undef main
int main(int argc, char *args[])
{

    player = new Player();

    Game game(*player);
    game.SetDrumSize(60);
    game.SetCardsSize(5, 3);




    //Start up SDL
    Graphics::Init();

    //Load media
    auto background = new Texture("Assets/Fondo_Juego.bmp");
    auto buttonBigNormal = new Texture("Assets/botongrande01.bmp");
    auto buttonBigHovered = new Texture("Assets/botongrande02.bmp");
    auto buttonSmallNormal = new Texture("Assets/botonpeque01.bmp");
    auto buttonSmallHovered = new Texture("Assets/botonpeque02.bmp");
    auto redX = new Texture("Assets/x.bmp");
    auto cartonBackground = new Texture("Assets/carton.bmp");
    auto celdaBackground = new Texture("Assets/celda.bmp");



    //Event handler
    SDL_Event e;

    std::vector<Widget*> widgets;


    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();
    auto redXSize = redX->GetSDLRect();

    auto cobrar = new Button("Cobrar", buttonBigNormal, buttonBigHovered);
    cobrar->SetPosition({0, backgroundSize.h - buttonBigNormalSize.h});
    cobrar->SetCallback(&Cobrar);
    widgets.push_back(cobrar);

    auto numeros = new Button("Numeros", buttonSmallNormal, buttonSmallHovered);
    numeros->SetPosition({buttonBigNormalSize.w, backgroundSize.h - buttonSmallNormalSize.h});
    widgets.push_back(numeros);

    auto jugar = new Button("JUGAR", buttonBigNormal, buttonBigHovered);
    jugar->SetPosition({backgroundSize.w - buttonBigNormalSize.w, backgroundSize.h - buttonBigNormalSize.h});
    widgets.push_back(jugar);

    auto monedas = new Button("Monedas", buttonSmallNormal, buttonSmallHovered);
    monedas->SetPosition({backgroundSize.w - buttonBigNormalSize.w - buttonSmallNormalSize.w,
                          backgroundSize.h - buttonSmallNormalSize.h});
    monedas->SetCallback(&Monedas);
    widgets.push_back(monedas);

    auto redXButton = new Button("", redX, redX);
    widgets.push_back(redXButton);
    redXButton->SetPosition({backgroundSize.w - redXSize.w, 0});
    redXButton->SetCallback(&Quit);


    auto card1 = new CardUI(cartonBackground, celdaBackground);
    SDL_Point card1Position{CARTON_COLUMN_0_X, CARTON_COLUMN_0_Y};
    card1->SetPosition(card1Position);
    card1->SetCard(player->GetCards()[0]);
    widgets.push_back(card1);

    auto card2 = new CardUI(cartonBackground, celdaBackground);
    SDL_Point card2Position{CARTON_COLUMN_1_X, CARTON_COLUMN_0_Y};
    card2->SetPosition(card2Position);
    card2->SetCard(player->GetCards()[1]);
    widgets.push_back(card2);

    auto card3 = new CardUI(cartonBackground, celdaBackground);
    SDL_Point card3Position{CARTON_COLUMN_0_X, CARTON_COLUMN_1_Y};
    card3->SetPosition(card3Position);
    card3->SetCard(player->GetCards()[2]);
    widgets.push_back(card3);

    auto card4 = new CardUI(cartonBackground, celdaBackground);
    SDL_Point card4Position{CARTON_COLUMN_1_X, CARTON_COLUMN_1_Y};
    card4->SetPosition(card4Position);
    card4->SetCard(player->GetCards()[3]);
    widgets.push_back(card4);



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

        for (Widget* button: widgets)
        {
            button->Update();
        }


        // Draw background
        Graphics::DrawTexture(background);
        //SDL_RenderCopy(Graphics::GetSDLRenderer(), background, nullptr, nullptr);

        for (Widget* w: widgets)
        {
            w->Draw();
        }

        // Draw credits
        std::stringstream player_credits;
        player_credits << "$ " << player->CreditsLeft();
        std::string creditsString = player_credits.str();

        SDL_Rect size = Graphics::MeasureText(creditsString);
        Graphics::DrawText(creditsString, {static_cast<int>(1120 - size.w / 2), 20}, {255, 255, 255});


        Graphics::SwapBuffers();
    }


    Graphics::Clean();

    return EXIT_SUCCESS;
}