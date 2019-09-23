
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"
#include "DrumUI.hpp"

class JugarButton : public ButtonWidget
{


public:

    explicit JugarButton();

    void Update() override;

    void Pressed() override;

};