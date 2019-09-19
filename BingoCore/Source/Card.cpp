


#include <Drum.hpp>
#include "Card.hpp"


Card::Card(unsigned int Width, unsigned int Height, unsigned int DrumMaxNumber) : Width(Width), Height(Height),
                                                                                  DrumMaxNumber(DrumMaxNumber)
{
    Drum d(DrumMaxNumber);
    card = d.Extract(Width * Height);
}

/*
unsigned int Card::operator[]( int index)
{
    return card[index];
}
*/
