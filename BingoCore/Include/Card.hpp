#pragma once

#include <vector>

class Card
{

private:

    std::vector<unsigned int> CardInternal;

public:

    /**
     * Number of columns
     */
    const unsigned int Width;

    /**
     * Number of rows
     */
    const unsigned int Height;

    /**
     * Maximum number this card will hold
     */
    const unsigned int MaxNumber;

    /**
     * Creates a new Bingo Card
     * The card is shuffled at creation time
     *
     * @param Width number of columns
     * @param Height number of rows
     * @param MaxNumber maximum number for the randomly generated numbers on the card
     */
    Card(unsigned int Width, unsigned int Height, unsigned int MaxNumber);

    [[deprecated]] void ReRoll();


    [[nodiscard]] const unsigned int& operator[](int index) const
    {
        return CardInternal[index];
    }

};


