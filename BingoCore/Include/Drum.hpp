#pragma once

#include <vector>
#include "EmptyDrumException.hpp"


/**
 * Object simulating a Drum with balls as unsigned ints
 * When the Drum is finished a new one needs to be created
 */
class Drum
{
    /**
     * Balls held by this Drum
     */
    std::vector<unsigned int> Balls;

    /**
     * Original number of balls when this Drum was created
     */
    const unsigned int NumberOfBalls;


public:

    /**
     * Creates a new random Drum
     * @param numberOfBalls the total number of balls inside
     */
    explicit Drum(unsigned int numberOfBalls);

    /**
     *  Extracts N balls from the drum
    */
    [[nodiscard]] std::vector<unsigned int> Extract(unsigned int N);


    /**
     * Returns the number of balls left
     */
    [[nodiscard]] unsigned int BallsLeft() const;

};