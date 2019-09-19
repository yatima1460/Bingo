
#include "Drum.hpp"

#include <algorithm>
#include <random>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include <cassert>


Drum::Drum(unsigned int numberOfBalls)
{

    // obtain a random number from hardware
    // seed the generator



    // "random_device" seems to have a problem with MingGW
    // entropy is 0 here, at least on my PC
    // double d = rd.entropy();
    //assert(d != 0.0f);

    for (size_t i = 0; i < numberOfBalls; i++)
    {
        balls.push_back(i + 1);
    }


    static std::random_device rng;
    static std::default_random_engine urng(rng());
    std::shuffle(balls.begin(), balls.end(), urng);
    //std::random_device dev;
    //auto rng = std::default_random_engine(dev());

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


