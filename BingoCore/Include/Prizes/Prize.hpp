#pragma once


#include "Card.hpp"

class Prize
{

protected:
    unsigned int value;

public:


    explicit Prize(unsigned int value) : value(value)
    {

    }

    /**
     * Given a card and the extracted numbers checks if the Prize is won, and will return the win credits amount
     *
     * @param card
     * @param extracted
     * @return
     */
    [[nodiscard]] virtual unsigned int Check(Card& card, std::vector<unsigned int> extracted) = 0;


    virtual ~Prize() = default;
};


