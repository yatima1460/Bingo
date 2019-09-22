#pragma once


#include "Card.hpp"

class Prize
{


    /**
     * Checks if the Prize is won, and will return the win credits amount
     * @return
     */
    virtual unsigned int Check(Card* card) = 0;
};