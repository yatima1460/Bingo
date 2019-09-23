
#include "Player.hpp"

#include <stdexcept>
#include <cassert>
#include <Config.hpp>

unsigned int Player::CreditsLeft() const
{
    return Credits;
}

bool Player::TryRemoveCredits(const unsigned int Value)
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

const std::vector<std::shared_ptr<Card>>& Player::GetCards() const
{
    return Cards;
}

Player::Player() : Credits(0)
{

    Player::ChangeCards();
    //Cards = std::vector<std::shared_ptr<Card>>(CARTON_NUMBER);


}

void Player::ChangeCards()
{

    Cards.clear();
    for (int i = 0; i < CARTON_NUMBER; i++)
        Cards.push_back(std::make_shared<Card>(CARTON_WIDTH, CARTON_HEIGHT, DRUM_SIZE));
    /*for (auto& card : Cards)
    {
        assert(card != nullptr);




        //auto newCard = new Card(CardInternal->Width, CardInternal->Height, CardInternal->MaxNumber);

        //delete CardInternal;

        //CardInternal = newCard;

        card->ReRoll();
    }*/

}
