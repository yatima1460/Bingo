
#include "Drum.hpp"

#include <algorithm>
#include <random>
#include <stdexcept>

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

std::vector<int> Drum::Extract(const int N)
{
    if (N > balls.size())
    {
        throw std::invalid_argument("You can't extract more balls than the ones left in the drum!");
    }

    std::vector<int> results;
    for (int i = 0; i < N; ++i)
    {
        results.push_back(balls.back());
        balls.pop_back();
    }

    return results;
}


