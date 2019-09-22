#include <cstdio>
#include <cassert>
#include <string>
#include <sstream>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Bingo.hpp"

#include "GUI/LabelWidget.hpp"
#include "GUI/ButtonWidget.hpp"
#include "GUI/ImageWidget.hpp"

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
#include "CustomWidgets/CloseButton.hpp"
#include "CustomWidgets/CreditosLabel.hpp"
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

void Bingo::BuildUI()
{
    // Add game background
    widgets.push_back(new ImageWidget(*AssetsManager::Get<Texture>("Fondo_Juego")));

    // Add credits label
    widgets.push_back(new CreditosLabel(*player));

    // Add cards
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

    // Add extracted balls
    widgets.push_back(new DrumUI());

    // Add buttons
    //widgets.push_back(new CobrarButton(*player));
    //widgets.push_back(new NumerosButton(*player, cards, drumUI));
    widgets.push_back(new MonedasButton(*player));
    //widgets.push_back(new JugarButton(*player));
    widgets.push_back(new CloseButton(&quit));
}


Bingo::Bingo()
{
    player = new Player();
    game = new Game(*player);
    game->SetDrumSize(60);
    game->SetCardsSize(5, 3);
    game->SetCardsNumber(4);


    BuildUI();


    /* auto background = AssetsManager::Get<Texture>("Fondo_Juego");

     auto buttonBigNormal = AssetsManager::Get<Texture>("botongrande01");
     auto buttonBigHovered = AssetsManager::Get<Texture>("botongrande02");
     auto buttonSmallNormal = AssetsManager::Get<Texture>("botonpeque01");
     auto buttonSmallHovered = AssetsManager::Get<Texture>("botonpeque02");



     auto backgroundSize = background->GetSDLRect();
     auto buttonBigNormalSize = buttonBigNormal->GetSDLRect();
     auto buttonSmallNormalSize = buttonSmallNormal->GetSDLRect();*/



/*    auto cobrar = new ButtonWidget("Cobrar", buttonBigNormal, buttonBigHovered);
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
    widgets.push_back(jugar);*/


    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
                case SDL_QUIT:
                {
                    // Pressing the window [X] closes
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

        //jugar->SetEnabled(player->CreditsLeft() != 0);


        for (auto widget: widgets)
            widget->Update();

        for (auto widget: widgets)
            widget->Draw();

        Graphics::SwapBuffers();
    }

    //TODO: use RAII
    Graphics::Clean();
}