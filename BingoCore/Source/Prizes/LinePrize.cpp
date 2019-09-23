
#include <Config.hpp>
#include "Prizes/LinePrize.hpp"

unsigned int LinePrize::Check(Card& card, std::vector<unsigned int> extracted)
{

    std::vector<unsigned int> lookup(DRUM_SIZE);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    for (size_t row = 0; row < card.Height; row++)
    {

        bool lineOk = true;
        for (size_t column = 0; column < card.Width; column++)
        {
            size_t index = row * card.Width + column;

            unsigned int cardNumber = card[index];
            if (lookup[cardNumber] != 1)
            {
                lineOk = false;
                break;

            }


        }
        if (lineOk)
        {
            return value;
        }
    }

    return 0;

}

LinePrize::LinePrize(unsigned int value) : Prize(value)
{

}
