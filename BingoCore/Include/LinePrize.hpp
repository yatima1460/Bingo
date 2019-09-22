
#pragma once

#include "Prize.hpp"


class LinePrize : public Prize
{


    /**
     * Checks if the Prize is won, and will return the win credits amount
     * @return
     */
    unsigned int Check(Card* card) override;
};

