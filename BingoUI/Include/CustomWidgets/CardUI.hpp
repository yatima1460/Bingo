
#pragma once

#include <Card.hpp>
#include "Texture.hpp"
#include "GUI/Widget.hpp"

class CardUI : public Widget
{

    void Draw() override;

    void Update() override;

    Texture& background;
    Card& card;
    Texture* cell = nullptr;
    std::vector<unsigned int> extracted;
    Texture* marked = nullptr;


public:
    CardUI(Card& card, Texture& background, Texture* cell, Texture* marked);

    void SetExtractedNumbers(std::vector<unsigned int> extracted);




};