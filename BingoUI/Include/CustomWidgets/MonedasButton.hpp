
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"

class MonedasButton : public ButtonWidget
{


private:

    Player& player;

public:

    MonedasButton(Player& player);

    void Update() override;

    void Pressed() override;

};