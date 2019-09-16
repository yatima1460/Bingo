
#include "Player.hpp"

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
    credits += Value;
}
