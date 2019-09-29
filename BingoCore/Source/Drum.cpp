
#include "Drum.hpp"

#include <algorithm>
#include <random>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include <cassert>


Drum::Drum(const unsigned int numberOfBalls) : NUMBER_OF_BALLS_AT_CREATION(numberOfBalls)
{
    if (numberOfBalls == 0)
        throw std::invalid_argument("The number of balls in a Drum can't be 0!");

    for (size_t i = 0; i < NUMBER_OF_BALLS_AT_CREATION; i++)
        balls.push_back(i + 1);

    // obtain a random number from hardware
    // seed the generator
    // NOTE: it's BUGGED on Windows with MinGW!!!!!
    static std::random_device rng;
    static std::default_random_engine urng(rng());
    std::shuffle(balls.begin(), balls.end(), urng);
}


std::vector<unsigned int> Drum::extract(const unsigned int n)
{
    if (n > balls.size())
        throw EmptyDrumException();

    std::vector<unsigned int> results;
    for (size_t i = 0; i < n; ++i)
    {
        results.push_back(balls.back());
        balls.pop_back();
    }

    return results;
}

unsigned int Drum::ballsLeft() const
{
    return balls.size();
}




