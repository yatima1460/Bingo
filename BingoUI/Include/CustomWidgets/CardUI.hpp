
#pragma once

#include "Texture.hpp"
#include "GUI/Widget.hpp"

class CardUI : public Widget
{

    void Draw() override;

    void Update() override;

    Texture* background = nullptr;
    Card* card = nullptr;
    Texture* cell = nullptr;
    std::vector<unsigned int> extracted;
    Texture* marked = nullptr;


public:
    CardUI(Texture* background, Texture* cell, Texture* marked);

    void SetExtractedNumbers(std::vector<unsigned int> extracted);


    void SetCard(Card* card);



};