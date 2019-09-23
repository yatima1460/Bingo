
#include <Config.hpp>
#include "Prizes/BingoPrize.hpp"

unsigned int BingoPrize::Check(Card& card, std::vector<unsigned int> extracted)
{

    std::vector<unsigned int> lookup(DRUM_SIZE);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    for (int i = 0; i < card.Width * card.Height; i++)
    {
        if (lookup[card[i]] == 0)
        {
            return 0;
        }
    }


    return BINGO_PRIZE;


}

BingoPrize::BingoPrize(unsigned int v) : Prize(v)
{

}
