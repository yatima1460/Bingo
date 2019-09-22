

#pragma once


#include <Player.hpp>
#include "GUI/LabelWidget.hpp"


class CreditosLabel : public LabelWidget
{


    Player& player;

protected:


public:


    explicit CreditosLabel(Player& player);


    void Update() override;

};


