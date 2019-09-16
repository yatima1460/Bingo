
#include "Drum.hpp"

#include <algorithm>
#include <random>

Drum::Drum(int numberOfBalls)
{
    for (size_t i = 0; i < numberOfBalls; i++)
    {
        balls.push_back(i+1);
    }


    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(balls), std::end(balls), rng);
}

int Drum::Total() {
    return balls.size();
}


