
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"

class CloseButton : public ButtonWidget
{


public:

    explicit CloseButton();

    void Update() override;

    void Pressed() override;

};