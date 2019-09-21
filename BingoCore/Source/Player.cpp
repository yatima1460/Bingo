
#include "Player.hpp"

#include <stdexcept>
#include <cassert>

unsigned int Player::CreditsLeft()
{
    return credits;
}

bool Player::TryRemoveCredits(unsigned int Value)
{
    if (Value > credits)
        return false;
    credits -= Value;
    return true;
}

unsigned int Player::Collect()
{
    unsigned int win = credits;
    credits = 0;
    return win;
}

void Player::AddCredits(unsigned int Value)
{
    if (Value == 0)
    {
        throw std::invalid_argument("Trying to add 0 credits to a Player!");
    }
    credits += Value;
}

std::vector<Card*> Player::GetCards()
{
    return cards;
}

Player::Player() : credits(0)
{

    cards = std::vector<Card*>(4);

    for (int i = 0; i < 4; i++)
    {
        cards[i] = new Card(5, 3, 60);
    }
}

void Player::RerollCards()
{

    for (auto& card : cards)
    {
        assert(card != nullptr);

        //auto newCard = new Card(card->Width, card->Height, card->DrumMaxNumber);

        //delete card;

        //card = newCard;

        card->ReRoll();
    }

}
