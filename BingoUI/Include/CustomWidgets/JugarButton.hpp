
#pragma once

#include <Player.hpp>
#include <Game.hpp>
#include "GUI/ButtonWidget.hpp"
#include "DrumUI.hpp"

class JugarButton : public ButtonWidget
{


private:

    Game& game;
    std::vector<CardUI*> cards;
    DrumUI& drumUI;

public:

    explicit JugarButton(Game& game, std::vector<CardUI*> cards, DrumUI& drumUI);

    void Update() override;

    void Pressed() override;

};