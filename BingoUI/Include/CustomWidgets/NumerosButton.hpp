
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"
#include "DrumUI.hpp"
#include "CardUI.hpp"

class NumerosButton : public ButtonWidget
{


public:

    explicit NumerosButton();

    void Pressed() override;

};