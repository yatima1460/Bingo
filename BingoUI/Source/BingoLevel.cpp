#include <cstdio>
#include <string>

#include <SDL.h>
#include <cassert>
#include <AssetsManager.hpp>
#include <Settings.hpp>

#include "BingoLevel.hpp"

#include "GUI/ImageWidget.hpp"

#include "Texture.hpp"
#include "Graphics.hpp"

#include "CustomWidgets/CobrarButton.hpp"
#include "CustomWidgets/NumerosButton.hpp"
#include "CustomWidgets/MonedasButton.hpp"
#include "CustomWidgets/JugarButton.hpp"
#include "CustomWidgets/CloseButton.hpp"
#include "CustomWidgets/CreditosLabel.hpp"


void BingoLevel::Update()
{
    for (auto widget: widgets)
        widget->Update();
}

void BingoLevel::Draw()
{
    for (auto widget: widgets)
        widget->Draw();
}

void BingoLevel::BeginLevel()
{

#if INITIAL_CREDITS > 0
    player.AddCredits(INITIAL_CREDITS);
#endif


    player.changeCards(/*CARTON_NUMBER, CARTON_WIDTH, CARTON_HEIGHT, DRUM_SIZE*/);
    // Create game settings
    //game = new Game(player);
    //game.SetDrumSize(DRUM_SIZE);
    //game.SetCardsSize(CARTON_WIDTH, CARTON_HEIGHT);
    //game.SetCardsNumber(CARTON_NUMBER);

    // Build user interface

    // Add game background
    widgets.push_back(new ImageWidget(*AssetsManager::Get<Texture>("Fondo_Juego")));

    // Add credits label
    widgets.push_back(new CreditosLabel());

    // Add cards




    int CARD_LOCATIONS_X[4] = {
            Settings::get<int>("CARTON_COLUMN_0_X"),
            Settings::get<int>("CARTON_COLUMN_1_X"),
            Settings::get<int>("CARTON_COLUMN_0_X"),
            Settings::get<int>("CARTON_COLUMN_1_X")};
    int CARD_LOCATIONS_Y[4] = {
            Settings::get<int>("CARTON_COLUMN_0_Y"),
            Settings::get<int>("CARTON_COLUMN_0_Y"),
            Settings::get<int>("CARTON_COLUMN_1_Y"),
            Settings::get<int>("CARTON_COLUMN_1_Y")};

    auto cartonBackground = AssetsManager::Get<Texture>("carton");
    auto celdaBackground = AssetsManager::Get<Texture>("celda");
    auto marked = AssetsManager::Get<Texture>("sello1");


    for (size_t i = 0; i < player.getCards().size(); i++)
    {
        std::shared_ptr<Card> c = player.getCards()[i];
        auto card = new CardUI(c, *cartonBackground, celdaBackground, marked);
        SDL_Point cardPosition{CARD_LOCATIONS_X[i], CARD_LOCATIONS_Y[i]};
        card->SetPosition(cardPosition);


        widgets.push_back(card);
        CardsUI.push_back(card);
    }

    // Add ExtractedBalls balls
    widgets.push_back(&drumUi);

    // Add buttons
    widgets.push_back(new CobrarButton());
    widgets.push_back(new NumerosButton());
    widgets.push_back(new MonedasButton());
    widgets.push_back(new JugarButton());
    widgets.push_back(new CloseButton());
}

void BingoLevel::EndLevel()
{

}

Player& BingoLevel::GetPlayer()
{
    return player;
}

DrumUI& BingoLevel::GetDrumUI()
{
    return drumUi;
}

std::vector<CardUI*> BingoLevel::GetCardsUI()
{
    return CardsUI;
}


