
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"

class CobrarButton : public ButtonWidget
{


private:

    Player& player;

public:

    explicit CobrarButton(Player& player);


    void Pressed() override;

};