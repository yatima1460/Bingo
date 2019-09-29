/*

#include <algorithm>
#include "Prizes/DoubleLinePrize.hpp"

unsigned int DoubleLinePrize::Check(Card& card, std::vector<unsigned int> extracted)
{
    unsigned int maxNExtracted = *std::max_element(std::begin(extracted), std::end(extracted));
    unsigned int maxNCard = *std::max_element(std::begin(card.NUMBERS), std::end(card.NUMBERS));
    std::vector<unsigned int> lookup(std::max(maxNExtracted, maxNCard) + 1);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    int nlineswin = 0;
    for (size_t row = 0; row < card.HEIGHT; row++)
    {

        bool lineOk = true;
        for (size_t column = 0; column < card.WIDTH; column++)
        {
            size_t index = row * card.WIDTH + column;

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
        return VALUE;
    }

    return 0;


}

DoubleLinePrize::DoubleLinePrize(unsigned int value) : Prize(value)
{

}
*/
