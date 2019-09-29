#include <Drum.hpp>
#include "Card.hpp"


Card::Card(const unsigned int width, const unsigned int height, const unsigned int maxNumber) : WIDTH(width),
                                                                                                HEIGHT(height),
                                                                                                MAX_NUMBER(maxNumber),
                                                                                                NUMBERS(Drum(
                                                                                                        maxNumber).extract(
                                                                                                        width * height))
{

}