#include <stdexcept>
#include <Drum.hpp>
#include "Game.hpp"
#include "OutOfCreditsException.hpp"
#include <cassert>
/*int Game::Collect()
{
    int win = credits;
    credits = 0;
    return win;
}*/


Game::Game(Player &player) : player(player)
{


}

void Game::PlayOneGame()
{

    /* if (this->maxCards > player.CreditsLeft())
     {
         throw OutOfCreditsException();
     }*/

    if (!player.TryRemoveCredits(this->maxCards))
    {
        throw OutOfCreditsException();
    }

    assert(drumSize != 0);
    Drum drum(drumSize);


    extracted = drum.Extract(30);



}

void Game::PlayNGames(unsigned int N)
{
/*    for (int i = 0; i < N; ++i)
    {
        PlayOneGame();
    }*/
}

void Game::InsertCredits(unsigned int N)
{

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



void Game::SetCardsNumber(unsigned int N)
{
    if (N == 0)
    {
        throw std::invalid_argument("Number of cards need to be at least 1");
    }
    this->maxCards = N;

    cards = std::vector<Card *>(N);

    // FIXME: delete old cards

    for (size_t i = 0; i < N; i++)
    {
        cards[i] = new Card(this->width, this->height, this->drumSize);
    }
}

std::vector<unsigned int> Game::ExtractedBalls()
{
    return extracted;
}

unsigned int Game::GetCardsNumber()
{
    return this->maxCards;
}

void Game::SetDrumSize(unsigned int N)
{
    this->drumSize = N;
}

void Game::SetCardsSize(unsigned int Width, unsigned int Height)
{
    this->width = Width;
    this->height = Height;
}

std::vector<Card *> Game::GetCards()
{
    return cards;
}
