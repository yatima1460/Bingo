
#include "Player.hpp"

#include <stdexcept>
#include <cassert>

unsigned int Player::CreditsLeft()
{
    return Credits;
}

bool Player::TryRemoveCredits(unsigned int Value)
{
    if (Value > Credits)
        return false;
    Credits -= Value;
    return true;
}

unsigned int Player::Collect()
{
    unsigned int win = Credits;
    Credits = 0;
    return win;
}

void Player::AddCredits(unsigned int Value)
{
    if (Value == 0)
    {
        throw std::invalid_argument("Trying to add 0 Credits to a PlayerRef!");
    }
    Credits += Value;
}

std::vector<std::shared_ptr<Card>>& Player::GetCards()
{
    return Cards;
}

Player::Player() : Credits(0)
{

    Cards = std::vector<std::shared_ptr<Card>>(4);

    for (int i = 0; i < 4; i++)
    {
        Cards[i] = std::make_shared<Card>(5, 3, 60);
    }
}

void Player::RerollCards()
{

    for (auto& card : Cards)
    {
        assert(card != nullptr);

        //auto newCard = new Card(CardInternal->Width, CardInternal->Height, CardInternal->MaxNumber);

        //delete CardInternal;

        //CardInternal = newCard;

        card->ReRoll();
    }

}
