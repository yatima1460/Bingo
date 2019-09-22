

#pragma once


#include <Player.hpp>
#include "GUI/LabelWidget.hpp"


class CreditosLabel : public LabelWidget
{


    Player& player;

protected:


public:


    CreditosLabel(Player& player);


    void Update() override;

};


