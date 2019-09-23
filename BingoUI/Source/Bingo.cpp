#include <cstdio>
#include <string>

#include <SDL.h>
#include <Config.hpp>

#include "Bingo.hpp"

#include "GUI/ImageWidget.hpp"

#include "Texture.hpp"
#include "Graphics.hpp"
#include "AssetsManager.hpp"

#include "CustomWidgets/CobrarButton.hpp"
#include "CustomWidgets/NumerosButton.hpp"
#include "CustomWidgets/MonedasButton.hpp"
#include "CustomWidgets/JugarButton.hpp"
#include "CustomWidgets/CloseButton.hpp"
#include "CustomWidgets/CreditosLabel.hpp"




Bingo::Bingo()
{
    // Create game settings
    player = new Player();
#if INITIAL_CREDITS > 0
    player->AddCredits(INITIAL_CREDITS);
#endif
    game = new Game(*player);
    game->SetDrumSize(DRUM_SIZE);
    game->SetCardsSize(CARTON_WIDTH, CARTON_HEIGHT);
    game->SetCardsNumber(CARTON_NUMBER);

    // Build user interface

    // Add game background
    widgets.push_back(new ImageWidget(*AssetsManager::Get<Texture>("Fondo_Juego")));

    // Add Credits label
    widgets.push_back(new CreditosLabel(*player));

    // Add Cards
    int CARD_LOCATIONS_X[4] = {CARTON_COLUMN_0_X, CARTON_COLUMN_1_X, CARTON_COLUMN_0_X, CARTON_COLUMN_1_X};
    int CARD_LOCATIONS_Y[4] = {CARTON_COLUMN_0_Y, CARTON_COLUMN_0_Y, CARTON_COLUMN_1_Y, CARTON_COLUMN_1_Y};
    auto cartonBackground = AssetsManager::Get<Texture>("carton");
    auto celdaBackground = AssetsManager::Get<Texture>("celda");
    auto marked = AssetsManager::Get<Texture>("sello1");
    for (size_t i = 0; i < game->GetCardsNumber(); ++i)
    {
        std::shared_ptr<Card> c = player->GetCards()[i];
        auto card = new CardUI(*c, *cartonBackground, celdaBackground, marked);
        SDL_Point cardPosition{CARD_LOCATIONS_X[i], CARD_LOCATIONS_Y[i]};
        card->SetPosition(cardPosition);


        widgets.push_back(card);
        cards.push_back(card);
    }

    // Add ExtractedBalls balls
    auto drumUI = new DrumUI();
    widgets.push_back(drumUI);

    // Add buttons
    widgets.push_back(new CobrarButton(*player));
    widgets.push_back(new NumerosButton(*player, cards, *drumUI));
    widgets.push_back(new MonedasButton(*player));
    widgets.push_back(new JugarButton(*game, cards, *drumUI));
    widgets.push_back(new CloseButton(&quit));

    // Main loop
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
                case SDL_QUIT:
                {
                    // Pressing the SDLWindow [X] closes
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

        for (auto widget: widgets)
            widget->Update();

        for (auto widget: widgets)
            widget->Draw();

        Graphics::SwapBuffers();
    }

    //TODO: use RAII



}