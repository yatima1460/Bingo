
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"
#include "DrumUI.hpp"
#include "CardUI.hpp"

class NumerosButton : public ButtonWidget
{


private:

    Player& player;
    DrumUI& drumUI;
    std::vector<CardUI*> cards;

public:

    explicit NumerosButton(Player& player, std::vector<CardUI*> cards, DrumUI& drumUI);


    void Pressed() override;

};