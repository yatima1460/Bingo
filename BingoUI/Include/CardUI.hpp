
#pragma once

#include "Texture.hpp"
#include "Widget.hpp"

class CardUI : public Widget
{

    void Draw() override;

    void Update() override;

    Texture* background = nullptr;
    Card* card = nullptr;
    Texture* cell = nullptr;


public:
    CardUI(Texture* background, Texture* cell);


    void SetCard(Card* card);



};