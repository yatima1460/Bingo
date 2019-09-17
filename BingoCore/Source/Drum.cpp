
#include "Drum.hpp"

#include <algorithm>
#include <random>
#include <stdexcept>

Drum::Drum(unsigned int numberOfBalls)
{
    for (size_t i = 0; i < numberOfBalls; i++)
    {
        balls.push_back(i + 1);
    }


    std::random_device dev;
    auto rng = std::default_random_engine(dev());
    std::shuffle(std::begin(balls), std::end(balls), rng);
}

unsigned int Drum::Total()
{
    return balls.size();
}

std::vector<unsigned int> Drum::Extract(const unsigned int N)
{
    if (N > balls.size())
    {
        throw std::invalid_argument("You can't extract more balls than the ones left in the drum!");
    }

    std::vector<unsigned int> results;
    for (int i = 0; i < N; ++i)
    {
        results.push_back(balls.back());
        balls.pop_back();
    }

    return results;
}


