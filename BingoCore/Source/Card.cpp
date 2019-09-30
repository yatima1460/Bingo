#include <Drum.hpp>
#include <cassert>
#include "Card.hpp"


Card::Card(const unsigned int width, const unsigned int height, const unsigned int maxNumber) : WIDTH(width),
                                                                                                HEIGHT(height),
                                                                                                MAX_NUMBER(maxNumber),
                                                                                                NUMBERS(Drum(
                                                                                                        maxNumber).extract(
                                                                                                        width * height))
{
    if (width == 0)
        throw std::invalid_argument("Card with can't be zero!");
    if (height == 0)
        throw std::invalid_argument("Card height can't be zero!");
    if (maxNumber == 0)
        throw std::invalid_argument("Card maxNumber can't be zero!");
    if (width * height > maxNumber)
        throw std::invalid_argument("Card maxNumber can't be smaller than card size!");

}