
#include <Config.hpp>
#include "Prizes/DoubleLinePrize.hpp"

unsigned int DoubleLinePrize::Check(Card& card, std::vector<unsigned int> extracted)
{

    std::vector<unsigned int> lookup(DRUM_SIZE);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    int nlineswin = 0;
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
            nlineswin++;
        }
    }
    if (nlineswin == 2)
    {
        return DOUBLELINE_PRIZE;
    }

    return 0;


}

DoubleLinePrize::DoubleLinePrize(unsigned int value) : Prize(value)
{

}
