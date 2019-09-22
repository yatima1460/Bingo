
#pragma once

#include <Player.hpp>
#include "GUI/ButtonWidget.hpp"

class CloseButton : public ButtonWidget
{
private:

    bool* quit;


public:

    explicit CloseButton(bool* quit);

    void Update() override;

    void Pressed() override;

};