#pragma once


#include <sstream>
#include "Card.hpp"

struct Prize
{


public:


    unsigned int MINIMUM_COLUMNS;
    unsigned int MINIMUM_ROWS;
    unsigned int VALUE;


    explicit Prize(unsigned int minimumRows, unsigned int minimumColumns, unsigned int value) :
            MINIMUM_COLUMNS(minimumColumns),
            MINIMUM_ROWS(minimumRows),
            VALUE(value)
    {

    }


    [[nodiscard]] std::string toString() const
    {
        std::stringstream ss;
        ss << "H" << MINIMUM_ROWS;
        ss << "V" << MINIMUM_COLUMNS;
        ss << "C" << VALUE;
        return ss.str();
    }


/*    *//**
     * Given a card and the extracted numbers checks if the Prize is won, and will return the win credits amount
     *
     * @param card
     * @param extracted
     * @return
     *//*
    [[nodiscard]] virtual unsigned int Check(Card& card, std::vector<unsigned int> extracted) = 0;


    */



/*
    virtual ~Prize() = default;*/
};


