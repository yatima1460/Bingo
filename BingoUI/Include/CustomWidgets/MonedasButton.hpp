
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"

class MonedasButton : public ButtonWidget
{

public:

    explicit MonedasButton();

    void Update() override;

    void Pressed() override;

};