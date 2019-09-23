


#include <Drum.hpp>
#include "Card.hpp"


Card::Card(const unsigned int Width, const unsigned int Height, const unsigned int MaxNumber) : Width(Width),
                                                                                                Height(Height),
                                                                                                MaxNumber(MaxNumber)
{
    ReRoll();
}

void Card::ReRoll()
{
    Drum d(MaxNumber);
    CardInternal = d.Extract(Width * Height);
}

/*
unsigned int Card::operator[]( int index)
{
    return CardInternal[index];
}
*/
