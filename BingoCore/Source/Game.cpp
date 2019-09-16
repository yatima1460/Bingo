#include <stdexcept>
#include "Game.hpp"


void Game::Collect()
{
    credits = 0;
}

void Game::PlayOneGame()
{

}

void Game::PlayNGames(int N)
{
/*    for (int i = 0; i < N; ++i)
    {
        PlayOneGame();
    }*/
}

void Game::InsertCredits(int N)
{
    if (N < 0)
    {
        throw std::invalid_argument("Can't insert a negative number of credits!");
    }
    if (N == 0)
    {
        throw std::invalid_argument("Can't insert a 0 number of credits!");
    }

    credits += N;
}
