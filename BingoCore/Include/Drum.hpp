#pragma once

#include <vector>
#include "BingoException.hpp"


class EmptyDrumException : BingoException
{

public:
    EmptyDrumException() : BingoException("You can't extract more balls than the ones left in the drum!")
    {

    }
};

/**
 * Object simulating a Drum with balls as unsigned ints
 * When the Drum is finished a new one needs to be created
 */
class Drum
{

    /**
     * Balls held by this Drum
     */
    std::vector<unsigned int> balls;




public:

    /**
     * Original number of balls when this Drum was created
     */
    const unsigned int NUMBER_OF_BALLS_AT_CREATION;

    /**
     * Creates a new random Drum
     * @param numberOfBalls the total number of balls inside
     */
    explicit Drum(unsigned int numberOfBalls);

    /**
     *  Extracts N balls from the drum
     *
     *  Complexity: theta(N)
    */
    [[nodiscard]] std::vector<unsigned int> extract(unsigned int n) noexcept(false);


    /**
     * Returns the number of balls left
     */
    [[nodiscard]] unsigned int ballsLeft() const;

};