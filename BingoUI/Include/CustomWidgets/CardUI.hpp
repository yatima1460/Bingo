
#pragma once

#include <Card.hpp>
#include <memory>
#include "Texture.hpp"
#include "GUI/Widget.hpp"

class CardUI : public Widget
{

    void Draw() override;

    void Update() override;

    Texture& background;
    std::shared_ptr<Card> card;
    Texture* cell = nullptr;
    std::vector<unsigned int> extracted;
    Texture* marked = nullptr;


public:
    CardUI(std::shared_ptr<Card> card, Texture& background, Texture* cell, Texture* marked);

    void SetExtractedNumbers(std::vector<unsigned int> extracted);

    void ChangeCard(std::shared_ptr<Card> card);


};