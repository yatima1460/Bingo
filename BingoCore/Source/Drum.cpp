
#include "Drum.hpp"

#include <algorithm>
#include <random>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include <cassert>


Drum::Drum(unsigned int numberOfBalls) : NumberOfBalls(numberOfBalls)
{
    if (numberOfBalls == 0)
        throw std::invalid_argument("The number of balls in a Drum can't be 0!");

    for (size_t i = 0; i < NumberOfBalls; i++)
    {
        Balls.push_back(i + 1);
    }
    // obtain a random number from hardware
    // seed the generator
    static std::random_device rng;
    static std::default_random_engine urng(rng());
    std::shuffle(Balls.begin(), Balls.end(), urng);
}



std::vector<unsigned int> Drum::Extract(const unsigned int N)
{
    if (N > Balls.size())
        throw EmptyDrumException();

    std::vector<unsigned int> results;
    for (int i = 0; i < N; ++i)
    {
        results.push_back(Balls.back());
        Balls.pop_back();
    }

    return results;
}

unsigned int Drum::BallsLeft() const
{
    return Balls.size();
}




