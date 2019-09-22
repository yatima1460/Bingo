#include "BingoUI.hpp"


#include <SDL.h>
#include <cstdio>
#include <SDL_ttf.h>
#include <cassert>
#include <string>
#include <sstream>


#include "GUI/LabelWidget.hpp"
#include "GUI/ButtonWidget.hpp"

#include "Texture.hpp"
#include "Graphics.hpp"

#include "AssetsManager.hpp"


#define COBRAR_CHARGE 100

#define CARTON_COLUMN_0_X 50
#define CARTON_COLUMN_1_X 1135
#define CARTON_COLUMN_0_Y 100
#define CARTON_COLUMN_1_Y 450


//#include "CustomWidgets/CobrarButton.hpp"
//#include "CustomWidgets/NumerosButton.hpp"
#include "CustomWidgets/MonedasButton.hpp"
//#include "CustomWidgets/JuegoButton.hpp"


//void Cobrar()
//{
//    player->AddCredits(COBRAR_CHARGE);
//}
//
//
//void Quit()
//{
//    quit = true;
//}



//
//void Numeros()
//{
//    player->RerollCards();
//    for (CardUI* card: cards)
//    {
//        card->SetExtractedNumbers(std::vector<unsigned int>());
//    }
//    drumUI->SetBalls(std::vector<unsigned int>());
//}
//
//
//
//void Jugar()
//{
//    game->PlayOneGame();
//    auto latestBalls = game->ExtractedBalls();
//    drumUI->SetBalls(latestBalls);
//
//    for (CardUI* card: cards)
//    {
//        card->SetExtractedNumbers(latestBalls);
//    }
//
//}

void BuildUI()
{

}


BingoUI::BingoUI()
{

    player = new Player();

    game = new Game(*player);
    game->SetDrumSize(60);
    game->SetCardsSize(5, 3);
    game->SetCardsNumber(4);



    //Load media
    /*auto background = new Texture("Assets/Fondo_Juego.bmp");
    auto buttonBigNormal = new Texture("Assets/botongrande01.bmp");
    auto buttonBigHovered = new Texture("Assets/botongrande02.bmp");
    auto buttonSmallNormal = new Texture("Assets/botonpeque01.bmp");
    auto buttonSmallHovered = new Texture("Assets/botonpeque02.bmp");
    auto redX = new Texture("Assets/x.bmp");
    auto cartonBackground = new Texture("Assets/carton.bmp");
    auto celdaBackground = new Texture("Assets/celda.bmp");
    auto ball = new Texture("Assets/bola.bmp");
    auto marked = new Texture("Assets/sello1.bmp");*/

    auto ball = AssetsManager::Get<Texture>("bola");

    drumUI = new DrumUI(ball);

    auto background = AssetsManager::Get<Texture>("Fondo_Juego");


    widgets.push_back(drumUI);

    auto buttonBigNormal = AssetsManager::Get<Texture>("botongrande01");
    auto buttonBigHovered = AssetsManager::Get<Texture>("botongrande02");
    auto buttonSmallNormal = AssetsManager::Get<Texture>("botonpeque01");
    auto buttonSmallHovered = AssetsManager::Get<Texture>("botonpeque02");

    auto redX = AssetsManager::Get<Texture>("x");

    auto backgroundSize = background->GetSDLRect();
    auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
    auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();
    auto redXSize = redX->GetSDLRect();

    auto cobrar = new ButtonWidget("Cobrar", buttonBigNormal, buttonBigHovered);
    cobrar->SetPosition({0, backgroundSize.h - buttonBigNormalSize.h});
    //cobrar->SetCallback(&Cobrar);
    widgets.push_back(cobrar);

    auto numeros = new ButtonWidget("Numeros", buttonSmallNormal, buttonSmallHovered);
    numeros->SetPosition({buttonBigNormalSize.w, backgroundSize.h - buttonSmallNormalSize.h});
    //numeros->SetCallback(&Numeros);
    widgets.push_back(numeros);

    auto jugar = new ButtonWidget("JUGAR", buttonBigNormal, buttonBigHovered);
    jugar->SetPosition({backgroundSize.w - buttonBigNormalSize.w, backgroundSize.h - buttonBigNormalSize.h});
    //jugar->SetCallback(&Jugar);
    widgets.push_back(jugar);

    assert(player != nullptr);
    widgets.push_back(new MonedasButton(*player));


    auto redXButton = new ButtonWidget("", redX, redX);
    widgets.push_back(redXButton);
    redXButton->SetPosition({backgroundSize.w - redXSize.w, 0});
    //redXButton->SetCallback(&Quit);


    int CARD_LOCATIONS_X[4] = {CARTON_COLUMN_0_X, CARTON_COLUMN_1_X, CARTON_COLUMN_0_X, CARTON_COLUMN_1_X};
    int CARD_LOCATIONS_Y[4] = {CARTON_COLUMN_0_Y, CARTON_COLUMN_0_Y, CARTON_COLUMN_1_Y, CARTON_COLUMN_1_Y};

    auto cartonBackground = AssetsManager::Get<Texture>("carton");
    auto celdaBackground = AssetsManager::Get<Texture>("celda");
    auto marked = AssetsManager::Get<Texture>("sello1");

    for (size_t i = 0; i < game->GetCardsNumber(); ++i)
    {
        auto card = new CardUI(cartonBackground, celdaBackground, marked);
        SDL_Point cardPosition{CARD_LOCATIONS_X[i], CARD_LOCATIONS_Y[i]};
        card->SetPosition(cardPosition);
        card->SetCard(player->GetCards()[i]);
        widgets.push_back(card);
        cards.push_back(card);
    }

    auto creditos = new LabelWidget("$ 0");
    widgets.push_back(creditos);


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

        jugar->SetEnabled(player->CreditsLeft() != 0);


        for (Widget* button: widgets)
            button->Update();

        std::stringstream player_credits;
        player_credits << "$ " << player->CreditsLeft();
        std::string creditsString = player_credits.str();
        SDL_Rect size = Graphics::MeasureText(creditsString);
        creditos->SetText(creditsString);
        creditos->SetPosition({static_cast<int>(1120 - size.w / 2), 20});

        Graphics::DrawTexture(background);

        for (Widget* w: widgets)
            w->Draw();

        Graphics::SwapBuffers();
    }

    Graphics::Clean();
}