


#pragma once


#include <Player.hpp>
#include "CustomWidgets/DrumUI.hpp"
#include "CustomWidgets/CardUI.hpp"
#include "Level.hpp"

class BingoLevel : public Level
{


    //DrumUIRef* DrumUIRef;
    std::vector<CardUI*> CardsUI;
    Player player;
    DrumUI drumUi;
    //Game& game;
    //Event handler


    std::vector<Widget*> widgets;


public:

    [[nodiscard]] Player& GetPlayer();

    [[nodiscard]] DrumUI& GetDrumUI();

    [[nodiscard]] std::vector<CardUI*> GetCardsUI();

    void BeginLevel() override;

    void Update() override;

    void Draw() override;

    void EndLevel() override;


};