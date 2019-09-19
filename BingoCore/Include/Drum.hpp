#pragma once

#include <vector>

class Drum
{
    std::vector<unsigned int> balls;
    

public:

    explicit Drum(unsigned int numberOfBalls);

    /**
     *  Extracts N balls from the drum
    */
    std::vector<unsigned int> Extract(unsigned int N);

    /**
     * Total number of balls left
     * @return
     */
    unsigned int Total();
};