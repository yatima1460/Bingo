#include <stdexcept>
#include <Drum.hpp>
#include "Game.hpp"


/*int Game::Collect()
{
    int win = credits;
    credits = 0;
    return win;
}*/

void Game::PlayOneGame()
{


    Drum drum(60);

    std::vector<int> extracted = drum.Extract(30);

    
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

/*
int Game::CurrentCredits()
{
    return credits;
}
*/

void Game::ChangeCards(int N)
{

}

Game::Game(Player &player) : player(player)
{

}
