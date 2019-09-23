#pragma once

#include "Prize.hpp"


class DoubleLinePrize : public Prize
{

public:

    explicit DoubleLinePrize(unsigned int value);

    /**
     * Checks if the Prize is won, and will return the win credits amount
     * @return
     */
    unsigned int Check(Card& card, std::vector<unsigned int> extracted) override;
};

