#pragma once


#include "Widget.hpp"

#include <string>


class LabelWidget : public Widget
{


    std::string text;
    SDL_Color color = {255, 255, 255};

public:
    explicit LabelWidget(std::string text);

    LabelWidget();

    void Update() override
    {

    }

    void Draw() override;


    void SetText(std::string basicString);
};