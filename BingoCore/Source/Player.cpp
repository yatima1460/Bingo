
#include "Player.hpp"

#include <stdexcept>

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

std::vector<Card *> Player::GetCards()
{
    return cards;
}
