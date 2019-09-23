#include <algorithm>
#include "Prizes/BingoPrize.hpp"

unsigned int BingoPrize::Check(Card& card, std::vector<unsigned int> extracted)
{

    unsigned int maxNExtracted = *std::max_element(std::begin(extracted), std::end(extracted));
    unsigned int maxNCard = *std::max_element(std::begin(card.Numbers), std::end(card.Numbers));
    std::vector<unsigned int> lookup(std::max(maxNExtracted, maxNCard) + 1);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    for (int i = 0; i < card.Width * card.Height; i++)
    {
        if (lookup[card[i]] == 0)
        {
            return 0;
        }
    }


    return value;


}

BingoPrize::BingoPrize(unsigned int v) : Prize(v)
{

}
