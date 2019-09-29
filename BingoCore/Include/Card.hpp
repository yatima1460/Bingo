#pragma once

#include <vector>
#include <stdexcept>

class Card
{


public:

    const std::vector<unsigned int> NUMBERS;

    /**
     * Number of columns
     */
    const unsigned int WIDTH;

    /**
     * Number of rows
     */
    const unsigned int HEIGHT;

    /**
     * Maximum number this card will hold
     * (it should be the Drum size)
     */
    const unsigned int MAX_NUMBER;

    /**
     * Creates a new Bingo Card
     * The card is shuffled at creation time
     *
     * @param width number of columns
     * @param height number of rows
     * @param maxNumber maximum number for the randomly generated numbers on the card
     */
    Card(unsigned int width, unsigned int height, unsigned int maxNumber);


    [[nodiscard]] const unsigned int& operator[](int index) const
    {
        if (index < 0 || index >= NUMBERS.size())
            throw std::invalid_argument("Card number index is invalid");
        return NUMBERS[index];
    }

};


